/*
want_ddpth回までで解答できるルービックキューブの探索
*/
#ifndef _IDA_CES_H_
#define _IDA_CES_H_
#include "operation_CES.h"
#include <stdlib.h>
#include <stdio.h>
#define IDA_LAST_COMAND 18//9 * 3 + 1-6
#define IDA_FAST_COMMAND 1
#define want_ddpth 2
char depth_add(void);

extern const CE m_CE_IDA;
extern const CE s_CE_IDA;
extern const CE e_CE_IDA;

extern const CE_LISTER CE_IDA_LIST[IDA_LAST_COMAND + 1];

extern char shortest_command[want_ddpth];
extern char shortest_depth;
void initialization_shortest_command(void);

char Create_Shoretest_command_Most_deep(void);
char Create_shortest_command_depp_N1(char check_depth);
char branch_off(void);
#endif
