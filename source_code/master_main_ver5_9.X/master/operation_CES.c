#include "operation_CES.h"

char LED_Light[6][9];
unsigned int total_number_of_moves = 0;

void set_CES(void)
{
    int i;

    set_S();
    set_C();
    set_E();
}

void turn_CE(const CE_LISTER *change)
{
    int i, j;
    for (j = 0; j < change->CE_count; j++)
    {
        CE past = state_CE;

        for (i = 0; i < 8; i++)
        {
            state_CE.cp[i] = past.cp[change->DATA->cp[i]];
            state_CE.co[i] = (past.co[change->DATA->cp[i]] + change->DATA->co[i]) % 3;
        }
        for (i = 0; i < 12; i++)
        {
            state_CE.ep[i] = past.ep[change->DATA->ep[i]];
            state_CE.eo[i] = (past.eo[change->DATA->ep[i]] + change->DATA->eo[i]) % 2;
        }
        for (i = 0; i < 6; i++)
        {
            state_CE.sp[i] = past.sp[change->DATA->sp[i]];
        }
    }
}

char TURN_COUNT = 0;

void command_turn_ARRAY(const char *s)
{
    const TURN_NUM TURN_NUM_R = {
        {0, 1, 5, 3},
        {0, 3, 6, 0, 3, 6, 0, 3, 6, 8, 5, 2}
    };
    const TURN_NUM TURN_NUM_U = {
        {1, 4, 3, 2},
        {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 0}
    };
    const TURN_NUM TURN_NUM_F = {
        {0, 2, 5, 4},
        {6, 7, 8, 0, 3, 6, 2, 1, 0, 8, 5, 2}
    };

    const TURN_NUM TURN_NUM_L = {
        {0, 3, 5, 1},
        {8, 5, 2, 0, 3, 6, 8, 5, 2, 8, 5, 2}};
    const TURN_NUM TURN_NUM_D = {
        {1, 2, 3, 4},
        {6, 7, 8, 6, 7, 8, 6, 7, 8, 6, 7, 8}};
    const TURN_NUM TURN_NUM_B = {
        {0, 4, 5, 2},
        {2, 1, 0, 0, 3, 6, 6, 7, 8, 8, 5, 2}};

    const TURN_NUM TURN_NUM_M = {
        {0, 3, 5, 1},
        {7, 4, 1, 1, 4, 7, 7, 4, 1, 7, 4, 1}};
    const TURN_NUM TURN_NUM_S = {
        {0, 2, 5, 4},
        {3, 4, 5, 1, 4, 7, 5, 4, 3, 7, 4, 1},
    };
    const TURN_NUM TURN_NUM_E = {
        {1, 2, 3, 4},
        {3, 4, 5, 3, 4, 5, 3, 4, 5, 3, 4, 5}};

        
    char for_count_num = 1;
    char MOVE_LOW = 0;
    const TURN_NUM *MEN_NUM;
    const char for_count_LIST[4] = {1, 11, 11, 1};
    char SIDE_SURFACE;
    char SIDE_TURN_FLG = 1;
    char for_count;
    char for_count_2;
    SIDE_TURN_FLG = 1;
    
	
    if (*(s + 1) == '\'')
    {
        for_count_num = 1;
    }
    else
    {
        for_count_num = 0;
    }
    switch (*s)
    {
    case 'R':
        MEN_NUM = &TURN_NUM_R;
        MOVE_LOW = 0;
        SIDE_SURFACE = 4;
        break;
    case 'L':
        MEN_NUM = &TURN_NUM_L;
        MOVE_LOW = 2;
        SIDE_SURFACE = 2;
        break;
    case 'U':
        SIDE_SURFACE = 0;
        MEN_NUM = &TURN_NUM_U;
        MOVE_LOW = 0;
        break;
    case 'D':
        SIDE_SURFACE = 5;
        MEN_NUM = &TURN_NUM_D;
        MOVE_LOW = 2;
        break;
    case 'F':
        SIDE_SURFACE = 1;
        MEN_NUM = &TURN_NUM_F;
        MOVE_LOW = 0;
        break;
    case 'B':
        MOVE_LOW = 2;
        SIDE_SURFACE = 3;
        MEN_NUM = &TURN_NUM_B;
        break;


    case 'M':
        MOVE_LOW = 2;
        MEN_NUM = &TURN_NUM_M;
        SIDE_TURN_FLG = 0;
        break;
    case 'S':
        MOVE_LOW = 0;
        SIDE_TURN_FLG = 0;
        MEN_NUM = &TURN_NUM_S;
        break;
    case 'E':
        MOVE_LOW = 2;
        MEN_NUM = &TURN_NUM_E;
        SIDE_TURN_FLG = 0;
        break;
    }
    for (for_count = 0; for_count < for_count_LIST[for_count_num + MOVE_LOW]; for_count++)
    {
        MOVE_LOW = 0;
        ARRAY_LINE_TURN(MOVE_LOW, *MEN_NUM);
    }
    if (SIDE_TURN_FLG == 1)
    {
		
        for (for_count_2 = 0; for_count_2 < for_count_LIST[for_count_num]; for_count_2++)
        {
            ARRAY_SIDE_TURN(SIDE_SURFACE);
        }
    }
}

void ARRAY_LINE_TURN(const char MOVE_LOW, const TURN_NUM MEN_NUM_1)
{
    char temp, i, j;
    char SURFASE;
    temp = LED_Light[MEN_NUM_1.MEN_SURFASE[0]][MEN_NUM_1.POINT_NUM[0]];
    for (i = 0; i < 4; i++)
    {
        SURFASE = MEN_NUM_1.MEN_SURFASE[i];
        for (j = 0; j < 2; j++)
        {
            LED_Light[SURFASE][MEN_NUM_1.POINT_NUM[j + i * 3]] = LED_Light[SURFASE][MEN_NUM_1.POINT_NUM[j + 1 + i * 3]];
        }
        LED_Light[SURFASE][MEN_NUM_1.POINT_NUM[2 + i * 3]] = LED_Light[MEN_NUM_1.MEN_SURFASE[i + 1]][MEN_NUM_1.POINT_NUM[(i + 1) * 3 + 0]];
    }
    LED_Light[MEN_NUM_1.MEN_SURFASE[3]][MEN_NUM_1.POINT_NUM[11]] = temp;
}

void ARRAY_SIDE_TURN(const char surface)
{
    const char side_NUM[8] = {0, 1, 2, 5, 8, 7, 6, 3};
    char temp, i;
    if (TURN_COUNT != 2 && TURN_COUNT != 5 && TURN_COUNT != 8 && TURN_COUNT != 11)
    {
        temp = LED_Light[surface][side_NUM[0]];
        for (i = 0; i < 7; i++)
        {
            LED_Light[surface][side_NUM[i]] = LED_Light[surface][side_NUM[i + 1]];
        }
        LED_Light[surface][side_NUM[7]] = temp;
    }
    TURN_COUNT++;
    if (TURN_COUNT == 12)
    {
        TURN_COUNT = 0;
    }
}

char command_turn_CE(const char *s)
{
    int i;

    for (i = 0; i < CE_LIST_COUNT; i++)
    {
        if (str_cmp_const(s, CE_LIST[i].name) == 0)
        {
            turn_CE(&CE_LIST[i]);
            if (i > 1 && i < CE_LIST_COUNT - 9)
            {
                total_number_of_moves++;
            }
            return 0;
        }
    }
    return -1;
}

// char str_cmp(char p1[], char *p2)
// {
// 	int i = 0;
// 	while (p1[i] != '\0')
// 	{
// 		if (p1[i] != *(p2 + i))
// 			return -1;
// 		i++;
// 	}
// 	if (*(p2 + i) == '\0')
// 		return 0;
// 	return -1;
//}

char str_cmp_const(const char p1[], char *p2)
{
    int i = 0;
    while (p1[i] != '\0')
    {
        if (p1[i] != *(p2 + i))
            return -1;
        i++;
    }
    if (*(p2 + i) == '\0')
        return 0;
    return -1;
}

void set_S(void)
{

    LED_Light[0][4] = state_CE.sp[0];
    LED_Light[1][4] = state_CE.sp[1];
    LED_Light[4][4] = state_CE.sp[2];
    LED_Light[3][4] = state_CE.sp[3];
    LED_Light[2][4] = state_CE.sp[4];
    LED_Light[5][4] = state_CE.sp[5];
}

void set_C(void)
{

    LED_Light[0][2] = LED_C[state_CE.cp[0]][state_CE.co[0]];
    LED_Light[0][0] = LED_C[state_CE.cp[1]][state_CE.co[1]];
    LED_Light[0][8] = LED_C[state_CE.cp[3]][state_CE.co[3]];
    LED_Light[0][6] = LED_C[state_CE.cp[2]][state_CE.co[2]];

    LED_Light[1][2] = LED_C[state_CE.cp[3]][(state_CE.co[3] + 2) % 3]; //x
    LED_Light[1][0] = LED_C[state_CE.cp[2]][(state_CE.co[2] + 1) % 3]; //y
    LED_Light[1][8] = LED_C[state_CE.cp[7]][(state_CE.co[7] + 1) % 3]; //x+4
    LED_Light[1][6] = LED_C[state_CE.cp[6]][(state_CE.co[6] + 2) % 3]; //y+4

    LED_Light[4][2] = LED_C[state_CE.cp[2]][(state_CE.co[2] + 2) % 3];
    LED_Light[4][0] = LED_C[state_CE.cp[1]][(state_CE.co[1] + 1) % 3];
    LED_Light[4][8] = LED_C[state_CE.cp[6]][(state_CE.co[6] + 1) % 3];
    LED_Light[4][6] = LED_C[state_CE.cp[5]][(state_CE.co[5] + 2) % 3];

    LED_Light[3][2] = LED_C[state_CE.cp[1]][(state_CE.co[1] + 2) % 3];
    LED_Light[3][0] = LED_C[state_CE.cp[0]][(state_CE.co[0] + 1) % 3];
    LED_Light[3][8] = LED_C[state_CE.cp[5]][(state_CE.co[5] + 1) % 3];
    LED_Light[3][6] = LED_C[state_CE.cp[4]][(state_CE.co[4] + 2) % 3];

    LED_Light[2][2] = LED_C[state_CE.cp[0]][(state_CE.co[0] + 2) % 3];
    LED_Light[2][0] = LED_C[state_CE.cp[3]][(state_CE.co[3] + 1) % 3];
    LED_Light[2][8] = LED_C[state_CE.cp[4]][(state_CE.co[4] + 1) % 3];
    LED_Light[2][6] = LED_C[state_CE.cp[7]][(state_CE.co[7] + 2) % 3];

    LED_Light[5][2] = LED_C[state_CE.cp[7]][state_CE.co[7]];
    LED_Light[5][0] = LED_C[state_CE.cp[6]][state_CE.co[6]];
    LED_Light[5][8] = LED_C[state_CE.cp[4]][state_CE.co[4]];
    LED_Light[5][6] = LED_C[state_CE.cp[5]][state_CE.co[5]];
}

void set_E(void)
{
    LED_Light[0][1] = LED_E[state_CE.ep[4]][state_CE.eo[4]];
    LED_Light[0][5] = LED_E[state_CE.ep[7]][state_CE.eo[7]];
    LED_Light[0][3] = LED_E[state_CE.ep[5]][state_CE.eo[5]];
    LED_Light[0][7] = LED_E[state_CE.ep[6]][state_CE.eo[6]];

    LED_Light[1][1] = LED_E[state_CE.ep[6]][(state_CE.eo[6] + 1) % 2];   //y+3
    LED_Light[1][5] = LED_E[state_CE.ep[3]][(state_CE.eo[3])];           //y
    LED_Light[1][3] = LED_E[state_CE.ep[2]][(state_CE.eo[2])];           //x
    LED_Light[1][7] = LED_E[state_CE.ep[10]][(state_CE.eo[10] + 1) % 2]; //x+8

    LED_Light[4][1] = LED_E[state_CE.ep[5]][(state_CE.eo[5] + 1) % 2];
    LED_Light[4][5] = LED_E[state_CE.ep[2]][(state_CE.eo[2] + 1) % 2];
    LED_Light[4][3] = LED_E[state_CE.ep[1]][(state_CE.eo[1] + 1) % 2];
    LED_Light[4][7] = LED_E[state_CE.ep[9]][(state_CE.eo[9] + 1) % 2];

    LED_Light[3][1] = LED_E[state_CE.ep[4]][(state_CE.eo[4] + 1) % 2];
    LED_Light[3][5] = LED_E[state_CE.ep[1]][(state_CE.eo[1])];
    LED_Light[3][3] = LED_E[state_CE.ep[0]][(state_CE.eo[0])];
    LED_Light[3][7] = LED_E[state_CE.ep[8]][(state_CE.eo[8] + 1) % 2];

    LED_Light[2][1] = LED_E[state_CE.ep[7]][(state_CE.eo[7] + 1) % 2];
    LED_Light[2][5] = LED_E[state_CE.ep[0]][(state_CE.eo[0] + 1) % 2];
    LED_Light[2][3] = LED_E[state_CE.ep[3]][(state_CE.eo[3] + 1) % 2];
    LED_Light[2][7] = LED_E[state_CE.ep[11]][(state_CE.eo[11] + 1) % 2];

    LED_Light[5][1] = LED_E[state_CE.ep[10]][state_CE.eo[10]];
    LED_Light[5][5] = LED_E[state_CE.ep[11]][state_CE.eo[11]];
    LED_Light[5][3] = LED_E[state_CE.ep[9]][state_CE.eo[9]];
    LED_Light[5][7] = LED_E[state_CE.ep[8]][state_CE.eo[8]];
}

void over_write_CE(const CE write_CE)
{
     int i;
     for (i = 0; i < 8; i++)
     {
         state_CE.co[i] = write_CE.co[i];
         state_CE.cp[i] = write_CE.cp[i];
     }
     for (i = 0; i < 12; i++)
     {
         state_CE.eo[i] = write_CE.eo[i];
         state_CE.ep[i] = write_CE.ep[i];
     }
     for (i = 0; i < 6; i++)
     {
         state_CE.sp[i] = write_CE.sp[i];
     }

}

void over_write_CE_from_A_to_B(const CE A,CE* B)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		B->co[i] = A.co[i];
		B->cp[i] = A.cp[i];
	}
	for (i = 0; i < 12; i++)
	{
		B->eo[i] = A.eo[i];
		B->ep[i] = A.ep[i];
	}
	for (i = 0; i < 6; i++)
	{
		B->sp[i] = A.sp[i];
	}
}

const CE deff_CE = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

CE state_CE = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE r_CE = {
    {0, 2, 6, 3, 4, 1, 5, 7},
    {0, 1, 2, 0, 0, 2, 1, 0},
    {0, 5, 9, 3, 4, 2, 6, 7, 8, 1, 10, 11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE u_CE = {
    {3, 0, 1, 2, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 7, 4, 5, 6, 8, 9, 10, 11},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE d_CE = {
    {0, 1, 2, 3, 5, 6, 7, 4},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 8},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE l_CE = {
    {4, 1, 2, 0, 7, 5, 6, 3},
    {2, 0, 0, 1, 1, 0, 0, 2},
    {11, 1, 2, 7, 4, 5, 6, 0, 8, 9, 10, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE f_CE = {
    {0, 1, 3, 7, 4, 5, 2, 6},
    {0, 0, 1, 2, 0, 0, 2, 1},
    {0, 1, 6, 10, 4, 5, 3, 7, 8, 9, 2, 11},
    {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 2, 3, 4, 5}};

const CE b_CE = {
    {1, 5, 2, 3, 0, 4, 6, 7},
    {1, 2, 0, 0, 2, 1, 0, 0},
    {4, 8, 2, 3, 1, 5, 6, 7, 0, 9, 10, 11},
    {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 2, 3, 4, 5}};

const CE m_CE = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 8, 5, 4, 7, 10, 9, 6, 11},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {3, 0, 2, 5, 4, 1}};

const CE s_CE = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 7, 6, 11, 8, 5, 10, 9},
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {4, 1, 0, 3, 5, 2}};

const CE e_CE = {
    {0, 1, 2, 3, 4, 5, 6, 7},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 4, 1, 2, 3, 5}};

const CE y_CE = {
    {3, 0, 1, 2, 7, 4, 5, 6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {3, 0, 1, 2, 7, 4, 5, 6, 11, 8, 9, 10},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 3, 4, 1, 5},
};

const CE x_CE = {
    {3, 2, 6, 7, 0, 1, 5, 4},
    {2, 1, 2, 1, 1, 2, 1, 2},
    {7, 5, 9, 11, 6, 2, 10, 3, 4, 1, 8, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 5, 2, 0, 4, 3},
};

const CE z_CE = {
    {4, 0, 3, 7, 5, 1, 2, 6},
    {1, 2, 1, 2, 2, 1, 2, 1},
    {8, 4, 6, 10, 0, 7, 3, 11, 1, 5, 2, 9},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {4, 1, 0, 3, 5, 2},
};
/*
const char LED_C[8][3] = {
    {white, orange, blue},
    {white, blue, red},
    {white, red, green},
    {white, green, orange},
    {yellow, blue, orange},
    {yellow, red, blue},
    {yellow, green, red},
    {yellow, orange, green},
};*/

const char LED_C[8][3] = {
    {white, blue, orange},
    {white, red, blue},
    {white, green, red},
    {white, orange, green},
    {yellow, orange, blue},
    {yellow, blue, red},
    {yellow, red, green},
    {yellow, green, orange},
};
const char LED_E[12][2] = {
    {blue, orange},
    {blue, red},
    {green, red},
    {green, orange},
    {white, blue},
    {white, red},
    {white, green},
    {white, orange},
    {yellow, blue},
    {yellow, red},
    {yellow, green},
    {yellow, orange},
};

const CE_LISTER CE_LIST[CE_LIST_COUNT] = {
    {&deff_CE, "deff", 0},
    {&state_CE, "state", 0},

    {&u_CE, "U", 1},
    {&d_CE, "D", 1},
    {&l_CE, "L", 1},
    {&r_CE, "R", 1},
    {&f_CE, "F", 1},
    {&b_CE, "B", 1},

    {&u_CE, "U'", 3},
    {&d_CE, "D'", 3},
    {&l_CE, "L'", 3},
    {&r_CE, "R'", 3},
    {&f_CE, "F'", 3},
    {&b_CE, "B'", 3},

    {&u_CE, "U2", 2},
    {&d_CE, "D2", 2},
    {&l_CE, "L2", 2},
    {&r_CE, "R2", 2},
    {&f_CE, "F2", 2},
    {&b_CE, "B2", 2},

    {&e_CE, "E", 1},
    {&s_CE, "S", 1},
    {&m_CE, "M", 1},

    {&e_CE, "E2", 2},
    {&s_CE, "S2", 2},
    {&m_CE, "M2", 2},

    {&e_CE, "E'", 3},
    {&s_CE, "S'", 3},
    {&m_CE, "M'", 3},

    {&x_CE, "X", 1},
    {&y_CE, "Y", 1},
    {&z_CE, "Z", 1},

    {&x_CE, "X'", 3},
    {&y_CE, "Y'", 3},
    {&z_CE, "Z'", 3},

    {&x_CE, "X2", 2},
    {&y_CE, "Y2", 2},
    {&z_CE, "Z2", 2},
};
