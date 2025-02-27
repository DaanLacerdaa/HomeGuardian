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

 void ssd1306_draw_bitmap(ssd1306_t *ssd, const uint8_t *bitmap, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
          // Verificar se as coordenadas estão dentro dos limites do display
          if (x >= ssd->width || y >= ssd->height) {
              return; // Fora dos limites, não desenha
          }
      
          // Ajustar largura e altura para não exceder o display
          uint8_t draw_w = (x + w > ssd->width) ? ssd->width - x : w;
          uint8_t draw_h = (y + h > ssd->height) ? ssd->height - y : h;
      
          // Calcular bytes por linha no bitmap (1 bit por pixel, 8 pixels por byte)
          uint8_t bytes_per_row = (w + 7) / 8;
      
          // Iterar sobre as linhas e colunas do bitmap
          for (uint8_t j = 0; j < draw_h; j++) {
              for (uint8_t i = 0; i < draw_w; i++) {
                  // Índice no bitmap
                  uint16_t bitmap_index = (j * bytes_per_row) + (i / 8);
                  uint8_t bit_offset = i % 8;
                  uint8_t bitmap_byte = bitmap[bitmap_index];
      
                  // Índice no buffer do display
                  uint16_t buffer_index = (y + j) * ssd->width + (x + i);
      
                  // Verificar o bit no bitmap e atualizar o buffer
                  if (bitmap_byte & (1 << bit_offset)) {
                      ssd->ram_buffer[buffer_index] = 0xFF; // Pixel aceso
                  } else {
                      ssd->ram_buffer[buffer_index] = 0x00; // Pixel apagado
                  }
              }
          }
      
          // Enviar os dados atualizados para o display
          ssd1306_send_data(ssd);
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



void ssd1306_fill_rect(ssd1306_t *oled, uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
          if (oled == NULL || x >= oled->width || y >= oled->height || x + w > oled->width || y + h > oled->height) return;
          for (uint8_t i = x; i < x + w; i++) {
              for (uint8_t j = y; j < y + h; j++) {
                  oled->ram_buffer[j * oled->width + i] = 0xFF;
              }
          }
      }

      