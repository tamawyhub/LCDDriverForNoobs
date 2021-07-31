#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "lcd.h"

#define RS PORTD,PORTD2
#define RW PORTD,PORTD1
#define EN PORTD,PORTD0
#define DPORT PORTB

#define DL DL_8
#define N_LINES TWO_LINE
#define FONT FONT_BIG

#endif /* LCD_CONFIG_H_ */