#include "printf_CES.h"

const int color_NUM[] = {'W', 'G', 'R', 'B', 'O', 'Y', ' '};

int number_of_moves = 0; //操作回数カウント

int print_mode_flag = 1;
int reset_mode_flag = 1;

void test_mode(void)
{

	int i;
	char s[100];
	char a[] = "state";
	while (1)
	{
		printf("command(help:@):");
		scanf("%s", s);
		if (s[0] == '@')
		{
			printf("command_list:\n");
			printf(" %3s\n", CE_LIST[1].name);
			for (i = CE_LIST_start; i < CE_LIST_COUNT; i++)
			{
				printf(" %3s", CE_LIST[i].name);
				if (i == 11 + CE_LIST_start || i == 23 + CE_LIST_start)
				{
					printf("\n");
				}
			}
			printf("\n");
			printf("mode_list:\n");
			printf(" 1:発光用出力モード(default)\n");
			printf(" 2:回転用出力モード\n");
			printf(" 3:毎回入力結果をリセットする(default)\n");
			printf(" 4:毎回入力結果をリセットしない\n");
			printf(" 0:END\n\n");
		}
		else if (s[0] == '0')
		{
			break;
		}
		else if (s[0] == '1')
		{
			print_mode_flag = 1;
		}
		else if (s[0] == '2')
		{
			print_mode_flag = 2;
		}
		else if (s[0] == '3')
		{
			reset_mode_flag = 1;
		}
		else if (s[0] == '4')
		{
			reset_mode_flag = 0;
		}
		else
		{
			if (command_turn_CE(s) == 0 /*|| str_cmp(a, CE_LIST[1].name) == 0*/)
			{
				number_of_moves++;
				printf("\n操作回数:%d,%s\n\n", number_of_moves, s);

				if (print_mode_flag == 1)
				{ //出力モードを選択
					set_CES();
					preint_SET_LED_2();
					printf("\n");
				}
				else
				{
					print_self(&state_CE);
				}
				if (reset_mode_flag == 1) //回転結果を初期化
					over_write_CE(deff_CE);
			}
			else
			{
				printf("err\n");
			}
		}
	}
}

void preint_SET_LED(void)
{
	int i, k, j;
	for (k = 0; k < 6; k++)
	{
		printf("%d\n", k);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%c,", color_NUM[LED_Light[k][i * 3 + j]]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void preint_SET_LED_2(void)
{
	int i, k, j;

	printf("                     0\n");
	for (i = 0; i < 3; i++)
	{
		printf("                     ");
		for (j = 2; j >= 0; j--)
		{
						printf("%c,", color_NUM[LED_Light[0][i * 3 + j]]);
			//printf("%d%d,", 0, i * 3 + j);
		}
		printf("\n");
	}
	printf("\n");

	printf("4      3      2      1      \n");
	for (k = 0; k < 3; k++)
	{
		for (i = 4; i >= 1; i--)
		{
			printf("%c,%c,%c  ",
				   color_NUM[LED_Light[i][2 + k * 3]],
				   color_NUM[LED_Light[i][1 + k * 3]],
				   color_NUM[LED_Light[i][0 + k * 3]]);
			// printf("%d%d,%d%d,%d%d  ",
			// 	   i, 2 + k * 3
			// 	   , i, 1 + k * 3
			// 	   , i, 0 + k * 3);
		}
		printf("\n");
	}
	printf("\n");

	printf("                     5\n");
	for (i = 0; i < 3; i++)
	{
		printf("                     ");
		for (j = 2; j >= 0; j--)
		{
						printf("%c,", color_NUM[LED_Light[5][i * 3 + j]]);
			//printf("%d%d,", 5, i * 3 + j);
		}
		printf("\n");
	}
}

void preint_SET_LED_COL_NUM(void)
{
	int i, k, j;

	printf("0\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d,", LED_Light[0][i * 3 + j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("1      2      3      4 \n");
	for (k = 0; k < 3; k++)
	{
		for (i = 1; i < 5; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d,", LED_Light[i][j + k * 3]);
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	printf("5\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d,", LED_Light[5][i * 3 + j]);
		}
		printf("\n");
	}
}
void preint_SET_LED_NUM(void)
{
	int i, k, j;

	printf("0\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d%d,", 0, i * 3 + j);
		}
		printf("\n");
	}
	printf("\n");

	printf("1      2      3      4 \n");
	for (k = 0; k < 3; k++)
	{
		for (i = 1; i < 5; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d%d,", i, j + k * 3);
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	printf("5\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d%d,", 5, i * 3 + j);
		}
		printf("\n");
	}
}

void print_self(const CE *now)
{
	int i;
	printf("cp, co, ep, eo, sp\n");

	printf("{");
	for (i = 0; i < 7; i++)
		printf(" %2d,", now->cp[i]);
	printf(" %2d},\n", now->cp[7]);

	printf("{");
	for (i = 0; i < 7; i++)
		printf(" %2d,", now->co[i]);
	printf(" %2d},\n", now->co[7]);

	printf("{");
	for (i = 0; i < 11; i++)
		printf(" %2d,", now->ep[i]);
	printf(" %2d},\n", now->ep[11]);

	printf("{");
	for (i = 0; i < 11; i++)
		printf(" %2d,", now->eo[i]);
	printf(" %2d},\n", now->eo[11]);

	printf("{");
	for (i = 0; i < 5; i++)
		printf(" %2d,", now->sp[i]);
	printf(" %2d},\n", now->sp[5]);
}
