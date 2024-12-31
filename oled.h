
#ifndef _SSD1306_H_
#define _SSD1306_H_

#include "stm32f4xx_hal.h"
#include "font.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
/* I2C address */
#ifndef SSD1306_I2C_ADDR
#define SSD1306_I2C_ADDR         0x78
#endif

/* SSD1306 width in pixels */
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH            128
#endif

/* SSD1306 LCD height in pixels */
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT           64
#endif

/**
 * @brief  SSD1306 color enumeration
 */
typedef enum {
	SSD1306_COLOR_BLACK = 0x00, /*!< Black color, no pixel */
	SSD1306_COLOR_WHITE = 0x01  /*!< Pixel is set. Color depends on LCD */
} SSD1306_COLOR_t;


/*************Function declaration ***************************/
uint8_t SSD1306_Init(void);

void setPixel(int x, int y, bool color);

void drawLine(int x0, int y0, int x1, int y1, bool color);
void drawRectangle(int x0, int y0, int x1, int y1, bool color);
void drawCircle(int xc, int yc, int radius, bool color);

void SSD1306_UpdateScreen(void);

void SSD1306_Fill(SSD1306_COLOR_t Color);

void SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);

void SSD1306_GotoXY(uint16_t x, uint16_t y);

char SSD1306_Putc(char ch, FontDef_t* Font, SSD1306_COLOR_t color);

char SSD1306_Puts(char* str, FontDef_t* Font, SSD1306_COLOR_t color);

// inverts the display i = 1->inverted, i = 0->normal
void SSD1306_InvertDisplay (int i);

// clear the display
void SSD1306_Clear (void);

/*************SCROLLING Function declaration ***************************/
// scroll the screen for fixed rows
void SSD1306_ScrollRight(uint8_t start_row, uint8_t end_row);
void SSD1306_ScrollLeft(uint8_t start_row, uint8_t end_row);
void SSD1306_Scrolldiagright(uint8_t start_row, uint8_t end_row);
void SSD1306_Scrolldiagleft(uint8_t start_row, uint8_t end_row);
void SSD1306_Stopscroll(void);



/*************I2C Function declaration ***************************/
#ifndef ssd1306_I2C_TIMEOUT
#define ssd1306_I2C_TIMEOUT					20000
#endif

void ssd1306_I2C_Init();

void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data);

void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count);


#endif
