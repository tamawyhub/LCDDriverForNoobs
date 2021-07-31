#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
    /* Replace with your application code */
	LCD_voidInit();
	
    while (1) 
    {
		LCD_voidClrDisp();
		LCD_voidWriteStr("Hello");
		LCD_voidSetPos(1,0);
		LCD_voidWriteStr("World");
		_delay_ms(1000);
		LCD_voidClrDisp();
		LCD_voidWriteStr("Life");
		LCD_voidSetPos(1,0);
		LCD_voidWriteStr("Sucks");
		_delay_ms(1000);
    }
}

