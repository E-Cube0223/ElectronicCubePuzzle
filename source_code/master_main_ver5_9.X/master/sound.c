#include "sound.h"
char sound_flag = 1;

void do1(void)
{ //261
    if (sound_flag == 0)
        return;

    for (long i = 1; i < 15; i++)
    {
        LATBbits.LATB3 = 1;
        __delay_us(do1_us);
        LATBbits.LATB3 = 0;
        __delay_us(do1_us);
    }
}

//void out_sound(unsigned int sound_us, unsigned int sound_ms) {
//    if (sound_flag == 0)
//        return;
//    unsigned int for_i = (sound_ms * 1000) / sound_us;
//    for (long i = 1; i < for_i; i++) {
//        sound = 1;
//        __delay_us(sound_us);
//        sound = 0;
//        __delay_us(sound_us);
//    }
//}

void re1(void)
{
    if (sound_flag == 0)
        return;

    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(re1_us);
        sound = 0;
        __delay_us(re1_us);
    }
}

void mi1(void)
{
    if (sound_flag == 0)
        return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(mi1_us);
        sound = 0;
        __delay_us(mi1_us);
    }
}

void fa1(void)
{
    //	if (sound_flag == 0)
    //		return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(fa1_us);
        sound = 0;
        __delay_us(fa1_us);
    }
}

void so1(void)
{
    if (sound_flag == 0)
        return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(so1_us);
        sound = 0;
        __delay_us(so1_us);
    }
}

void ra1(void)
{
    if (sound_flag == 0)
        return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(ra1_us);
        sound = 0;
        __delay_us(ra1_us);
    }
}

void si1(void)
{
    if (sound_flag == 0)
        return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(si1_us);
        sound = 0;
        __delay_us(si1_us);
    }
}

void do2(void)
{
    if (sound_flag == 0)
        return;
    for (long i = 1; i < 30; i++)
    {
        sound = 1;
        __delay_us(do2_us);
        sound = 0;
        __delay_us(do2_us);
    }
}
