
#ifndef _MASTER_SPI_H_
#define _MASTER_SPI_H_
#include <xc.h>
#include <htc.h>
#include "XTAL.h"
#include "sound.h"
//�X���[�u�̌���pPIN
#define CS0 LATAbits.LATA0
#define CS1 LATAbits.LATA1
#define CS2 LATAbits.LATA2
#define CS3 LATAbits.LATA3
#define CS4 LATAbits.LATA4
#define CS5 LATAbits.LATA5

char SPIreadM(void);	//SPI��M
char SPI_readM_2(const char);	//�l��n�����X���[�u�Ƃ�SPI��M
void SPI_M_ioport(void);//SPI�ʐM�p�����ݒ�
void SPI_RET(void);
void SPI_RET_2(void);

#endif