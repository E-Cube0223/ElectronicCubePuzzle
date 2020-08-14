/*
EEROM�ǂݏ����p
*/
#ifndef EEROM_WR_H
#define	EEROM_WR_H
#include "operation_CES.h"
#include <htc.h>
#include <xc.h> 

#define EEROM_DEF_FLAG_ADDRESS 0
#define EEROM_SAVE_FLAG_ADDRESS 1
#define EEROM_GAME_FLAG_ADDRESS 2
#define EEROM_DEF_START_ADDRESS 3
#define EEROM_SAVE_START_ADDRESS 49

#define GAME_FLAG_ON 1
#define GAME_FLAG_OFF 0

void EEROM_WR_ioport(void);//�N�����̏����z��̏�����

//�d�����؂ꂽ���̑΍�ɑ��삲�ƂɃf�[�^�ۑ�
void EEROM_R_DEFF(void);   //state_CE�ɓǂݍ���
void EEROM_W_DEFF(void); //state_CE�ۑ�

void DATAEE_WriteByte(unsigned char bAdd, unsigned char bData);//1byte������
unsigned char DATAEE_ReadByte(unsigned char bAdd);//1Byte�ǂݍ���
extern char game_flag;
extern CE save_CE;

void EEROM_R_SAVE(void); //state_CE�ɕۑ��p�f�[�^�ǂݍ���
void EEROM_W_SAVE(void); //state_CE��ۑ��p�f�[�^�ɕۑ�

void EEROM_GAME_ON(void);//GAME_FLAG_ON

void EEROM_GAME_OFF(void); //GAME_FLAG_OFF

#endif	

