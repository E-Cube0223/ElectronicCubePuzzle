/*
�A�j���[�V�����{�����񓯂�����̕`�ʂ��s��Ȃ���]�A�j���[�V����

*/
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include "SerialLED_PIC18F25K22.h"
#include "CES_SPI_support.h"
#include "XTAL.h"
#include "operation_CES.h"
#include "solution_CES.h"
#define SHUFFLE_MAX 20

//�A�j���[�V����
char animation_1(const char);
char animation_2(void);
char animation_3(char, char);
char animation_4(unsigned int);

void set_all_LED_ARRAY(char);//�P�F����

void shuffle_state_CE(const unsigned int seed_number); //SHUFFLE_MAX�񂾂������_���ɉ�]���s��

void convert_ROTtoLED(void); //�΋������p�ϐ����琳�������p�ϐ��Ɉړ�

//��]�A�j���[�V����
void command_turn_ARRAY_2(const char *s);
void command_turn_ARRAY_2_2(const char *s);
void command_turn_ARRAY_2_3(const char *s1, const char *s2, const char *s3);

//�����񓯂�����̕`�ʂ��s��Ȃ���]�A�j���[�V����
char past_command_3 = 0;
char past_command_count_3 = 0;
void command_turn_ARRAY_3(const char *s);
void command_turn_ARRAY_3_end(void);

extern char mode_cube_end;//��������s�����ǂ���

extern char ARRAY_skip_CS;//������͂�����I�Ɏ󂯕t����ʂ̋L�^

#endif
