#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "math.h"
#include "ssd1306.h"
#include "font.h"
#include "screen.h"

// Definições da BitDogLab
#define LED_RED         13
#define LED_GREEN       11
#define LED_BLUE        12
#define JOYSTICK_X      26
#define JOYSTICK_Y      27
#define JOYSTICK_BTN    22
#define BUTTON_A        5
#define BUTTON_B        6
#define BUZZER          21
#define MIC_PIN         26      // ADC0
#define TEMP_SENSOR     4       // ADC4

// Configurações
#define TEMP_THRESHOLD  40.0    // Limiar de temperatura
#define SOUND_THRESHOLD 500     // Limiar de som
#define UPDATE_INTERVAL 1000    // Atualizações a cada 1s
#define DEBOUNCE_DELAY  50      // Delay para debounce

// Estados do sistema
typedef enum {
    MODE_NORMAL,
    MODE_ALERT,
    MODE_CONFIG
} SystemState;

// Estrutura do display
ssd1306_t oled;
volatile SystemState system_state = MODE_NORMAL;
volatile bool alert_acknowledged = false;
float current_temp = 0.0;
uint16_t sound_level = 0;

// Protótipos
void init_hardware();
void read_sensors();
void update_display();
void handle_input();
void trigger_alert();
void clear_alert();
float read_internal_temp();
void buzzer_alert(bool state);
void led_control(uint8_t r, uint8_t g, uint8_t b);

// Interrupção do botão A
void button_callback(uint gpio, uint32_t events) {
    if(gpio == BUTTON_A && system_state == MODE_ALERT) {
        clear_alert();
    }
}

int main() {
    stdio_init_all();
    init_hardware();
    
    absolute_time_t last_update = get_absolute_time();
    
    while(true) {
        absolute_time_t now = get_absolute_time();
        
        if(absolute_time_diff_us(last_update, now) >= UPDATE_INTERVAL * 1000) {
            read_sensors();
            update_display();
            last_update = now;
        }
        
        handle_input();
        
        if(system_state == MODE_ALERT && !alert_acknowledged) {
            trigger_alert();
        }
        
        sleep_ms(10);
    }
}

void init_hardware() {
    // ADC
    adc_init();
    adc_gpio_init(MIC_PIN);
    adc_set_temp_sensor_enabled(true);

    // Display OLED
    i2c_init(i2c1, 400000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    ssd1306_init(&oled, 128, 64, false, 0x3C, i2c1);

    // LEDs
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Buzzer
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(BUZZER);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 16.0f);
    pwm_init(slice, &config, true);

    // Botões
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, button_callback);
}

void read_sensors() {
    // Temperatura
    adc_select_input(TEMP_SENSOR);
    float adc_temp = adc_read() * 3.3f / 4096.0f;
    current_temp = 27.0f - (adc_temp - 0.706f) / 0.001721f;

    // Som
    adc_select_input(0);
    uint32_t sum = 0;
    for(int i=0; i<100; i++) {
        uint16_t sample = adc_read();
        sum += sample * sample;
        sleep_us(1000);
    }
    sound_level = sqrt(sum/100);
}

void update_display() {
    ssd1306_fill(&oled, false); // Limpa o display
    
    if(system_state == MODE_ALERT) {
        ssd1306_draw_bitmap(&oled, exec_buzzer);
    }
    else if(system_state == MODE_CONFIG) {
        ssd1306_draw_bitmap(&oled, led_select);
    }
    else {
        char temp_str[20];
        sprintf(temp_str, "Temp: %.1fC", current_temp);
        ssd1306_draw_string(&oled, temp_str, 10, 10);
        
        char sound_str[20];
        sprintf(sound_str, "Som: %d dB", sound_level);
        ssd1306_draw_string(&oled, sound_str, 10, 25);
        
        ssd1306_send_data(&oled); // Envia apenas no modo normal
    }
}

void handle_input() {
    // Leitura do joystick Y para modo config
    adc_select_input(1);
    uint16_t y_pos = adc_read();
    
    if(y_pos < 1000 && system_state != MODE_ALERT) {
        system_state = MODE_CONFIG;
    } else if(y_pos > 3000) {
        system_state = MODE_NORMAL;
    }
}

void trigger_alert() {
    // Buzzer com PWM
    static bool buzzer_state = false;
    buzzer_state = !buzzer_state;
    pwm_set_gpio_level(BUZZER, buzzer_state ? 512 : 0);
    
    // LEDs vermelho piscante
    led_control(1, 0, 0);
    sleep_ms(100);
    led_control(0, 0, 0);
}

void clear_alert() {
    pwm_set_gpio_level(BUZZER, 0);
    led_control(0, 0, 0);
    alert_acknowledged = true;
    system_state = MODE_NORMAL;
}

void led_control(uint8_t r, uint8_t g, uint8_t b) {
    gpio_put(LED_RED, r);
    gpio_put(LED_GREEN, g);
    gpio_put(LED_BLUE, b);
}