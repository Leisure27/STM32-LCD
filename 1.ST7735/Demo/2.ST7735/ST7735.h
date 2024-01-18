#ifndef __ST7735_H
#define __ST7735_H

#include "main.h"
#include "spi.h"
#include "Font.h"
#include "stdio.h"

#define ST7735_SPI_INSTANCE hspi2

#define ST7735_RST_GPIO_Port LCD_RES_GPIO_Port
#define ST7735_RST_Pin LCD_RES_Pin

#define ST7735_DC_GPIO_Port LCD_DC_GPIO_Port
#define ST7735_DC_Pin LCD_DC_Pin

#define ST7735_CS_GPIO_Port LCD_CS_GPIO_Port
#define ST7735_CS_Pin LCD_CS_Pin

#define ST7735_XSTART 0
#define ST7735_YSTART 24
#define ST7735_WIDTH 160
#define ST7735_HEIGHT 80

#define ST7735_ROTATION 3

// Color definitions
#define ST7735_BLACK 0x0000
#define ST7735_BLUE 0xF800
#define ST7735_RED 0x001F
#define ST7735_GREEN 0x07E0
#define ST7735_CYAN 0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW 0xFFE0
#define ST7735_WHITE 0xFFFF
#define ST7735_COLOR565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

void ST7735_Init(void);
void ST7735_SetRotation(uint8_t rotation);
void ST7735_DrawRectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color);
void ST7735_FillScreen(uint16_t color);
void ST7735_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_WriteString(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_DrawImage(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *image);

#endif
