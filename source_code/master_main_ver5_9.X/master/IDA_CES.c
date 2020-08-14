#include "IDA_CES.h"

char shortest_command[want_ddpth];
char shortest_depth;

void initialization_shortest_command(void)
{
	char i;
	shortest_depth = 0;
	for (i = 0; i < want_ddpth; i++)
		shortest_command[i] = '\0';
}

/*
ñﬂÇËíl0ÅFê≥èÌèIóπ
ñﬂÇËílÇQÅFÇ±ÇÃåvéZÇÕÇ∆ÇŒÇ∑
*/
char Create_Shoretest_command_Most_deep(void)
{
	char check_depth;
	char search_flag;
	check_depth = shortest_depth;
	depth_add();

	search_flag = 1;
	while (search_flag == 1)
	{
		search_flag = Create_shortest_command_depp_N1(check_depth); //ëSIDA
		//search_flag = Create_shortest_command_depp_N2(check_depth); //èdï°îrèúIDA
		check_depth--;
	}
	while (branch_off() == 1)
		;
	return search_flag;
}

char branch_off(void)
{
	char return_num = 0;
	char a, b, c = 1, d = 0;

	char check_depth = 0;
	if (shortest_depth == 0)
		return 0;
	check_depth = 0;
	while (check_depth < shortest_depth)
	{
		if (check_depth >= 1)
		{
			c = (18 + shortest_command[check_depth] - shortest_command[check_depth - 1]) % 3;
			d = CE_IDA_LIST[shortest_command[check_depth - 1]].name[0];
		} //if (c == 0)

		a = CE_IDA_LIST[shortest_command[check_depth]].name[0];
		b = CE_IDA_LIST[shortest_command[check_depth + 1]].name[0];
		if ((a == b) || (c == 0 && d == b))

		//		if (shortest_command[check_depth]  == shortest_command[check_depth + 1] )
		{
			return_num = 1;

			// fprintf(fp, "::");
			// printf("::");
			// for (int j = 0; j <= shortest_depth; j++)
			// {
			// 	//			fprintf(fp, "%s", CE_IDA_LIST[shortest_command[j]].name);
			// 	fprintf(fp, "%2d,", shortest_command[j]);
			// 	//				fprintf(fp, "%2d", j);
			// 	printf("%2d,", shortest_command[j]);
			// }

			// printf(":%d\n", shortest_depth);
			// fprintf(fp, "\n");

			if (shortest_command[check_depth + 1] == IDA_LAST_COMAND)
			{
				// printf("a");
				// fprintf(fp, "a");
				signed char i;
				for (i = check_depth; i >= 0; i--)
				{
					if (shortest_command[i] != IDA_LAST_COMAND)
					{
						break;
					}
				}
				//				fprintf(fp, "%d:", i);
				if (i == -1)
				{
					shortest_depth++;
					shortest_command[0] = IDA_FAST_COMMAND;
				}
				else
				{ //ç≈ëÂílÇ≈Ç»Ç¢
					shortest_command[i]++;
				}
				for (check_depth = i + 1; check_depth <= shortest_depth; check_depth++)
					shortest_command[check_depth] = IDA_FAST_COMMAND;
			}
			else
			{
				shortest_command[check_depth + 1]++;

				for (check_depth = check_depth + 2; check_depth <= shortest_depth; check_depth++)
					shortest_command[check_depth] = IDA_FAST_COMMAND;
			}

			break;
		}
		check_depth++;
	}
	return return_num;
}

char depth_add(void)
{
	if (shortest_command[shortest_depth] >= IDA_LAST_COMAND)
	{
		char NEXT_FLAG = 1;
		char check_depth;
		for (check_depth = 0; check_depth < shortest_depth; check_depth++) //Ç∑Ç◊ÇƒÇ™LASTÇ»ÇÁNEXT_FLAG=1
		{
			if (shortest_command[check_depth] != IDA_LAST_COMAND)
			{
				NEXT_FLAG = 0;
			}
		}
		if (NEXT_FLAG)
		{
			shortest_depth++;
			shortest_command[shortest_depth] = IDA_FAST_COMMAND;
			return 1;
		}
		return 0;
	}
	return 0;
}

/*
ñﬂÇËílÇPÅFââéZë±çs
	Å@ÇOÅFââéZèIóπ
	Å@ÇQÅFÇ±ÇÃåvéZÇÕîÚÇŒÇ∑
*/
char Create_shortest_command_depp_N1(char check_depth)
{
	char return_num;
	return_num = 0;
	if (shortest_command[check_depth] == IDA_LAST_COMAND)
	{
		shortest_command[check_depth] = IDA_FAST_COMMAND;
		//if (check_depth != 0)
		return_num = 1;
	}
	else
	{
		shortest_command[check_depth]++;
	}
	return return_num;
}

const CE_LISTER CE_IDA_LIST[IDA_LAST_COMAND + 1] = {
	{&deff_CE, "deff", 0},
	//{&state_CE, "state", 0},

	{&u_CE, "U", 1},
	{&l_CE, "L", 1},
	{&f_CE, "F", 1},
	{&d_CE, "D", 1},
	{&r_CE, "R", 1},
	{&b_CE, "B", 1},

	// {&e_CE_IDA, "E", 1},
	// {&s_CE_IDA, "S", 1},
	//{&m_CE_IDA, "M", 1},

	{&u_CE, "U'", 3},
	{&l_CE, "L'", 3},
	{&f_CE, "F'", 3},
	{&d_CE, "D'", 3},
	{&r_CE, "R'", 3},
	{&b_CE, "B'", 3},

	//{&e_CE_IDA, "E'", 3},
	//{&s_CE_IDA, "S'", 3},
	//{&m_CE_IDA, "M'", 3},

	{&u_CE, "U2", 2},
	{&l_CE, "L2", 2},
	{&f_CE, "F2", 2},
	{&d_CE, "D2", 2},
	{&r_CE, "R2", 2},
	{&b_CE, "B2", 2},

	// {&e_CE_IDA, "E2", 2},
	// {&s_CE_IDA, "S2", 2},
	// {&m_CE_IDA, "M2", 2},

};

const CE m_CE_IDA = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 2, 3, 8, 5, 4, 7, 10, 9, 6, 11},
	{0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{3, 0, 2, 5, 4, 1}};

const CE s_CE_IDA = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4, 7, 6, 11, 8, 5, 10, 9},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{4, 1, 0, 3, 5, 2}};

const CE e_CE_IDA = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 4, 1, 2, 3, 5}};
