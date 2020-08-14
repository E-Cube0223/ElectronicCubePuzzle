#include "solution_CES.h"
#include "animation.h"

int opereation_count;
char opereation_over_flag;
char limit_count;

void made_cube(char Light_ON_OFF, const char skip_CS)
{
	char i;
	const char start8[14][3] = {
		"L'", "D'", "L", "D'", "L'", "D2", "L", "B", "D", "B'",
		"D", "B", "D2", "B'"};

	char test_flag = 0;

	mode_cube_end = Light_ON_OFF;
	ARRAY_skip_CS = skip_CS;

	do
	{
		operation_first();
		command_turn_ARRAY_3_end();
		make_justice_axis();
	} while (opereation_over_flag == 1);
	operation_first();
	limit_count = 0;

	while (test_flag != 4)
	{

		switch (test_flag)
		{
		case 0: //完全一面が完成しているか
			make_up_white();
			if (if_perfect_white() == 1) //完全一面
			{
				make_up_yellow();
				make_white_yellow_flower(); //黄色と白の花を作る
				make_while_flower();		//白花完成
				make_up_white();
				make_perfect_white();
			}
			test_flag = 1;
			break;
		case 1: //二段目
			//			make_flont_green();
			if (if_second_flower_perfect() != 0)
			{
				make_up_yellow();
				make_second_flower_perfect();
				make_up_white();
			}
			test_flag = 2;
			break;
		case 2:

			if (if_perfect_yellow() != 0)
			{
				yellow_cross();
				all_yellow();
			}
			test_flag = 3;
			break;
		case 3:
			if (if_solution_end() != 0)
			{
				make_step_7();
				if (if_start_step8() == 1)
				{
					for (i = 0; i < 14; i++)
					{
						command_turn_ARRAY_3(start8[i]);
					}
				}

				make_step_8();
			}

			if (if_solution_end() != 0) //解答に失敗したので最初から
			{
				test_flag = 0;
				limit_count++;
				command_turn_ARRAY_3("R");
				command_turn_ARRAY_3("L");
				command_turn_ARRAY_3("U");
				command_turn_ARRAY_3("B");
			}
			else
			{
				make_justice_axis();
				test_flag = 4;
			}
			break;
		default:
			break;
		}

		if (opereation_over_flag == 1 || limit_count > 5)
		{
			operation_first();
			limit_count++;

			if (limit_count > 5)
			{//諦める
				return;
			}
			command_turn_ARRAY_3("R");
			command_turn_ARRAY_3("L");
			command_turn_ARRAY_3("U");
			command_turn_ARRAY_3("B");
			make_justice_axis();
			test_flag = 0;
		}
	}
	command_turn_ARRAY_3_end();
	__delay_ms(100); //100
}

char if_solution_end(void)
{
	char i, xo = 0, p_start, j;
	//	make_flont_green();
	for (p_start = 0; p_start < 8; p_start++)
	{
		if (state_CE.cp[p_start] == 0)
		{
			break;
		}
	}
	for (j = 0; j < 2; j++)
	{
		for (i = j * 4; i < (1 + j) * 4; i++) //段チェック
		{

			if (state_CE.cp[(i + p_start) % 4 + j * 4] != deff_CE.cp[i])
				return 1;
			xo += state_CE.co[i];
		}
	}

	if (xo != 0)
		return 1;

	for (p_start = 0; p_start < 12; p_start++)
	{
		if (state_CE.ep[p_start] == 0)
		{
			break;
		}
	}
	xo = 0;
	for (j = 0; j < 3; j++)
	{
		for (i = j * 4; i < (1 + j) * 4; i++) //段チェック
		{

			if (state_CE.ep[(i + p_start) % 4 + j * 4] != deff_CE.ep[i])
				return 1;
			xo += state_CE.eo[i];
		}
	}
	if (xo != 0 && xo != 4)
		return 1;

	return 0;
}

char if_start_step8(void)
{
	char i, j = 0;
	for (i = 0; i < 4; i++)
	{
		if (state_CE.ep[8] - state_CE.cp[4] == 4)
		{
			return 0;
		}
		command_turn_ARRAY_3("Y");
	}
	command_turn_ARRAY_3("Y");
	return 1;
}

char if_perfect_yellow(void)
{
	char i, distortion = 0; //ねじれ
	for (i = 0; i < 4; i++)
	{
		if (state_CE.cp[i + 4] != i + 4)
			return 1;
		distortion += state_CE.co[i + 4];
	}
	for (i = 0; i < 4; i++)
	{
		if (state_CE.ep[i + 8] != i + 8)
			return 1;
		distortion += state_CE.eo[i + 8];
	}
	if (distortion != 0)
		return 1;
	return 0;
}


void make_while_flower(void)
{
	char i;
	if (operation_setup() == 1)
		return;

	for (i = 0; i < 4;)
	{
		if (operation_limit(20) == 1)
			return;

		if ((state_CE.ep[4] == 4 && state_CE.sp[3] == 3) || (state_CE.ep[4] == 5 && state_CE.sp[3] == 2) || (state_CE.ep[4] == 6 && state_CE.sp[3] == 1) || (state_CE.ep[4] == 7 && state_CE.sp[3] == 4))
		{
			i++;
			command_turn_ARRAY_3("B2");
			command_turn_ARRAY_3("Y");
		}
		else
		{
			command_turn_ARRAY_3("U");
		}
	}
}

void make_white_yellow_flower(void)
{
	char i = 0;
	char mark_count = 0;
	const char command[3][6][3] = {
		{"F'", "E", "F", "M", "D2", "M'"},
		{"E'", "F'", "E", "F"}};
	char t;
	while (mark_count < 4)
	{
		if (if_EP(6, 4, 7) == 1) //手前中央に上パーツがある
		{
			if (state_CE.eo[6] != 0) //上パーツがねじれている
			{
				//コマンド//パーツ正しい位置に
				for (t = 0; t < 6; t++)
					command_turn_ARRAY_3(command[0][t]);
			}
			mark_count++;
			command_turn_ARRAY_3("Y"); //手前中央上が正しい向きにあるので次の上コーナーを手前に移動
			continue;
		}
		else if (if_EP(3, 4, 7) == 1)
		{
			//中央左手前を上中央手前に
			for (t = 0; t < 4; t++)
				command_turn_ARRAY_3(command[1][t]);
			continue;
		}
		else if (if_EP(10, 4, 7) == 1)
		{
			//した中央手前を上中央手前に
			command_turn_ARRAY_3("M");
			command_turn_ARRAY_3("D2");
			command_turn_ARRAY_3("M'");
			continue;
		}
		command_turn_ARRAY_3("E'");
		command_turn_ARRAY_3("D'");
	}
}

char if_CP(char check, char s_cp, char e_cp)
{
	char i, DATA = 0;
	for (i = s_cp; i <= e_cp; i++)
	{
		if (state_CE.cp[check] == i)
		{
			DATA = 1;
			break;
		}
	}
	return DATA;
}

char if_EP(char check, char s_ep, char e_ep)
{
	char i;
	for (i = s_ep; i <= e_ep; i++)
	{
		if (state_CE.ep[check] == i)
		{
			return 1;
		}
	}
	return 0;
}

char if_perfect_white(void)
{
	signed char j, i;
	command_turn_ARRAY_3_end();
	for (i = 0; i < 4; i++)
	{
		if (if_CP(i, 0, 3) != 1)
			return 1; //全上面CPが白を含まない
	}
	for (i = 0; i < 4; i++)
	{
		if (state_CE.co[i] != 0)
			return 2; //全上面CPの白が上面向き
	}

	for (i = 3; i >= 0; i--)
	{
		if (state_CE.cp[i] == 3)
			break;
	}
	for (j = 0; j < 4; j++)
	{
		if (state_CE.cp[(i - j + 4) % 4] != 3 - j)
			return 3; //全上面CPの白が正しい配置
	}
	return 0;
}

char if_second_flower_perfect(void) //
{
	signed char i, j;
	for (i = 0; i < 4; i++)
	{
		if (if_EP(i, 0, 3) != 1)
			return 1;
	}

	j = 0;
	for (i = 0; i < 4; i++)
	{
		j += state_CE.eo[i];
	}
	if (j != 0 && j != 4)
		return 2;

	for (i = 3; i >= 0; i--)
	{
		if (state_CE.ep[i] == 0)
			break;
	}
	for (j = 0; j < 4; j++)
	{
		if (state_CE.cp[4 + j] - state_CE.ep[j] != 0)
			return 3;
	}
	return 0;
}

/*
上下を変えているがそのせいで終了条件が信頼できなくなっている。
10
23
と中段の配置が鳴っている
01
32
の順でifを行っているためどうするべきだろうか？
配列に値を代入して行く？
 */
void make_second_flower_perfect(void)
{
	char i, flont_0 = 0, search_ep, j;
	const char command_drop_right[8][3] = {"U", "R", "U'", "R'", "U'", "F'", "U", "F"};
	const char command_drop_left[8][3] = {"U'", "L'", "U", "L", "U", "F", "U'", "F'"};

	if (operation_setup() == 1)
		return;

	while (if_second_flower_perfect() != 0)
	{

		if (operation_limit(100) == 1)
			return;
		for (search_ep = 0; search_ep < 4; search_ep++)
		{
			if (if_second_flower_perfect() == 0)
				break;
			if (operation_limit(100) == 1)
				return;
			make_flont_green();

			if (state_CE.ep[0] == search_ep || state_CE.ep[1] == search_ep || state_CE.ep[2] == search_ep || state_CE.ep[3] == search_ep) //正しい位置に正しいパーツがある//上下逆になっているのを忘れている
			{
				if (state_CE.eo[search_ep] != 0 || state_CE.cp[search_ep + 4] - state_CE.ep[search_ep] != 0) //パーツの向きが正しくない || パーツの位置が正しくない
				{
					if (search_ep <= 1)
					{
						command_turn_ARRAY_3("Y");
						command_turn_ARRAY_3("Y");
					}
					if (search_ep % 2 == 0)
					{
						for (i = 0; i < 8; i++)
						{
							command_turn_ARRAY_3(command_drop_right[i]);
						}
					}
					else
					{
						for (i = 0; i < 8; i++)
						{
							command_turn_ARRAY_3(command_drop_left[i]);
						}
					}
				}
				else
				{
					continue; //正しい位置と向きである
				}
			}
			if (search_ep < 2) //後川を調べる
			{
				command_turn_ARRAY_3("Y");
				command_turn_ARRAY_3("Y");
			}
			for (i = 0; i < 4; i++)
			{
				if (state_CE.ep[6] == search_ep)
				{
					flont_0 = 0;
					if (state_CE.eo[6] == 0) //前が直線でない
					{
						if (search_ep % 2 == 0)
						{ //上から見て反時計
							command_turn_ARRAY_3("E");
							command_turn_ARRAY_3("D");
						}
						else
						{ //上から見て時計
							command_turn_ARRAY_3("E'");
							command_turn_ARRAY_3("D'");
							//左落とし
						}
						flont_0++;
					}
					//落とす方向はiとjを2で割って決める？
					if ((search_ep + flont_0) % 2 == 1)
					{
						for (j = 0; j < 8; j++)
						{
							command_turn_ARRAY_3(command_drop_right[j]);
						}
					}
					else
					{
						for (j = 0; j < 8; j++)
						{
							command_turn_ARRAY_3(command_drop_left[j]);
						}
					}
					search_ep = 0;
					break;
				}
				else
				{
					command_turn_ARRAY_3("U");
					if (i == 3 && search_ep == 3)
					{
						make_flont_green();
						for (i = 0; i < 4; i++)
						{
							if (state_CE.ep[i] == i)
							{
								search_ep = 3 - i;
								break;
							}
						}
						for (i = 0; i < search_ep; i++)
						{
							command_turn_ARRAY_3("Y");
						}
						for (i = 0; i < 8; i++)
						{
							command_turn_ARRAY_3(command_drop_left[i]);
						}
						i = 5;
						search_ep = 0; //ここがcontinueでできるか調べる
					}
				}
			}
		}
	}
}

char make_flont_green(void)
{
	int move_count = 0;
	if (state_CE.sp[0] == green || state_CE.sp[5] == green)
		command_turn_ARRAY_3("X");

	while (state_CE.sp[1] != green)
	{

		command_turn_ARRAY_3("Y");
	}
	return move_count;
}

void make_up_white(void)
{
	if (state_CE.sp[2] == white || state_CE.sp[4] == white)
		command_turn_ARRAY_3("Y");

	while (state_CE.sp[0] != white)
	{

		command_turn_ARRAY_3("X");
	}
}

void yellow_cross(void)
{
	const char cross_eo[4] = {0, 0, 0, 0};
	const char check_eo[2][4] = {
		{1, 0, 1, 0},  //-
		{0, 0, 1, 1}}; //v
	const char step5[6][3] = {"B", "R", "D", "R'", "D'", "B'"};
	char i, j;

	if (operation_setup() == 1)
		return;

	while (if_yellow_eo(cross_eo) == 1)
	{
		if (operation_limit(50) == 1)
			return;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < (i + 1) * 2; j++)
			{
				if (if_yellow_eo(check_eo[i]) == 0)
				{
					i = 3;
					break;
				}
				command_turn_ARRAY_3("D");
			}
		}
		for (i = 0; i < 6; i++)
		{
			command_turn_ARRAY_3(step5[i]);
		}
	}
}

char if_yellow_eo(const char eo[])
{
	char i;
	for (i = 0; i < 4; i++)
	{
		if (state_CE.eo[8 + i] != eo[i])
		{
			return 1;
		}
	}
	return 0;
}

void all_yellow(void)
{
	char check_CO = 7, i, j;
	const char CO[8][4] = {
		{1, 0, 2, 0},  //A
		{0, 0, 2, 1},  //B1
		{0, 1, 2, 0},  //B2
		{1, 2, 1, 2},  //C1
		{2, 2, 1, 1},  //C2
		{2, 2, 0, 2},  //D1
		{1, 1, 0, 1},  //D2
		{0, 0, 0, 0}}; //end
	const char step6[7][3] = {"R", "D2", "R'", "D'", "R", "D'", "R'"};

	if (operation_setup() == 1)
		return;

	while (if_yellow_co(CO[7]) != 0)
	{
		if (operation_limit(50) == 1)
			return;
		for (i = 0; i < 4; i++)
		{
			if (if_yellow_co(CO[check_CO]) == 0)
			{
				for (j = 0; j < 7; j++)
				{
					command_turn_ARRAY_3(step6[j]);
				}
				check_CO = 7;
				break;
			}
			else
			{
				command_turn_ARRAY_3("D");
			}
		}
		check_CO--;
	}
}

char if_yellow_co(const char co[])
{
	char i;
	for (i = 0; i < 4; i++)
	{
		if (state_CE.co[4 + i] != co[i])
		{
			return 1;
		}
	}
	return 0;
}

void make_up_yellow(void)
{
	if (state_CE.sp[2] == yellow || state_CE.sp[4] == yellow)
		command_turn_ARRAY_3("Y");

	while (state_CE.sp[0] != yellow)
	{

		command_turn_ARRAY_3("X");
	}
}

char if_all_2pair(void)
{
	int i, if_flag = 0, re = 0, x, y = 0;
	for (i = 0; i < 4; i++)
	{
		if (state_CE.cp[i + 4] == 4)
		{
			break;
		}
	}
	if_flag = i;
	for (i = 0; i < 4; i++)
	{
		if (state_CE.cp[4 + (i + if_flag) % 4] != i + 4)
		{
			re = 1;
		}
	}
	return re;
}

char if_no_pair(void)
{
	char i;

	command_turn_ARRAY_3_end(); //LED配列を確認するため計算中のものをセットしなおす必要あり
	set_C();
	for (i = 1; i < 5; i++)
	{
		if (LED_Light[i][6] == LED_Light[i][8])
			return 1;
	}
	return 0;
}

void make_step_7(void)
{
	const char start7[20][3] = {
		"R", "L'", "D", "R'", "D'", "L", "D", "R", "D'", "R'",
		"R'", "D'", "R", "D", "L", "D'", "R'", "D", "R", "L'"};
	char  i;
	const char step7[14][3] = {
		"R", "D", "R'", "D'", "R'", "B", "R2",
		"D'", "R'", "D'", "R", "D", "R'", "B'"};

	if (if_no_pair() == 0)
	{

		for (i = 0; i < 20; i++)
		{
			command_turn_ARRAY_3(start7[i]);
		}
	}
	if (if_all_2pair() == 0)
	{
		return;
	}
	make_flont_green();

	if (operation_setup() == 1)
		return;

	while (if_2pair() == 1)
	{
		if (operation_limit(50) == 1)
			return;
		command_turn_ARRAY_3("D");
	}
	command_turn_ARRAY_3("D");
	if (operation_setup() == 1)
		return;

	while (state_CE.cp[4] - state_CE.cp[0] != 4) //--------------------------------------------------------------------------
	{
		if (operation_limit(8) == 1)
			return;
		command_turn_ARRAY_3("U'");
		command_turn_ARRAY_3("E");
	}

	for (i = 0; i < 14; i++)
	{
		command_turn_ARRAY_3(step7[i]);
	}
	make_flont_green();
}

void make_step_8(void)
{
	const char step8[7][3] = {"M2", "D'", "M", "D2", "M'", "D'", "M2"};
	char i = 0;
	if (if_solution_end() == 0)
		return;

	if (operation_setup() == 1)
		return;

	while (1)
	{
		if (operation_limit(50) == 1)
			return;
		if (state_CE.ep[10] - state_CE.ep[6] == 4 && state_CE.cp[7] - state_CE.cp[3] == 4)
		{
			if (if_solution_end() == 0)
			{
				return;
			}
			for (i = 0; i < 7; i++)
			{
				command_turn_ARRAY_3(step8[i]);
			}
			if (state_CE.ep[8] - state_CE.ep[4] == 4 && state_CE.cp[5] - state_CE.cp[1] == 4)
			{
			}
			else
			{
				for (i = 0; i < 7; i++) //--------------------------------------------
				{
					command_turn_ARRAY_3(step8[i]);
				}
			}
			break;
		}
		i++;
		command_turn_ARRAY_3("D");
		if (i >= 4)
		{
			command_turn_ARRAY_3("U");
			command_turn_ARRAY_3("E'");
			i = 0;
		}
	}
}

char if_2pair(void)
{
	char i;
	if (state_CE.cp[5] - state_CE.cp[4] == 1)
	{
		return 0;
	}
	if (state_CE.cp[5] == 4 && state_CE.cp[4] == 7)
	{
		return 0;
	}
	return 1;
}

void make_perfect_white(void)
{

	signed char mark_count = 3, EPW_count = 1, i = 3, j;

	make_flont_green();
	if (operation_setup() == 1)
		return;
	command_turn_ARRAY_3_end();

	while (if_perfect_white() != 0) //mark_count >= 0)
	{
		command_turn_ARRAY_3_end();

		if (operation_limit(100) == 1)
			return;

		if (if_CP(3, 0, 3) == 1)
		{

			if (state_CE.co[3] != 0 || state_CE.cp[3] != mark_count)
			{ //2を操作している

				command_turn_ARRAY_3("L");
				command_turn_ARRAY_3("D");
				command_turn_ARRAY_3("L'");
				command_turn_ARRAY_3("D'");
				//continue;
			}

			mark_count--;
			if (mark_count < 0)
				mark_count = 3;
			command_turn_ARRAY_3("U");
			command_turn_ARRAY_3("E'");
			continue;
		}

		for (j = 0; j < 4; j++)
		{

			if (state_CE.cp[7] == mark_count)
			{

				switch (state_CE.co[7])
				{
				case 0:
					EPW_count = 3;
					break;
				case 1:
					EPW_count = 5; //?
				case 2:
					EPW_count = 1;
					break;
				default:
					break;
				}

				for (i = 0; i < EPW_count; i++)
				{
					command_turn_ARRAY_3("L");
					command_turn_ARRAY_3("D");
					command_turn_ARRAY_3("L'");
					command_turn_ARRAY_3("D'");
					j = 5;
				}
				break;
			}

			command_turn_ARRAY_3("D'");
		}
		mark_count--;
		if (mark_count < 0)
		{
			mark_count = 3;
		}
		command_turn_ARRAY_3("Y");
	}
}

void make_justice_axis(void)
{
	if (state_CE.sp[0] != white)
	{
		make_up_white();
	}
	if (operation_setup() == 1)
		return;
	while (state_CE.sp[1] != green)
	{
		if (operation_limit(8) == 1)
			return;
		command_turn_ARRAY_3("Y");
	}
}

char operation_limit(const int count)
{
	opereation_count++;
	if (opereation_count > count)
	{
		opereation_over_flag = 1;
		return 1;
	}
	return 0;
}

void operation_first(void)
{
	opereation_count = 0;
	opereation_over_flag = 0;
}

char operation_setup(void)
{
	if (opereation_over_flag == 1)
	{
		return 1;
	}
	opereation_count = 0;
	return 0;
}
