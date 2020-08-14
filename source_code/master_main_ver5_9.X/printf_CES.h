

#ifndef _PRINTF_CES_H_
#define _PEINTF_CES_H_
#include <stdio.h>
#include "operation_CES.h"

void print_self(const CE *);

void preint_SET_LED(void);

void command_turn_CE_2(char s[]);
extern const int color_NUM[];
extern int number_of_moves ; //‘€ì‰ñ”ƒJƒEƒ“ƒg

extern int print_mode_flag ;
extern int reset_mode_flag ;

void preint_SET_LED_2(void);

void test_mode(void);

void preint_SET_LED_COL_NUM(void);
void preint_SET_LED_NUM(void);

#endif
