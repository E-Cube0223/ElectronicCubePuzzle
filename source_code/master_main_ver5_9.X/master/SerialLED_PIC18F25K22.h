//LED_COLOR define
#ifndef _SERIALLED_PIC_18F25K22_H_
#define _SERIALLED_PIC_18F25K22_H_


#define white 0
#define green 1
#define red 2
#define blue 3
#define orange 4
#define yellow 5
#define no_color 6

#define LEDOUT    PORTBbits.RB1

#define LED_ARRAY_X 6
#define LED_ARRAY_Y 9
#define LED_ARRAY_SIZE 54


void OUT_NONE(unsigned char); //OUTPUT NO COLOR
void OUT_RED(unsigned char); //OUTPUT RED pattern
void OUT_GREEN(unsigned char); //OUTPUT GREEN pattern
void OUT_BLUE(unsigned char); //OUTPUT BLUE pattern
void OUT_WHITE(unsigned char); //OUTPUT WHITE pattern
void OUT_YELLOW(unsigned char); //OUTPUT YELLOW pattern
void OUT_ORANGE(unsigned char); //OUTPUT YELLOW pattern
void OUT_LOW(void); //OUTPUT LOW SIGNAL
void OUT_HIGH(void); //OUTPUT HIGH SIGNAL
void LED_RET(void); //OUTPUT RESET SIGNAL
void OUT_LED_ARRAY(unsigned char [LED_ARRAY_X][LED_ARRAY_Y], unsigned char); //OUTPUT LED DATA
void OUT_CHECK(unsigned char); //HIGH LOW check

void (*LED_COLOR[])(unsigned char) = {OUT_WHITE, OUT_GREEN, OUT_RED, OUT_BLUE, OUT_ORANGE, OUT_YELLOW, OUT_NONE}; //OUTPUT COLOR pattern

extern unsigned char LED_ARRAY[LED_ARRAY_X][LED_ARRAY_Y]; //LEDカラーパターン配列
extern unsigned char POWER ; //LED輝度

#endif