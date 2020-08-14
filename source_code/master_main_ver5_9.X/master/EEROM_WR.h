/*
EEROM読み書き用
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

void EEROM_WR_ioport(void);//起動時の所持配列の初期化

//電源が切れた時の対策に操作ごとにデータ保存
void EEROM_R_DEFF(void);   //state_CEに読み込み
void EEROM_W_DEFF(void); //state_CE保存

void DATAEE_WriteByte(unsigned char bAdd, unsigned char bData);//1byte書込み
unsigned char DATAEE_ReadByte(unsigned char bAdd);//1Byte読み込み
extern char game_flag;
extern CE save_CE;

void EEROM_R_SAVE(void); //state_CEに保存用データ読み込み
void EEROM_W_SAVE(void); //state_CEを保存用データに保存

void EEROM_GAME_ON(void);//GAME_FLAG_ON

void EEROM_GAME_OFF(void); //GAME_FLAG_OFF

#endif	

