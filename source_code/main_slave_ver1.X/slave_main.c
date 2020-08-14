/*
 * LED�L���[�u�@�e�ʗp�}�C�R��(PIC16F1827)�v���O����
 * ���[�h�X�C�b�`������̏��ԂŔ���������SPI�ʐM�ő���ɑΉ������f�[�^�𑗐M����B
 * ��莞��(0.5s)���[�h�X�C�b�`���������Ȃ���Γ��͏��̓��Z�b�g�����B
 * PIC_NUM�ɖʔԍ������ĂˁB
 * 
 * �X�C�b�`�z�u�Ƒ���ԍ�
 *               1
 *               ��
 * �@RSW1�FRB0          RSW3�FRB6
 *               ��
 *               5
 *    4�� ��8           6�� ��2
 *               7
 *               ��
 * �@RSW2�FRB3          RSW4�FRB7
 *               ��
 *               3
 * 
 * ���ꑀ��:9
 * 
 */

#include <xc.h>

#include "slave_SPI.h"

// CONFIG1
#pragma config FOSC = INTOSC   // �����ۯ����g��(INTOSC)
#pragma config WDTE = OFF  // �����ޯ����ϰ���g��Ȃ�(OFF)
#pragma config PWRTE = ON  // �p���[�A�b�v�^�I�C�}�[��L���ɂ���(ON)
#pragma config MCLRE = OFF // �O��ؾ�ĐM���͎g�p�������޼��ٓ���(RA3)��݂Ƃ���(OFF)
#pragma config CP = OFF	// ��۸�����ذ��ی삵�Ȃ�(OFF)
#pragma config CPD = OFF   // �ް���ذ��ی삵�Ȃ�(OFF)
#pragma config BOREN = ON  // �d���d���~���펞�Ď��@�\ON(ON)
//#pragma config CLKOUTEN = OFF // CLKOUT��݂�RA4��݂Ŏg�p����(OFF)
#pragma config IESO = OFF  // �O���E�����ۯ��̐ؑւ��ł̋N���͂Ȃ�(OFF)
#pragma config FCMEN = OFF // �O���ۯ��Ď����Ȃ�(OFF)
// CONFIG2
#pragma config WRT = OFF   // Flash��ذ��ی삵�Ȃ�(OFF)
#pragma config PLLEN = ON // ����N���b�N��32MHz�œ��삳����(ON)
#pragma config STVREN = ON // �X�^�b�N���I�[�o�t���[��A���_�[�t���[�����烊�Z�b�g������(ON)
#pragma config BORV = HI   // �d���d���~���펞�Ď��d��(2.5V)�ݒ�(HI)
#pragma config LVP = ON	// ��d���v���O���~���O�@�\�g�p���Ȃ�(OFF)

#define _XTAL_FREQ 32000000

#define RSW1_PORT RB0
#define RSW2_PORT RB3
#define RSW3_PORT RB6
#define RSW4_PORT RB7

#define RSW1 0x01
#define RSW2 0x02
#define RSW3 0x03
#define RSW4 0x04


#define FUNC_1to2 8
#define FUNC_1to3 1
#define FUNC_2to1 4
#define FUNC_2to4 7
#define FUNC_3to1 5
#define FUNC_3to4 2
#define FUNC_4to3 6
#define FUNC_4to2 3
#define FUNC_SP 9

#define TMR0_set 0xFF-125//TMR0�ݒ�l


void ioport(void); // I/O�|�[�g�ݒ�֐��̃v���g�^�C�v
void wait_ms(unsigned int time); //time ms�ҋ@�@__delay_ms()�͒萔����������Ȃ����߁A�쐬�B

unsigned char LED_ARRAY[3]; //LED�J���[�p�^�[���z��
unsigned char prev = 0; //�ЂƂO�̓���
unsigned char SPfunc_flag = 0; //���ꑀ��t���O
unsigned int TMR0_count = 0; //�^�C�}�J�E���^
unsigned char TMR0_mode = 0; //�^�C�}���[�h�@1:0.5�b���Ƃɓ��͏�񃊃Z�b�g�@0:TMR0_count���C���N�������g���邾��

void main(void) {

    ioport();
    SPI_S_ioport();

    while (1) {
        if (!RSW1_PORT) {
            wait_ms(10);
            while (!RSW1_PORT);
            wait_ms(10);
            if (prev == 0) {//�ЂƂO�̓��͏��Ȃ����
                prev = RSW1; //���݂̓��͏�������
            } else if (prev == RSW1) {
                if (SPfunc_flag) {//���ꑀ��t���O�����Ă��
                    SPI_send(FUNC_SP);//���ꑀ��f�[�^���M
                    SPfunc_flag--; //�t���O������
                    prev = 0; //���͏�񃊃Z�b�g
                } else {
                    SPfunc_flag++; //�t���O�グ��
                }
            } else {
                switch (prev) { //�e������s��
                    case RSW2:
                        SPI_send(FUNC_2to1);
                        break;
                    case RSW3:
                        SPI_send(FUNC_3to1);
                        break;
                    default:
                        break;
                }
                prev = 0;
                SPfunc_flag = 0;
            }
        } else if (!RSW2_PORT) {
            wait_ms(10);
            while (!RSW2_PORT);
            wait_ms(10);
            if (prev == 0) {
                prev = RSW2;
            } else if (prev == RSW2) {
                if (SPfunc_flag) {
                    SPI_send(FUNC_SP);
                    SPfunc_flag--;
                    prev = 0;
                } else {
                    SPfunc_flag++;
                }
            } else {
                switch (prev) {
                    case RSW1:
                        SPI_send(FUNC_1to2);
                        break;
                    case RSW4:
                        SPI_send(FUNC_4to2);
                        break;
                    default:
                        break;
                }
                prev = 0;
                SPfunc_flag = 0;
            }
        } else if (!RSW3_PORT) {
            wait_ms(10);
            while (!RSW3_PORT);
            wait_ms(10);
            if (prev == 0) {
                prev = RSW3;
            } else if (prev == RSW3) {
                if (SPfunc_flag) {
                    SPI_send(FUNC_SP);
                    SPfunc_flag--;
                    prev = 0;
                } else {
                    SPfunc_flag++;
                }
            } else {
                switch (prev) {
                    case RSW1:
                        SPI_send(FUNC_1to3);
                        break;
                    case RSW4:
                        SPI_send(FUNC_4to3);
                        break;
                    default:
                        break;
                }
                prev = 0;
                SPfunc_flag = 0;
            }
        } else if (!RSW4_PORT) {
            wait_ms(10);
            while (!RSW4_PORT);
            wait_ms(10);
            if (prev == 0) {
                prev = RSW4;
            } else if (prev == RSW4) {
                if (SPfunc_flag) {
                    SPI_send(FUNC_SP);
                    SPfunc_flag--;
                    prev = 0;
                } else {
                    SPfunc_flag++;
                }
            } else {
                switch (prev) {
                    case RSW2:
                        SPI_send(FUNC_2to4);
                        break;
                    case RSW3:
                        SPI_send(FUNC_3to4);
                        break;
                    default:
                        break;
                }
                prev = 0;
                SPfunc_flag = 0;
            }

        } else {
            if (TMR0IE == 0 && prev != 0) {
                TMR0 = TMR0_set; // �^�C�}�[0�̏�����
                TMR0_count = 0;
                TMR0_mode = 1;
                TMR0IE = 1; // �^�C�}�[0������(T0IE)��������
                //GIE = 1; // �S�����ݏ�����������
            } else if (prev == 0) {
                TMR0IE = 0; // �^�C�}�[0������(T0IE)�����ۂ���
                //GIE = 0; // �S�����ݏ��������ۂ���
            }
        }
    }
}

void interrupt isr(void) {
    SPI_interrupt();
    if (TMR0IF == 1) { // �^�C�}�[0�̊����ݔ������H 1ms����
        TMR0 = TMR0_set; // �^�C�}�[0�̏�����
        TMR0_count++; // �����ݔ����̉񐔂��J�E���g����
        TMR0IF = 0; // �^�C�}�[0�����t���O�����Z�b�g
        if (TMR0_mode) {
            if (TMR0_count >= 500) { // �����݂�500��J�E���g�����0.5s
                TMR0_count = 0;
                prev = 0; //�e���͏�񃊃Z�b�g
                SPfunc_flag = 0;
            }
        }
    }
}

void ioport(void) // I/O�|�[�g�ݒ�֐�
{

    OSCCON = 0b01110000; // �����N���b�N32Mhz
    ANSELB = 0b00000000; // �S�ăf�W�^������
    TRISB = 0b11001001; // RB7�E6�E3�E0����͂ɐݒ�
    PORTB = 0b00000000; // �o�̓s���̏�����

    WPUB = 0b11001001; // ����PIN���v���A�b�v
    nWPUEN = 0; //�v���A�b�v�L����

    OPTION_REG = 0b00000101; // Focs/4 TIMER0���g�p�A��ؽ��׶��Ēl 1:64 1��8us
    TMR0 = TMR0_set; // �^�C�}�[0�̏����� 125�񊄍��݂ŐM�����M (1ms)
    TMR0IF = 0; // �^�C�}�[0�����t���O(T0IF)��0�ɂ���
    TMR0_count = 0; // �����ݔ����̉񐔃J�E���^�[��0�ɂ���
    TMR0IE = 0; // �^�C�}�[0������(T0IE)�����ۂ���
    GIE = 1; // �S�����ݏ�����������
}

void wait_ms(unsigned int time) {
    OPTION_REG = 0b00000101; // Focs/4 TIMER0���g�p�A��ؽ��׶��Ēl 1:64 1��8us
    TMR0 = TMR0_set; // �^�C�}�[0�̏����� 125�񊄍��݂ŐM�����M (1ms)
    TMR0IF = 0; // �^�C�}�[0�����t���O(T0IF)��0�ɂ���
    TMR0_count = 0; // �����ݔ����̉񐔃J�E���^�[��0�ɂ���
    TMR0_mode = 0;
    TMR0IE = 1; // �^�C�}�[0������(T0IE)��������
    //GIE = 1; // �S�����ݏ�����������
    while (TMR0_count < time);
    TMR0IE = 0; // �^�C�}�[0������(T0IE)�����ۂ���
    //GIE = 0; // �S�����ݏ��������ۂ���
}