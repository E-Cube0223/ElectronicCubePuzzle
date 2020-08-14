/*
 * File:   slave_SPI..c
 * Author: NAOYUKI
 *
 * Created on 2019/10/21, 17:42
 * 
 * PIC16f1827����send_SPI_2�ɓ��ꂽ�f�[�^��SPI���荞�݂ő��M����B
 * ���M���s�����SPI_FLAG��1�ɂȂ�
 * 
 * SPI�ʐM�J�n�O��SPI_S_ioport()�̐錾���K�v
 * ���荞�݊֐�����SPI_interrupt()��u�����Ƃő��M�����s�����
 * 
 * �z���Ɋւ��ĎQ�l�\
 * http://zattouka.net/GarageHouse/micon/SPI/SPI.htm
 */


#include "slave_SPI.h"

char SPI_FLAG = 1;
char send_SPI_1 = 0;
char return_SPI;

void SPI_S_ioport(void) {

    SDO1SEL = 0; //SDO1=RB2
    SS1SEL = 0; //SS1=RB5

    SSP1STATbits.SMP = 0;

    SSP1STATbits.CKE = 0; //���[�h�O
    SSP1CON1bits.CKP = 0;

    SSP1CON1bits.SSPEN = 1;
    SSP1CON1bits.SSPM = 0b0100;

    TRISBbits.TRISB1 = 1; //SDI����
    TRISBbits.TRISB2 = 0; //SDO�o��    
    TRISBbits.TRISB4 = 1; //SCK����
    TRISBbits.TRISB5 = 1; //SS����

    SSP1IF = 0; // �r�o�h�̊����݃t���O������������
    SSP1IE = 1; // �r�o�h�̊����݂�������
    PEIE = 1; // ���ӑ��u�����݂�������
    GIE = 1; // �S�����ݏ�����������
    //    SSP1BUF = 0;
}

/*
 * SPI���M�f�[�^�Z�b�g�p�֐�
 * SPI���M�\��ԂɂȂ�����
 * ���M�f�[�^���Z�b�g���t���O��������
 */
void SPI_send(char data) {
    while (SPI_FLAG == 0);//�O�̑��M���I���܂őҋ@
    send_SPI_1 = data;//�f�[�^�Z�b�g
    SPI_FLAG = 0;//���M
    return;
}

/*
 * ���荞��SPI
 * ���M�\�f�[�^��0~128
 * 1bit���̃V�t�g������s���Ă��瑗�M 
 * �ʐM���s�����т�SPI_FLAG��1���Z�b�g
 */
void SPI_interrupt(void) {
    if (PIR1bits.SSP1IF == 1) {
        if (SPI_FLAG==0) {//���M�f�[�^���Z�b�g����ĂȂ��ꍇ�́@�󂯎�����l(0)�����̂܂ܕԂ��B ����ł�����H�H�H
            send_SPI_1 = send_SPI_1 << 1;
            return_SPI = SSP1BUF;
            SSP1BUF = send_SPI_1;
            SPI_FLAG = 1;
        }
        PIR1bits.SSP1IF = 0;
    }
}
