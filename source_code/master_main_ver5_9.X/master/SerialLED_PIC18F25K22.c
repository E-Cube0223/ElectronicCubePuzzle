/*
 * File:   SerialLED.c
 * Author: junmo
 *
 * Created on 2019/10/21, 14:07
 */

#include<xc.h>
#include"SerialLED_PIC18F25K22.h"


void OUT_NONE(unsigned char LED_POWER) {
    OUT_CHECK(0);
    OUT_CHECK(0);
    OUT_CHECK(0);
}

void OUT_RED(unsigned char LED_POWER) {

    OUT_CHECK(LED_POWER);
    OUT_CHECK(0);
    OUT_CHECK(0);
}

void OUT_GREEN(unsigned char LED_POWER) {
    OUT_CHECK(0);
    OUT_CHECK(LED_POWER);
    OUT_CHECK(0);
}

void OUT_BLUE(unsigned char LED_POWER) {
    OUT_CHECK(0);
    OUT_CHECK(0);
    OUT_CHECK(LED_POWER);
}

void OUT_WHITE(unsigned char LED_POWER) {
    OUT_CHECK(LED_POWER>>1);
    OUT_CHECK(LED_POWER>>1);
    OUT_CHECK(LED_POWER>>1);

}

void OUT_YELLOW(unsigned char LED_POWER) {
    OUT_CHECK(LED_POWER>>1);
    OUT_CHECK(LED_POWER>>1);
    OUT_CHECK(0);
}

void OUT_ORANGE(unsigned char LED_POWER) {
    OUT_CHECK(LED_POWER);
    OUT_CHECK(LED_POWER>>1);
    OUT_CHECK(0);
}

void OUT_HIGH(void) {
    LEDOUT = 1;
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    LEDOUT = 0;
    asm("nop");
    asm("nop");
    //asm("nop");
    //asm("nop");
    //asm("nop");
    //asm("nop");
}

void OUT_LOW(void) {
    LEDOUT = 1;
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    LEDOUT = 0;
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    //asm("nop");
    //asm("nop");
    //asm("nop");
    //asm("nop");
}

void LED_RET(void) {
    LEDOUT = 0;
    for (int i = 0; i < 10000; i++)
        asm("nop");
}

void OUT_LED_ARRAY(unsigned char LED_COLOR_ARRAY_2D[LED_ARRAY_X][LED_ARRAY_Y], unsigned char LED_POWER) {
    unsigned char LED_COLOR_ARRAY[LED_ARRAY_SIZE];
    for(unsigned int j=0;j<LED_ARRAY_X;j++){
        for(unsigned int i=0;i<LED_ARRAY_Y;i++){
            LED_COLOR_ARRAY[j*LED_ARRAY_Y+i]=LED_COLOR_ARRAY_2D[j][i];
        }
    }
    for (unsigned int i = 0; i < LED_ARRAY_SIZE; i++) {
        (*LED_COLOR[LED_COLOR_ARRAY[i]])(LED_POWER);
    }
    LED_RET();
}

void OUT_CHECK(unsigned char LED_POWER) {
    for (int i = 0; i < 8; i++) {
        if ((LED_POWER & 0x80) == 0x80) {//最上位ビットがHIGHならば
            OUT_HIGH();//HIGHシグナル送信
        } else {//違えば
            OUT_LOW();//LOWシグナル送信
        }
        LED_POWER <<= 1;//1bit左シフト
    }
}
