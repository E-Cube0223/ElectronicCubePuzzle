#ifndef SOUND_H
#define	SOUND_H

#include <htc.h>
#include <xc.h> // include processor files - each processor file is guarded.  
#include "XTAL.h"
#define sound LATBbits.LATB3
#define do1_us 21//500//1908
#define re1_us 80//1700
#define mi1_us 22
#define fa1_us 500
#define so1_us 300
#define ra1_us 200
#define si1_us 100
#define do2_us 956
//500
#define SOUND_NUM 7

extern char sound_flag;
void do1(void);
void re1(void);
void mi1(void);
void fa1(void);
void so1(void);
void ra1(void);
void si1(void);
void do2(void);
//void out_sound(unsigned int sound_us,unsigned int sound_ms);
void (*SOUND_NOTE[])(void) = {do1, re1, mi1, /* fa1,*/ so1, ra1, si1, do2}; //OUTPUT SOUND pattern



#endif	/* XC_HEADER_TEMPLATE_H */

