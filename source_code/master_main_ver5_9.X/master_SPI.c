/*
 * File:   master_SPI.c
 * Author: NAOYUKI
 *
 * Created on 2019/10/21, 18:14
 */

#include "master_SPI.h"

/*
 * SPI�ʐM�ł̎�M
 * SSPIN�̑���͊֐����ōs��Ȃ�
 * ��M�f�[�^��1bit�������V�t�g������s��
 */
char SPIreadM(void) {
    char dumy;
    //CS0 = 0; //CS Low
    //SSP1CON1bits.WCOL = 0;
    //   dumy = SSP1BUF; //�_�~�[�f�[�^
    SSP1BUF = 0; //�f�[�^���M
    while (!SSP1STATbits.BF)
        ; //�f�[�^��M����
    //CS0 = 1; //CS High
    return ((SSP1BUF >> 1)); //�f�[�^�擾
}

/*
 * SPI�ʐM�ł̎�M
 * SSPIN�̑���͊֐����ōs��
 * �ڍׂ�SPI_readM()
 */
char SPI_readM_2(const char csPIN) {
    int i = 0;
    char data;
    for (i = 0; i < 2; i++) { //�X���[�u�I��
        switch (csPIN) {
            case 0:
                CS0 = i;
                break;
            case 1:
                CS1 = i;
                break;
            case 2:
                CS2 = i;
                break;
            case 3:
                CS3 = i;
                break;
            case 4:
                CS4 = i;
                break;
            case 5:
                CS5 = i;
                break;
        }
        if (i == 0)
            data = SPIreadM(); //�f�[�^��M
    }
    return data;
}

void SPI_M_ioport(void) {
    //    SSP1BUF = 0;
    SSP1STATbits.SMP = 0;
    SSP1STATbits.CKE = 0;
    SSP1CON1bits.SSPEN = 1;
    SSP1CON1bits.CKP = 0;
    SSP1CON1bits.SSPM = 0b0000;

    SSP1CON1 = 0b00100001; // �N���b�N�ɐ���LOW�@�}�X�^���[�h��FOSC/16�̃N���b�N�ɐݒ�
    SSP1STAT = 0b00000000; // �N���b�N�ʑ��͂O�A�A�C�h��(0V)���A�N�e�B�u(5V)���Ƀf�[�^���M

    TRISCbits.TRISC4 = 1; //SDI����
    TRISCbits.TRISC5 = 0; //SDO�o��
    TRISCbits.TRISC3 = 0; //SCK�o��

    //�SCS�pPIN�o��
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;

    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC5 = 0;

    //CS�𖢑I����Ԃ�
    CS0 = 1;
    CS1 = 1;
    CS2 = 1;
    CS3 = 1;
    CS4 = 1;
    CS5 = 1;
}

void SPI_RET(void) {
    for (char i = 0; i < 10; i++) {
        SPI_RET_2();
        __delay_ms(50);
    }
}

void SPI_RET_2(void) {
    for (char j = 0; j < 6; j++) {
        while (SPI_readM_2(j) != 0);
    }
}
