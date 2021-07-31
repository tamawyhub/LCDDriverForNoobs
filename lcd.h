#ifndef LCD_H_
#define LCD_H_


#define DL_4 0
#define DL_8 1
#define ONE_LINE 0
#define TWO_LINE 1
#define FONT_SMALL 0
#define FONT_BIG 1

//LCD_voidInit
//Initiate LCD as per configuration in lcd_config.h
//return: 
void LCD_voidInit();

//LCD_voidClrDisp
//Clear LCD display
//return:
void LCD_voidClrDisp();

//LCD_voidWriteChar
//Write a single character to the display
//ch: the character to be written
//return:
void LCD_voidWriteChar(uint8_t ch);

//LCD_voidWriteStr
//Write a null terminated string to the display
//str: pointer to the first character in the string to be written
//return:
void LCD_voidWriteStr(uint8_t *str);

//LCD_voidRetHome
//Place the cursor at the beginning of the display
//return:
void LCD_voidRetHome();

//LCD_voidSetPos
//Place the cursor at desired position
//line: the desired line, either 0 or 1
//col:  the desired position in the line, 0 to 15
//return:
void LCD_voidSetPos(uint8_t line, uint8_t col);

#endif /* LCD_H_ */