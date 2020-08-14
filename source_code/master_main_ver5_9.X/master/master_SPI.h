/*
SPI通信
*/
#ifndef _MASTER_SPI_H_
#define _MASTER_SPI_H_
#include <xc.h>
#include <htc.h>
#include "XTAL.h"
#include "sound.h"
//スレーブの決定用PIN
#define CS0 LATAbits.LATA0
#define CS1 LATAbits.LATA1
#define CS2 LATAbits.LATA2
#define CS3 LATAbits.LATA3
#define CS4 LATAbits.LATA4
#define CS5 LATAbits.LATA5

char SPIreadM(void);	//SPI受信
char SPI_readM_2(const char);	//値を渡したスレーブとのSPI受信
void SPI_M_ioport(void);//SPI通信用初期設定
void SPI_RET(void);//SPI通信残存データ複数回破棄
void SPI_RET_2(void); //SPI通信残存データ1度破棄
#endif