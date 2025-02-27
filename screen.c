#include "screen.h"
#include <stdint.h>
/**
 * @brief Desenha um bitmap no display OLED em uma posição específica
 * @param oled Ponteiro para a estrutura do display SSD1306
 * @param data Ponteiro para os dados do bitmap
 * @param x Coordenada X inicial
 * @param y Coordenada Y inicial
 * @param w Largura do bitmap em pixels
 * @param h Altura do bitmap em pixels
 */
void ssd1306_draw_bitmap(ssd1306_t *oled, const uint8_t *data, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
    for (uint8_t j = 0; j < h; j++) {
        for (uint8_t i = 0; i < w; i++) {
            // Verifica se a posição está dentro dos limites do buffer
            if (x + i < oled->width && y + j < oled->height) {
                oled->ram_buffer[(y + j) * oled->width + (x + i)] = data[j * w + i];
            }
        }
    }
}

/**
 * @brief Desenha as bordas de um retângulo no display OLED
 * @param oled Ponteiro para a estrutura do display SSD1306
 * @param x Coordenada X inicial
 * @param y Coordenada Y inicial
 * @param w Largura do retângulo
 * @param h Altura do retângulo
 */
void ssd1306_draw_rect(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
    if (x >= oled->width || y >= oled->height || w == 0 || h == 0) return;

    // Ajusta largura e altura para não exceder os limites do display
    uint8_t x_end = (x + w <= oled->width) ? x + w - 1 : oled->width - 1;
    uint8_t y_end = (y + h <= oled->height) ? y + h - 1 : oled->height - 1;

    // Desenha as bordas horizontais (topo e base)
    for (uint8_t i = x; i <= x_end; i++) {
        oled->ram_buffer[y * oled->width + i] |= 0x01;           // Topo
        oled->ram_buffer[y_end * oled->width + i] |= 0x80;       // Base
    }
    // Desenha as bordas verticais (esquerda e direita)
    for (uint8_t j = y; j <= y_end; j++) {
        oled->ram_buffer[j * oled->width + x] |= 0x01;           // Esquerda
        oled->ram_buffer[j * oled->width + x_end] |= 0x80;       // Direita
    }
}

/**
 * @brief Desenha uma barra de progresso no display OLED
 * @param oled Ponteiro para a estrutura do display SSD1306
 * @param x Coordenada X inicial
 * @param y Coordenada Y inicial
 * @param width Largura total da barra
 * @param height Altura da barra
 * @param progress Progresso (0.0 a 1.0)
 */
void draw_progress_bar(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t width, uint8_t height, float progress) {
    // Limita o progresso entre 0.0 e 1.0
    progress = (progress > 1.0f) ? 1.0f : (progress < 0.0f) ? 0.0f : progress;
    uint8_t fill_width = (uint8_t)(progress * (width - 2)); // Espaço interno da barra

    // Desenha a moldura da barra
    ssd1306_draw_rect(oled, x, y, width, height);

    // Preenche a barra de progresso
    for (uint8_t j = y + 1; j < y + height - 1; j++) {
        for (uint8_t i = x + 1; i < x + 1 + fill_width && i < x + width - 1; i++) {
            oled->ram_buffer[j * oled->width + i] = 0xFF; // Preenche com pixels acesos
        }
    }
}

void ssd1306_fill_rect(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
          if (oled == NULL || x >= oled->width || y >= oled->height || x + w > oled->width || y + h > oled->height) return;
          for (uint8_t i = x; i < x + w; i++) {
              for (uint8_t j = y; j < y + h; j++) {
                  oled->ram_buffer[j * oled->width + i] = 0xFF;
              }
          }
      }

      