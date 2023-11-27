#include "st7789.h"
#include "ascii_char.h"
u16 BACK_COLOR;

extern SPI_HandleTypeDef 	hspi2;
#define LCD_SPI				hspi2
extern uint8_t spi_transfer_complete;
/*
*
*
*/
void LCD_Writ_Bus(u8 *dat , u32 length)
{
	OLED_CS_Clr();
	//HAL_SPI_Transmit(&LCD_SPI, dat, length, 500);
	spi_transfer_complete = 0 ;
	HAL_SPI_Transmit_DMA(&LCD_SPI, dat, length);
	while(spi_transfer_complete == 0);
	OLED_CS_Set();
}
/*
*
*
*/
void LCD_WR_DATA8(u8 dat)
{
	OLED_DC_Set();//д����
	LCD_Writ_Bus(&dat , 1);
}
/******************************************************************************/
void LCD_WR_DATA8_multiple(u8 *dat, u32 num)
{
	OLED_DC_Set();//д����
	LCD_Writ_Bus(dat , num);
}

/*
*
*
*/
void LCD_WR_DATA(u16 dat)
{
	OLED_DC_Set();//д����
	u8 dat1[2] = {dat>>8 , dat};
	LCD_Writ_Bus(dat1 , 2);
}
/*
*
*
*/
void LCD_WR_REG(u8 dat)
{
	OLED_DC_Clr();//д����
	LCD_Writ_Bus(&dat , 1);
}
/*
*
*
*/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	if(USE_HORIZONTAL==0)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);
	}
	else if(USE_HORIZONTAL==1)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA(y1+80);
		LCD_WR_DATA(y2+80);
		LCD_WR_REG(0x2c);
	}
	else if(USE_HORIZONTAL==2)
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);
	}
	else
	{
		LCD_WR_REG(0x2a);
		LCD_WR_DATA(x1+80);
		LCD_WR_DATA(x2+80);
		LCD_WR_REG(0x2b);
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);
	}
}
/*
*
*
*/
void Lcd_Init(void)
{
	OLED_RST_Clr();
	HAL_Delay(20);
	OLED_RST_Set();
	HAL_Delay(20);

	//************* Start Initial Sequence **********//
	LCD_WR_REG(0x36);
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
	else LCD_WR_DATA8(0xA0);

	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);

	LCD_WR_REG(0xB2);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x33);
	LCD_WR_DATA8(0x33);

	LCD_WR_REG(0xB7);
	LCD_WR_DATA8(0x35);

	LCD_WR_REG(0xBB);
	LCD_WR_DATA8(0x19);

	LCD_WR_REG(0xC0);
	LCD_WR_DATA8(0x2C);

	LCD_WR_REG(0xC2);
	LCD_WR_DATA8(0x01);

	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x12);

	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x20);

	LCD_WR_REG(0xC6);
	LCD_WR_DATA8(0x0F);

	LCD_WR_REG(0xD0);
	LCD_WR_DATA8(0xA4);
	LCD_WR_DATA8(0xA1);

	LCD_WR_REG(0xE0);
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2B);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x4C);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x0B);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x23);

	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0xD0);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0C);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x2C);
	LCD_WR_DATA8(0x3F);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x51);
	LCD_WR_DATA8(0x2F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x1F);
	LCD_WR_DATA8(0x20);
	LCD_WR_DATA8(0x23);

	LCD_WR_REG(0x21);

	LCD_WR_REG(0x11);
	//Delay (120);

	LCD_WR_REG(0x29);
}
/*
*
*
*/
void LCD_Clear(u16 Color)
{
	u16 i,j;
	LCD_Address_Set(0,0,LCD_W-1,LCD_H-1);
    for(i=0;i<LCD_W;i++)
	 {
	  for (j=0;j<LCD_H;j++)
	   	{
        	LCD_WR_DATA(Color);
	    }

	  }
}
/*
*
*
*/
void LCD_DrawPoint(u16 x,u16 y,u16 color)
{
	LCD_Address_Set(x,y,x,y);
	LCD_WR_DATA(color);
}
/*
*
*
*/
void LCD_DrawPoint_big(u16 x,u16 y,u16 color)
{
	LCD_Fill(x-1,y-1,x+1,y+1,color);
}
/*
*
*
*/
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{
	u16 i,j;
	LCD_Address_Set(xsta,ysta,xend,yend);
	for(i=ysta;i<=yend;i++)
	{
		for(j=xsta;j<=xend;j++)LCD_WR_DATA(color);
	}
}
/*
*
*
*/
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color)
{
	u16 t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; 
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; 
	else if (delta_x==0)incx=0;
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;
	else {incy=-1;delta_y=-delta_x;}
	if(delta_x>delta_y)distance=delta_x; 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		LCD_DrawPoint(uRow,uCol,color);
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
/*
*
*
*/
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
/*
*
*
*/
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color)
{
	int a,b;
	int di;
	a=0;b=r;
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);  
		LCD_DrawPoint(x0+b,y0-a,color);  
		LCD_DrawPoint(x0-a,y0+b,color);  
		LCD_DrawPoint(x0-a,y0-b,color);  
		LCD_DrawPoint(x0+b,y0+a,color);  
		LCD_DrawPoint(x0+a,y0-b,color);  
		LCD_DrawPoint(x0+a,y0+b,color);  
		LCD_DrawPoint(x0-b,y0+a,color);  
		a++;
		if((a*a+b*b)>(r*r))
		{
			b--;
		}
	}
}
/*
*
*
*/
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color)
{
    u8 temp;
    u8 pos,t;
	  u16 x0=x;
    if(x>LCD_W-16||y>LCD_H-16)return;
	num=num-' ';
	LCD_Address_Set(x,y,x+8-1,y+16-1);
	if(!mode) 
	{
		for(pos=0;pos<16;pos++)
		{
			temp=asc2_1608[(u16)num*16+pos];	
			for(t=0;t<8;t++)
		    {
		        if(temp&0x01)LCD_WR_DATA(color);
				    else LCD_WR_DATA(BACK_COLOR);
				    temp>>=1;
				    x++;
		    }
			x=x0;
			y++;
		}
	}else
	{
		for(pos=0;pos<16;pos++)
		{
		    temp=asc2_1608[(u16)num*16+pos];		
			for(t=0;t<8;t++)
		    {
		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos,color);
		        temp>>=1;
		    }
		}
	}
}
/*
*
*
*/
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 color)
{
    while(*p!='\0')
    {
        if(x>LCD_W-16){x=0;y+=16;}
        if(y>LCD_H-16){y=x=0;LCD_Clear(RED);}
        LCD_ShowChar(x,y,*p,0,color);
        x+=8;
        p++;
    }
}
/*
*
*
*/
u32 mypow(u8 m,u8 n)
{
	u32 result=1;
	while(n--)result*=m;
	return result;
}
/*
*
*
*/
void LCD_ShowNum(u16 x,u16 y,u16 num,u8 len,u16 color)
{
	u8 t,temp;
	u8 enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+8*t,y,' ',0,color);
				continue;
			}else enshow=1;

		}
	 	LCD_ShowChar(x+8*t,y,temp+48,0,color);
	}
}
/*
*
*
*/
void LCD_ShowNum1(u16 x,u16 y,float num,u8 len,u16 color)
{
	u8 t,temp;
	u8 enshow=0;
	u16 num1;
	num1=num*100;
	for(t=0;t<len;t++)
	{
		temp=(num1/mypow(10,len-t-1))%10;
		if(t==(len-2))
		{
			LCD_ShowChar(x+8*(len-2),y,'.',0,color);
			t++;
			len+=1;
		}
	 	LCD_ShowChar(x+8*t,y,temp+48,0,color);
	}
}

