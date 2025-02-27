/**
 * @file HomeGuardian.c
 * @brief Sistema de monitoramento ambiental com alertas e interface gráfica
 * @details 
 * - Monitora temperatura e nível de som
 * - Interface OLED com gráficos dinâmicos
 * - Matriz de LEDs WS2812- para feedback visual
 * - Controle por joystick e botões
 */

 #include <stdio.h>
 #include "pico/stdlib.h"
 #include "hardware/adc.h"
 #include "hardware/pwm.h"
 #include "hardware/i2c.h"
 #include "hardware/pio.h"
 #include "math.h"
 #include "ssd1306.h"
 #include "font.h"
 #include "screen.h"
 #include "ws2812.pio.h"
 
 // Configurações da BitDogLab
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
 #define LED_MATRIX_PIN  7       // GPIO para matriz de LEDs
 #define NUM_LEDS        25      // 5x5 matrix
 
 // Configurações do sistema

 #define UPDATE_INTERVAL 1000    // Atualizações a cada 1s
 #define DEBOUNCE_DELAY  50      // Delay para debounce
 #define JOYSTICK_DEADZONE 200   // Zona morta do joystick

 // Limites para os limiares
#define TEMP_MIN 10.0f
#define TEMP_MAX 50.0f
#define SOUND_MIN 100
#define SOUND_MAX 1000
 
 // Estados do sistema
 typedef enum {
     MODE_NORMAL,
     MODE_ALERT,
     MODE_CONFIG
 } SystemState;
 
 // Estruturas globais
 ssd1306_t oled;
 PIO led_pio = pio0;
 uint led_sm;
 uint32_t led_colors[NUM_LEDS];
 
 volatile SystemState system_state = MODE_NORMAL;
 volatile bool alert_acknowledged = false;
 float current_temp = 0.0;
 uint16_t sound_level = 0;
 uint8_t config_selection = 0;
 float temp_threshold = 40.0f;   // Valor inicial definido diretamente
 uint16_t sound_threshold = 500; // Valor inicial definido diretamente
 
 // Protótipos de funções
 void init_hardware();
 void read_sensors();
 void update_display();
 void handle_input();
 void trigger_alert();
 void clear_alert();
 void led_control(uint8_t r, uint8_t g, uint8_t b);
 void update_led_matrix();
 void set_led_color_hsv(uint8_t led, float h, float s, float v);
 void draw_progress_bar(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t width, uint8_t height, float progress);
 
 // Interrupção dos botões
void button_callback(uint gpio, uint32_t events) {
    if (gpio == BUTTON_A && system_state == MODE_ALERT) {
        clear_alert();
    } else if (gpio == BUTTON_B && system_state == MODE_CONFIG) {
        system_state = MODE_NORMAL; // Sair do modo de configuração
    }
}
 
int main() {
    stdio_init_all();
    init_hardware();
    
    absolute_time_t last_update = get_absolute_time();
    absolute_time_t last_led_update = get_absolute_time();
    
    while(true) {
        absolute_time_t now = get_absolute_time();
        
        // Atualização periódica de sensores e display
        if(absolute_time_diff_us(last_update, now) >= UPDATE_INTERVAL * 1000) {
            read_sensors();
            update_display();
            last_update = now;
        }
        
        // Atualização da matriz de LEDs (60 FPS)
        if(absolute_time_diff_us(last_led_update, now) >= 16666) {
            update_led_matrix();
            last_led_update = now;
        }
        
        handle_input();
        
        // Controle dos LEDs RGB com base no estado do sistema
        switch(system_state) {
            case MODE_ALERT:
                led_control(1, 0, 0); // Vermelho para alerta
                break;
            case MODE_CONFIG:
                led_control(0, 0, 1); // Azul para configuração
                break;
            default: // MODE_NORMAL
                led_control(0, 1, 0); // Verde para normal
                break;
        }
        
        if(system_state == MODE_ALERT && !alert_acknowledged) {
            trigger_alert();
        }
        
        sleep_ms(10);
    }
}
 
 /**
  * @brief Inicializa todos os componentes de hardware
  */
 void init_hardware() {
     // Configuração ADC
     adc_init();
     adc_gpio_init(MIC_PIN);
     adc_set_temp_sensor_enabled(true);
 
     // Display OLED
     i2c_init(i2c1, 400000);
     gpio_set_function(14, GPIO_FUNC_I2C);
     gpio_set_function(15, GPIO_FUNC_I2C);
     ssd1306_init(&oled, 128, 64, false, 0x3C, i2c1);
 
     // LEDs RGB
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
 
     // Matriz de LEDs
     uint offset = pio_add_program(led_pio, &ws2812_program);
     ws2812_program_init(led_pio, led_sm, offset, LED_MATRIX_PIN, 800000, false);
 
     // Botões
     gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, button_callback);
 }
 
 /**
  * @brief Lê e processa dados dos sensores
  */
 void read_sensors() {
    // Leitura da temperatura
    adc_select_input(TEMP_SENSOR);
    float adc_temp = adc_read() * 3.3f / 4096.0f;
    current_temp = 27.0f - (adc_temp - 0.706f) / 0.001721f;

    // Leitura do nível de som (RMS otimizado)
    adc_select_input(0);
    uint32_t sum = 0;
    for (int i = 0; i < 100; i++) {
        int16_t sample = adc_read() - 2048; // Remove DC offset
        sum += (int32_t)sample * sample;    // Quadrado direto
        sleep_us(100);
    }
    sound_level = (uint16_t)sqrt(sum / 100);

    // Verificação de limiares ajustáveis
    if (current_temp > temp_threshold || sound_level > sound_threshold) {
        system_state = MODE_ALERT;
        alert_acknowledged = false;
    }
}
 
 /**
  * @brief Atualiza a interface do display OLED
  */
 
void update_display() {
    ssd1306_fill(&oled, false);
    
    switch(system_state) {
        case MODE_ALERT:
            ssd1306_draw_bitmap(&oled, warning_icon, 40, 10);
            ssd1306_draw_string(&oled, "ALERTA!", 35, 40);
            break;
            
        case MODE_CONFIG:
            ssd1306_draw_string(&oled, "Modo Configuracao", 10, 10);
            char temp_str[20], sound_str[20];
            sprintf(temp_str, "> Temp Limite: %.1fC", temp_threshold);
            sprintf(sound_str, "> Som Limite: %d", sound_threshold);
            ssd1306_draw_string(&oled, config_selection == 0 ? temp_str : "  Temp Limite", 10, 25);
            ssd1306_draw_string(&oled, config_selection == 1 ? sound_str : "  Som Limite", 10, 40);
            break;
            
        default:
            draw_progress_bar(&oled, 10, 10, 100, 8, current_temp/temp_threshold);
            ssd1306_draw_string(&oled, "Temp:", 10, 20);
            draw_progress_bar(&oled, 10, 35, 100, 8, (float)sound_level/sound_threshold);
            ssd1306_draw_string(&oled, "Som:", 10, 45);
            char temp_str[20], sound_str[20];
            sprintf(temp_str, "%.1fC", current_temp);
            sprintf(sound_str, "%d dB", sound_level);
            ssd1306_draw_string(&oled, temp_str, 80, 20);
            ssd1306_draw_string(&oled, sound_str, 80, 45);
    }
    
    ssd1306_send_data(&oled);
}

/**
 * @brief Controla os LEDs RGB
 * @param r Estado do LED vermelho (0: apagado, 1: aceso)
 * @param g Estado do LED verde (0: apagado, 1: aceso)
 * @param b Estado do LED azul (0: apagado, 1: aceso)
 */
void led_control(uint8_t r, uint8_t g, uint8_t b) {
    gpio_put(LED_RED, r);
    gpio_put(LED_GREEN, g);
    gpio_put(LED_BLUE, b);
}

 
 /**
  * @brief Processa entradas do joystick e botões
  */
 void handle_input() {
    adc_select_input(1); // Eixo Y
    uint16_t y_pos = adc_read();
    adc_select_input(0); // Eixo X
    uint16_t x_pos = adc_read();

    if (system_state == MODE_CONFIG) {
        // Navegação no menu
        if (y_pos < 2048 - JOYSTICK_DEADZONE) {
            config_selection = (config_selection + 1) % 2;
            sleep_ms(DEBOUNCE_DELAY);
        } else if (y_pos > 2048 + JOYSTICK_DEADZONE) {
            config_selection = (config_selection - 1) % 2;
            sleep_ms(DEBOUNCE_DELAY);
        }
        // Ajuste de limiares com limites
        else if (x_pos < 2048 - JOYSTICK_DEADZONE) {
            if (config_selection == 0) {
                temp_threshold -= 0.5f;
                if (temp_threshold < TEMP_MIN) temp_threshold = TEMP_MIN;
            } else {
                sound_threshold -= 10;
                if (sound_threshold < SOUND_MIN) sound_threshold = SOUND_MIN;
            }
            sleep_ms(DEBOUNCE_DELAY);
        } else if (x_pos > 2048 + JOYSTICK_DEADZONE) {
            if (config_selection == 0) {
                temp_threshold += 0.5f;
                if (temp_threshold > TEMP_MAX) temp_threshold = TEMP_MAX;
            } else {
                sound_threshold += 10;
                if (sound_threshold > SOUND_MAX) sound_threshold = SOUND_MAX;
            }
            sleep_ms(DEBOUNCE_DELAY);
        }
    } else {
        if (y_pos < 1000) {
            system_state = MODE_CONFIG;
        } else if (x_pos > 3000 && system_state == MODE_ALERT) {
            clear_alert();
        }
    }
}
 

 /**
  * @brief Ativa alertas visuais e sonoros
  */
 void trigger_alert() {
    static bool buzzer_state = false;
    buzzer_state = !buzzer_state;
    pwm_set_gpio_level(BUZZER, buzzer_state ? 512 : 0);
    led_control(1, 0, 0); // Acender LED vermelho durante o alerta
    sleep_ms(100);
}
 
 /**
  * @brief Desativa alertas e retorna ao modo normal
  */
 void clear_alert() {
    pwm_set_gpio_level(BUZZER, 0);
    led_control(0, 0, 0); // Apagar LEDs RGB
    alert_acknowledged = true;
    system_state = MODE_NORMAL;
}
 
 /**
  * @brief Atualiza a matriz de LEDs WS2812
  */
 void update_led_matrix() {
    static uint8_t hue = 0;

    switch (system_state) {
        case MODE_ALERT:
            // Padrão vermelho piscante
            for (int i = 0; i < NUM_LEDS; i++) {
                set_led_color_hsv(i, 0, 1.0, (to_ms_since_boot(get_absolute_time()) % 500 < 250) ? 1.0 : 0.0);
            }
            break;

        case MODE_CONFIG:
            // Padrão verde estático
            for (int i = 0; i < NUM_LEDS; i++) {
                set_led_color_hsv(i, 120, 1.0, 0.2);
            }
            break;

        default:
            // Animação de onda azul
            for (int i = 0; i < NUM_LEDS; i++) {
                float offset = (float)i / NUM_LEDS;
                set_led_color_hsv(i, 240, 1.0, fabs(sin((hue / 255.0 + offset) * M_PI)));
            }
            hue += 2;
    }

    // Envia dados para os LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
        pio_sm_put_blocking(led_pio, led_sm, led_colors[i]);
    }
}
 
 /**
  * @brief Define a cor de um LED usando HSV
  * @param led Índice do LED
  * @param h Matiz (0-360)
  * @param s Saturação (0.0-1.0)
  * @param v Valor (0.0-1.0)
  */
 void set_led_color_hsv(uint8_t led, float h, float s, float v) {
     float r, g, b;
     h = fmod(h, 360);
     
     int i = (int)(h / 60.0);
     float f = h / 60.0 - i;
     float p = v * (1 - s);
     float q = v * (1 - f*s);
     float t = v * (1 - (1 - f)*s);
     
     switch(i) {
         case 0: r=v; g=t; b=p; break;
         case 1: r=q; g=v; b=p; break;
         case 2: r=p; g=v; b=t; break;
         case 3: r=p; g=q; b=v; break;
         case 4: r=t; g=p; b=v; break;
         default: r=v; g=p; b=q;
     }
     
     led_colors[led] = ((uint8_t)(g*255) << 24) | ((uint8_t)(r*255) << 16) | ((uint8_t)(b*255) << 8);
 }
 
 /**
  * @brief Desenha uma barra de progresso no display
  */
 void draw_progress_bar(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t width, uint8_t height, float progress) {
     progress = progress > 1.0 ? 1.0 : progress;
     uint8_t fill = (uint8_t)(progress * (width-2));
     
     // Moldura
     ssd1306_draw_rect(oled, x, y, width, height);
     
     // Preenchimento
     ssd1306_fill_rect(oled, x+1, y+1, fill, height-2);
 }