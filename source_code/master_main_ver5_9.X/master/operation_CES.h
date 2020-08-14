/*
���[�r�b�N�L���[�u�̊�{����
�F�Ɩʂ̑Ή�
 0
4123
 5
�@��
��ΐԐ�
�@��
 */
#ifndef _OPERATION_CES_H_
#define _OPERATION_CES_H_

#define CE_LIST_start 2						   //CE_LIST��0,1��deff��state�Ȃ̂Ŋ�{��΂�
#define CE_LIST_COUNT (CE_LIST_start + 12 * 3) //CE_LIST�ő吔((deff+state)+��{12����*3)

//�e�F�̔ԍ�
#define white 0
#define green 1
#define red 2
#define blue 3
#define orange 4
#define yellow 5
#define no_color 6

typedef struct CE_2 {
    char cp[8]; //�R�[�i�[�p�[�c�̈ʒu
    char co[8]; //�R�[�i�[�p�[�c�̂˂���
    char ep[12]; //�G�b�W�p�[�c�̈ʒu
    char eo[12]; //�G�b�W�p�[�c�̂˂���
    char sp[6]; //�Z���^�[�p�[�c
} CE;


//�e������s�����ꍇ�̍\����
//�w�b�_�t�@�C���̕ϐ��錾�ɂ�extern���K�v
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

//LED�o�͗p�z��
extern char LED_Light[6][9];

//state_CE�����ŏ㏑��

void over_write_CE_from_A_to_B(const CE , CE *);
void over_write_CE(const CE);
extern unsigned int total_number_of_moves;

//����p�\���̂��܂Ƃ߂邽��

typedef struct enm {
    const CE(*DATA);
    char *name;
    char CE_count;

} CE_LISTER;

extern const CE_LISTER CE_LIST[CE_LIST_COUNT];

//�R�[�i�[�p�[�c�̔z�F�萔
extern const char LED_C[8][3];

//�G�b�W�p�[�c�̔z�F�萔
extern const char LED_E[12][2];

//p1,p2�̕������r
char str_cmp_const(const char p1[], char *p2);

void set_C(void); //state_CE�̃R�[�i�[�p�[�c�̐F��LED�����p�z��ɑ��
void set_E(void); //state_CE�̃G�b�W�p�[�c�̐F��LED�����p�z��ɑ��
void set_S(void); //state_CE�̃Z���^�[�[�p�[�c�̐F��LED�����p�z��ɑ��
void set_CES(void); //state_CE�̐F��LED�����p�z��ɑ��

char command_turn_CE(const char *s); //������ɂ���������state_CE�̉�]���s��

typedef struct TURN_NUM2 {
    const char MEN_SURFASE[4];
    const char POINT_NUM[12];
} TURN_NUM;

extern char TURN_COUNT;
void command_turn_ARRAY(const char *s);
void ARRAY_SIDE_TURN(const char surface);
void ARRAY_LINE_TURN(const char MOVE_LOW, const TURN_NUM MEN_NUM_1);

void turn_CE(const CE_LISTER *); //CE_LISTER����������state_CE�̉�]���s��

#endif
