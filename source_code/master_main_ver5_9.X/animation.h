#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "XTAL.h"
#include "operation_CES.h"
#include "solution_CES.h"
#define SHUFFLE_MAX 20
char animation_1(const char);
char animation_2(void);
char animation_3(char, char);
char animation_4(unsigned int);
void set_all_LED_ARRAY(char);
//void convert_ROTtoLED(void); //LED_ARRAY‚ÖLED_Light‚ð•ÏŠ·
void shuffle_state_CE(const unsigned int seed_number);

void command_turn_ARRAY_2(const char *s);

//extern char column[3], now_axis,
extern char mode_cube_end;
//extern char axis[3]; //x,y,z
void convert_ROTtoLED(void);
void command_turn_ARRAY_2_2(const char *s);
void command_turn_ARRAY_2_3(const char *s1, const char *s2, const char *s3);
//void axis_adjust_ARRAY(void);

// char last_command_3 ;
//char last_command_count_3 ;

void command_turn_ARRAY_3(const char *s);
void command_turn_ARRAY_3_end(void);


extern char ARRAY_skip_CS;

char get_axis(const char *s);
#endif
