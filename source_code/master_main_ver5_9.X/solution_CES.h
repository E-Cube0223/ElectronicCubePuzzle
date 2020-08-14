
#ifndef _SOLUTION_CES_H_
#define _SOLUTION_CES_H_
#include "animation.h"
#include "operation_CES.h"
//#include "SerialLED_PIC18F25K22.h"
//#include <htc.h>
#include "XTAL.h"
char flower_check(void);
void make_while_flower(void);
void make_white_yellow_flower(void);
char if_CP(char check, char s_cp, char e_cp);
char if_EP(char check, char s_ep, char e_ep);
void make_perfect_white(void);
char if_perfect_white(void);
char make_flont_green(void);
void make_up_white(void);
void make_up_yellow(void);

void make_second_flower_perfect(void);
char if_second_flower_perfect(void);
void made_cube(char, const char);
void yellow_cross(void);
char if_yellow_eo(const char eo[]);

char if_yellow_co(const char co[]);
void all_yellow(void);
void make_step_7(void);
char if_2pair(void);
void make_step_8(void);
char if_perfect_yellow(void);
char if_solution_end(void);

char if_start_step8(void);
char if_all_2pair(void);
char if_no_pair(void);
void make_justice_axis(void);

char operation_limit(const int count);
char operation_setup(void);
void operation_first(void);

#endif