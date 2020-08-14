/*
ルービックキューブの基本操作
色と面の対応
 0
4123
 5
　白
橙緑赤青
　黄
 */
#ifndef _OPERATION_CES_H_
#define _OPERATION_CES_H_

#define CE_LIST_start 2						   //CE_LISTの0,1はdeffとstateなので基本飛ばす
#define CE_LIST_COUNT (CE_LIST_start + 12 * 3) //CE_LIST最大数((deff+state)+基本12操作*3)

//各色の番号
#define white 0
#define green 1
#define red 2
#define blue 3
#define orange 4
#define yellow 5
#define no_color 6

typedef struct CE_2 {
    char cp[8]; //コーナーパーツの位置
    char co[8]; //コーナーパーツのねじれ
    char ep[12]; //エッジパーツの位置
    char eo[12]; //エッジパーツのねじれ
    char sp[6]; //センターパーツ
} CE;


//各動作を行った場合の構造体
//ヘッダファイルの変数宣言にはexternが必要
extern CE state_CE;
extern const CE deff_CE;
extern const CE r_CE;
extern const CE u_CE;
extern const CE d_CE;
extern const CE l_CE;
extern const CE f_CE;
extern const CE b_CE;
extern const CE m_CE;
extern const CE s_CE;
extern const CE e_CE;
extern const CE y_CE;
extern const CE x_CE;
extern const CE z_CE;

//LED出力用配列
extern char LED_Light[6][9];

//state_CEを代入で上書き

void over_write_CE_from_A_to_B(const CE , CE *);
void over_write_CE(const CE);
extern unsigned int total_number_of_moves;

//動作用構造体をまとめるため

typedef struct enm {
    const CE(*DATA);
    char *name;
    char CE_count;

} CE_LISTER;

extern const CE_LISTER CE_LIST[CE_LIST_COUNT];

//コーナーパーツの配色定数
extern const char LED_C[8][3];

//エッジパーツの配色定数
extern const char LED_E[12][2];

//p1,p2の文字列比較
char str_cmp_const(const char p1[], char *p2);

void set_C(void); //state_CEのコーナーパーツの色をLED発光用配列に代入
void set_E(void); //state_CEのエッジパーツの色をLED発光用配列に代入
void set_S(void); //state_CEのセンターーパーツの色をLED発光用配列に代入
void set_CES(void); //state_CEの色をLED発光用配列に代入

char command_turn_CE(const char *s); //文字列にしたがってstate_CEの回転を行う

typedef struct TURN_NUM2 {
    const char MEN_SURFASE[4];
    const char POINT_NUM[12];
} TURN_NUM;

extern char TURN_COUNT;
void command_turn_ARRAY(const char *s);
void ARRAY_SIDE_TURN(const char surface);
void ARRAY_LINE_TURN(const char MOVE_LOW, const TURN_NUM MEN_NUM_1);

void turn_CE(const CE_LISTER *); //CE_LISTERしたがってstate_CEの回転を行う

#endif
