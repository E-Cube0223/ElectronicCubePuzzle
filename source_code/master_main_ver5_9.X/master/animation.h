/*
アニメーション＋複数回同じ動作の描写を行わない回転アニメーション

*/
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include "SerialLED_PIC18F25K22.h"
#include "CES_SPI_support.h"
#include "XTAL.h"
#include "operation_CES.h"
#include "solution_CES.h"
#define SHUFFLE_MAX 20

//アニメーション
char animation_1(const char);
char animation_2(void);
char animation_3(char, char);
char animation_4(unsigned int);

void set_all_LED_ARRAY(char);//単色発光

void shuffle_state_CE(const unsigned int seed_number); //SHUFFLE_MAX回だけランダムに回転を行う

void convert_ROTtoLED(void); //石橋発光用変数から正元発光用変数に移動

//回転アニメーション
void command_turn_ARRAY_2(const char *s);
void command_turn_ARRAY_2_2(const char *s);
void command_turn_ARRAY_2_3(const char *s1, const char *s2, const char *s3);

//複数回同じ動作の描写を行わない回転アニメーション
char past_command_3 = 0;
char past_command_count_3 = 0;
void command_turn_ARRAY_3(const char *s);
void command_turn_ARRAY_3_end(void);

extern char mode_cube_end;//早送りを行うかどうか

extern char ARRAY_skip_CS;//特殊入力を限定的に受け付ける面の記録

#endif
