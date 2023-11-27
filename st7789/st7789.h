#ifndef __ST7789__
#define __ST7789__
#include "stdint.h"
#include "stdlib.h"
#include "main.h"

#define USE_HORIZONTAL 0  

#if USE_HORIZONTAL==0 || USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 240

#else
#define LCD_W 240
#define LCD_H 240
#endif

#define	u8		uint8_t
#define	u16		uint16_t
#define	u32		uint32_t
//-----------------

#define OLED_RST_Clr() HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_RESET)//RES
#define OLED_RST_Set() HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,GPIO_PIN_SET)

//#define OLED_DC_Clr() HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_RESET)//DC
//#define OLED_DC_Set() HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,GPIO_PIN_SET)
//
//#define OLED_CS_Clr()  HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_RESET)//CS
//#define OLED_CS_Set()  HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,GPIO_PIN_SET)

#define OLED_DC_Clr() LCD_DC_GPIO_Port->BSRR = LCD_DC_Pin << 16
#define OLED_DC_Set() LCD_DC_GPIO_Port->BSRR = LCD_DC_Pin

#define OLED_CS_Clr() LCD_CS_GPIO_Port->BSRR = LCD_CS_Pin << 16
#define OLED_CS_Set() LCD_CS_GPIO_Port->BSRR = LCD_CS_Pin


#define OLED_CMD  0	
#define OLED_DATA 1	

extern  u16 BACK_COLOR;  

void LCD_Writ_Bus(u8 *dat , u32 length);
void LCD_WR_DATA8(u8 dat);
void LCD_WR_DATA8_multiple(u8 *dat, u32 num);
void LCD_WR_DATA(u16 dat);
void LCD_WR_REG(u8 dat);
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);
void Lcd_Init(void);
void LCD_Clear(u16 Color);
void LCD_DrawPoint(u16 x,u16 y,u16 color);
void LCD_DrawPoint_big(u16 x,u16 y,u16 colory);
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color);
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 color);
u32 mypow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u16 num,u8 len,u16 color);
void LCD_ShowNum1(u16 x,u16 y,float num,u8 len,u16 color);
void LCD_ShowPicture(u16 x1,u16 y1,u16 x2,u16 y2);



#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE           	 0x001F
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 
#define BRRED 			     0XFC07 
#define GRAY  			     0X8430 


#define DARKBLUE      	 0X01CF	
#define LIGHTBLUE      	 0X7D7C	
#define GRAYBLUE       	 0X5458 


#define LIGHTGREEN     		 0X841F 
#define LGRAY 			     0XC618 

#define LGRAYBLUE        0XA651 
#define LBBLUE           0X2B12 



#endif





