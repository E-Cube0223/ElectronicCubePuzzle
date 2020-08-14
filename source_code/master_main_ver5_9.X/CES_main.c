/*
âÒì]ãLçÜ
https://tribox.com/3x3x3/solution/notation/
https://qiita.com/7y2n/items/a840e44dba77b1859352
*/

#include <stdlib.h>
#include <stdio.h>
#include "operation_CES.h"
#include "solution_CES.h"
#include "printf_CES.h"
#include "change_need_CE.h"
#include "Make_log.h"
#include "IDA_CES.h"
#include <time.h>
#include "animation.h"
#include "XTAL.h"
// void main()
// {
// 	// mode_cube_end = 1;
// 	// set_CES();
// 	// printf("start\n");
// 	// command_turn_ARRAY_3("B");
// 	// command_turn_ARRAY_3("F");
// 	// command_turn_ARRAY_3("B");
// 	// command_turn_ARRAY_3("X");
// 	// command_turn_ARRAY_3("L");
// 	// command_turn_ARRAY_3("R'");
// 	// command_turn_ARRAY_3("X'");
// 	// command_turn_ARRAY_3("X'");
// 	// command_turn_ARRAY_3("R");
// 	// command_turn_ARRAY_3("R");
// 	// command_turn_ARRAY_3("B");
// 	// command_turn_ARRAY_3("F");
// 	// command_turn_ARRAY_3("B");
// 	// command_turn_ARRAY_3("X");
// 	// command_turn_ARRAY_3("L");
// 	// command_turn_ARRAY_3("R'");
// 	// command_turn_ARRAY_3("X'");
// 	// command_turn_ARRAY_3("X'");
// 	// command_turn_ARRAY_3("R");
// 	// command_turn_ARRAY_3("R");
// 	// command_turn_ARRAY_3_end();

// 	// printf("end\n");
// 	// set_CES();
// 	// preint_SET_LED_2();
// 	// return;

// 	// //shuffle_state_CE(0);
// 	// printf("start>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
// 	// set_CES();
// 	// preint_SET_LED_2();
// 	// printf("\n");
// 	// print_self(&state_CE);

// 	// return;
// 	// made_cube();
// 	// make_flont_green();

// 	// set_CES();
// 	// preint_SET_LED_2();
// 	// printf("\n");
// 	// print_self(&state_CE);

// 	// return;
// 	// print_self(&state_CE);
// 	// set_CES();
// 	// preint_SET_LED_2();
// 	// printf("%c,%c,", color_NUM[LED_Light[3][3]], color_NUM[LED_Light[2][5]]); //,color_NUM[LED_Light[2][2]]);
// 	// return;
// 	// while (1)
// 	// {
// 	// }

// 	int i; //, j = 0;
// 	setup_log("firtest_.txt");

// 	initialization_shortest_command();
// 	clock_t start, end;
// 	start = clock();
// 	while (shortest_depth < want_ddpth)
// 	{
// 		//		j++;

// 		i = Create_Shoretest_command_Most_deep();
// 		if (i == 0)
// 		{
// 			if (shortest_depth >= want_ddpth)
// 				break;
// 			int j;
// 			for (j = 0; j <= shortest_depth; j++)
// 			{
// 				fprintf(fp, "%-2s ", CE_IDA_LIST[shortest_command[j]].name);
// 				//		fprintf(fp, "%2d,", shortest_command[j]);
// 				// fprintf(fp, "%2d", j);
// 				//printf("%2d,", shortest_command[j]);
// 			}
// 			end = clock();
// 			printf("%.2f???????\n", (double)(end - start) / CLOCKS_PER_SEC);

// 			//		printf(":%d,%d\n", shortest_depth, j);
// 			fprintf(fp, "\n");
// 		}
// 	}
// 	end = clock();
// 	printf("%.2f???????\n", (double)(end - start) / CLOCKS_PER_SEC);
// 	endup_log();
// }

void main(void)
{
	unsigned int seed_number = 10;
	unsigned int i, p = 0;
	srand(10);

	// printf("R------------------------------------------------------------");
	// TURN_COUNT = 0;
	// over_write_CE(deff_CE);
	// command_turn_CE("U");
	// set_CES();
	// preint_SET_LED_2();
	// printf("\n");
	// //print_self(&state_CE);
	// for (i = 0; i < 3; i++)
	// {
	// 	command_turn_ARRAY("R");
	// 	preint_SET_LED_2();
	// 	printf("\n");
	// }

	// printf("R------------------------------------------------------------");
	// TURN_COUNT = 0;
	// over_write_CE(deff_CE);
	// //command_turn_CE("R");
	// set_CES();
	// preint_SET_LED_2();
	// printf("\n");
	// //print_self(&state_CE);
	// for (i = 0; i < 3; i++)
	// {
	// 	command_turn_ARRAY("R");
	// 	preint_SET_LED_2();
	// 	printf("\n");
	// }

	//10177

	setup_log("CE_log.txt");

	for (i = 1 + p; i < 65500 + p; i++)
	{
		printf("%d, ", i);
		fprintf(fp, "seed_count=%4d, ", i);
		seed_number = i; //rand()%5000;
		shuffle_state_CE(seed_number);
		fprintf(fp, "seed_number=%4d, ", seed_number);
		printf("seed_number=%4d-------------------------------------------,\n", seed_number);
		total_number_of_moves = 0;
		made_cube(1, 1);
		if (if_solution_end() == 0)
		{
			fprintf(fp, "OK , ");
			printf("OK , \n");
		}
		else
		{
			printf("ERR , \n");
			fprintf(fp, "ERR, ");
		}
		fprintf(fp, "total_number_of_moves:%4d\n", total_number_of_moves);
	}
	endup_log();

	// err_seed_CE(10177);
	// if (if_solution_end() == 0)
	// {
	// 	printf("OK , ");
	// }
	// else
	// {
	// 	printf("ERR, ");
	// }
/*
	total_number_of_moves = 0;
	printf("start>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	set_CES();
	preint_SET_LED_2();
	printf("\n");
	print_self(&state_CE);
	made_cube();
	make_flont_green();

	set_CES();
	preint_SET_LED_2();
	printf("\n");
	print_self(&state_CE);
	printf("total_number_of_moves:%d\n", total_number_of_moves);
*/}
