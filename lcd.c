#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "lcd_config.h"
#include "lcd.h"

#define WRITE_BIT_3(REG,BIT,VAL) REG&=(~(1<<BIT));REG|=(VAL<<BIT)
#define WRITE_BIT_2(BIT,VAL) WRITE_BIT_3(BIT,VAL)

static void LCD_voidSendData(uint8_t data);
static void LCD_voidSendCmd(uint8_t cmd);
static void LCD_voidEnable();


static void LCD_voidSendData(uint8_t data)
{
	WRITE_BIT_2(RS,1);
	WRITE_BIT_2(RW,0);
	
	DPORT=data;
	LCD_voidEnable();
	#if DL==DL_4
	DPORT=data<<4;
	LCD_voidEnable();
	#endif
	_delay_ms(10);
}

static void LCD_voidSendCmd(uint8_t cmd)
{
	WRITE_BIT_2(RS,0);
	WRITE_BIT_2(RW,0);

	DPORT=cmd;
	LCD_voidEnable();
	#if DL==DL_4
	DPORT=cmd<<4;
	LCD_voidEnable();
	#endif
	_delay_ms(10);
}

static void LCD_voidEnable()
{
	WRITE_BIT_2(EN,1);
	WRITE_BIT_2(EN,0);
}

void LCD_voidInit()
{
	WRITE_BIT_3(DDRD,PORTD0,1);
	WRITE_BIT_3(DDRD,PORTD1,1);
	WRITE_BIT_3(DDRD,PORTD2,1);
	DDRB=0xFF;
	
	#if DL==DL_4
	WRITE_BIT_2(RS,0);
	WRITE_BIT_2(RW,0);
	DPORT=0x30;
	LCD_voidEnable();
	_delay_ms(1);
	LCD_voidEnable();
	_delay_ms(1);
	LCD_voidEnable();
	_delay_ms(1);
	DPORT=0x20;
	LCD_voidEnable();
	#endif
		
	//function set
	uint8_t dl=DL, n=N_LINES, f=FONT;
	uint8_t cmd=32 | (dl << 4) | (n << 3) | (f << 2);
	LCD_voidSendCmd(cmd);
	//display on-off
	
	LCD_voidSendCmd(12);	
}

void LCD_voidClrDisp()
{
	LCD_voidSendCmd(1);
}

void LCD_voidWriteChar(uint8_t ch)
{
	LCD_voidSendData(ch);
}

void LCD_voidWriteStr(uint8_t *str)
{
	while (*str)
		LCD_voidSendData(*(str++));
}
void LCD_voidRetHome()
{
	LCD_voidSendCmd(2);
}
void LCD_voidSetPos(uint8_t line, uint8_t col)
{
	LCD_voidSendCmd(0x80|((line&1)*0x40+(line>>1)*0x14+col));
}