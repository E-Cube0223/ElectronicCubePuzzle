/*
 * File:   slave_SPI..c
 * Author: NAOYUKI
 *
 * Created on 2019/10/21, 17:42
 * 
 * PIC16f1827からsend_SPI_2に入れたデータをSPI割り込みで送信する。
 * 送信が行われるとSPI_FLAGが1になる
 * 
 * SPI通信開始前にSPI_S_ioport()の宣言が必要
 * 割り込み関数内にSPI_interrupt()を置くことで送信が実行される
 * 
 * 配線に関して参考可能
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

    SSP1STATbits.CKE = 0; //モード０
    SSP1CON1bits.CKP = 0;

    SSP1CON1bits.SSPEN = 1;
    SSP1CON1bits.SSPM = 0b0100;

    TRISBbits.TRISB1 = 1; //SDI入力
    TRISBbits.TRISB2 = 0; //SDO出力    
    TRISBbits.TRISB4 = 1; //SCK入力
    TRISBbits.TRISB5 = 1; //SS入力

    SSP1IF = 0; // ＳＰＩの割込みフラグを初期化する
    SSP1IE = 1; // ＳＰＩの割込みを許可する
    PEIE = 1; // 周辺装置割込みを許可する
    GIE = 1; // 全割込み処理を許可する
    //    SSP1BUF = 0;
}

/*
 * SPI送信データセット用関数
 * SPI送信可能状態になったら
 * 送信データをセットしフラグを下げる
 */
void SPI_send(char data) {
    while (SPI_FLAG == 0);//前の送信が終わるまで待機
    send_SPI_1 = data;//データセット
    SPI_FLAG = 0;//送信
    return;
}

/*
 * 割り込みSPI
 * 送信可能データは0~128
 * 1bit分のシフト操作を行ってから送信 
 * 通信を行うたびにSPI_FLAGに1をセット
 */
void SPI_interrupt(void) {
    if (PIR1bits.SSP1IF == 1) {
        if (SPI_FLAG==0) {//送信データがセットされてない場合は　受け取った値(0)をそのまま返す。 これでいける？？？
            send_SPI_1 = send_SPI_1 << 1;
            return_SPI = SSP1BUF;
            SSP1BUF = send_SPI_1;
            SPI_FLAG = 1;
        }
        PIR1bits.SSP1IF = 0;
    }
}
