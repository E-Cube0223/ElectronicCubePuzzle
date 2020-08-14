#include <stdio.h>
#include <stdlib.h>
#include "change_need_CE.h"
#include"operation_CES.h"
#include"printf_CES.h"

#include "solution_CES.h"
void shuffle_state_CE(const unsigned int seed_number)
{
	char rand_CE[20];
	char i;
	srand(seed_number);

	for (i = 0; i < 20; i++)
	{
		rand_CE[i] = 2 + rand() % 18;
	}
	for (i = 0; i < 20; i++)
	{
		command_turn_CE(CE_LIST[rand_CE[i]].name);
	}
}

void err_seed_CE(const unsigned int seed_number)
{
	char rand_CE[20];
	char i;
	srand(seed_number);

	for (i = 0; i < 20; i++)
	{
		rand_CE[i] = 2 + rand() % 18;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s, ", CE_LIST[rand_CE[i]].name);
		command_turn_CE(CE_LIST[rand_CE[i]].name);
	}
	printf("\n");
	set_CES();
	preint_SET_LED_2();
	printf("\n");
	print_self(&state_CE);

	total_number_of_moves = 0;
	printf("start>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	set_CES();
	preint_SET_LED_2();
	printf("\n");
	print_self(&state_CE);
	made_cube(1,1);
	make_flont_green();

	set_CES();
	preint_SET_LED_2();
	printf("\n");
	print_self(&state_CE);
	printf("total_number_of_moves:%d\n", total_number_of_moves);
}
