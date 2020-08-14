/*
 * LEDキューブ　各面用マイコン(PIC16F1827)プログラム
 * リードスイッチが特定の順番で反応したらSPI通信で操作に対応したデータを送信する。
 * 一定時間(0.5s)リードスイッチが反応しなければ入力情報はリセットされる。
 * PIC_NUMに面番号を入れてね。
 * 
 * スイッチ配置と操作番号
 *               1
 *               →
 * 　RSW1：RB0          RSW3：RB6
 *               ←
 *               5
 *    4↑ ↓8           6↑ ↓2
 *               7
 *               →
 * 　RSW2：RB3          RSW4：RB7
 *               ←
 *               3
 * 
 * 特殊操作:9
 * 
 */

#include <xc.h>

#include "slave_SPI.h"

// CONFIG1
#pragma config FOSC = INTOSC   // 内部ｸﾛｯｸを使う(INTOSC)
#pragma config WDTE = OFF  // ｳｵｯﾁﾄﾞｯｸﾞﾀｲﾏｰを使わない(OFF)
#pragma config PWRTE = ON  // パワーアップタオイマーを有効にする(ON)
#pragma config MCLRE = OFF // 外部ﾘｾｯﾄ信号は使用せずにﾃﾞｼﾞﾀﾙ入力(RA3)ﾋﾟﾝとする(OFF)
#pragma config CP = OFF	// ﾌﾟﾛｸﾞﾗﾑﾒﾓﾘｰを保護しない(OFF)
#pragma config CPD = OFF   // ﾃﾞｰﾀﾒﾓﾘｰを保護しない(OFF)
#pragma config BOREN = ON  // 電源電圧降下常時監視機能ON(ON)
//#pragma config CLKOUTEN = OFF // CLKOUTﾋﾟﾝをRA4ﾋﾟﾝで使用する(OFF)
#pragma config IESO = OFF  // 外部・内部ｸﾛｯｸの切替えでの起動はなし(OFF)
#pragma config FCMEN = OFF // 外部ｸﾛｯｸ監視しない(OFF)
// CONFIG2
#pragma config WRT = OFF   // Flashﾒﾓﾘｰを保護しない(OFF)
#pragma config PLLEN = ON // 動作クロックを32MHzで動作させる(ON)
#pragma config STVREN = ON // スタックがオーバフローやアンダーフローしたらリセットをする(ON)
#pragma config BORV = HI   // 電源電圧降下常時監視電圧(2.5V)設定(HI)
#pragma config LVP = ON	// 低電圧プログラミング機能使用しない(OFF)

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

#define TMR0_set 0xFF-125//TMR0設定値


void ioport(void); // I/Oポート設定関数のプロトタイプ
void wait_ms(unsigned int time); //time ms待機　__delay_ms()は定数しか入れられないため、作成。

unsigned char LED_ARRAY[3]; //LEDカラーパターン配列
unsigned char prev = 0; //ひとつ前の入力
unsigned char SPfunc_flag = 0; //特殊操作フラグ
unsigned int TMR0_count = 0; //タイマカウンタ
unsigned char TMR0_mode = 0; //タイマモード　1:0.5秒ごとに入力情報リセット　0:TMR0_countをインクリメントするだけ

void main(void) {

    ioport();
    SPI_S_ioport();

    while (1) {
        if (!RSW1_PORT) {
            wait_ms(10);
            while (!RSW1_PORT);
            wait_ms(10);
            if (prev == 0) {//ひとつ前の入力情報なければ
                prev = RSW1; //現在の入力情報を入れる
            } else if (prev == RSW1) {
                if (SPfunc_flag) {//特殊操作フラグ立ってれば
                    SPI_send(FUNC_SP);//特殊操作データ送信
                    SPfunc_flag--; //フラグ下げる
                    prev = 0; //入力情報リセット
                } else {
                    SPfunc_flag++; //フラグ上げる
                }
            } else {
                switch (prev) { //各操作を行う
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
                TMR0 = TMR0_set; // タイマー0の初期化
                TMR0_count = 0;
                TMR0_mode = 1;
                TMR0IE = 1; // タイマー0割込み(T0IE)を許可する
                //GIE = 1; // 全割込み処理を許可する
            } else if (prev == 0) {
                TMR0IE = 0; // タイマー0割込み(T0IE)を拒否する
                //GIE = 0; // 全割込み処理を拒否する
            }
        }
    }
}

void interrupt isr(void) {
    SPI_interrupt();
    if (TMR0IF == 1) { // タイマー0の割込み発生か？ 1ms周期
        TMR0 = TMR0_set; // タイマー0の初期化
        TMR0_count++; // 割込み発生の回数をカウントする
        TMR0IF = 0; // タイマー0割込フラグをリセット
        if (TMR0_mode) {
            if (TMR0_count >= 500) { // 割込みを500回カウントすると0.5s
                TMR0_count = 0;
                prev = 0; //各入力情報リセット
                SPfunc_flag = 0;
            }
        }
    }
}

void ioport(void) // I/Oポート設定関数
{

    OSCCON = 0b01110000; // 内部クロック32Mhz
    ANSELB = 0b00000000; // 全てデジタル入力
    TRISB = 0b11001001; // RB7・6・3・0を入力に設定
    PORTB = 0b00000000; // 出力ピンの初期化

    WPUB = 0b11001001; // 入力PINをプルアップ
    nWPUEN = 0; //プルアップ有効化

    OPTION_REG = 0b00000101; // Focs/4 TIMER0を使用、ﾌﾟﾘｽｹｰﾗｶｳﾝﾄ値 1:64 1回＝8us
    TMR0 = TMR0_set; // タイマー0の初期化 125回割込みで信号送信 (1ms)
    TMR0IF = 0; // タイマー0割込フラグ(T0IF)を0にする
    TMR0_count = 0; // 割込み発生の回数カウンターを0にする
    TMR0IE = 0; // タイマー0割込み(T0IE)を拒否する
    GIE = 1; // 全割込み処理を許可する
}

void wait_ms(unsigned int time) {
    OPTION_REG = 0b00000101; // Focs/4 TIMER0を使用、ﾌﾟﾘｽｹｰﾗｶｳﾝﾄ値 1:64 1回＝8us
    TMR0 = TMR0_set; // タイマー0の初期化 125回割込みで信号送信 (1ms)
    TMR0IF = 0; // タイマー0割込フラグ(T0IF)を0にする
    TMR0_count = 0; // 割込み発生の回数カウンターを0にする
    TMR0_mode = 0;
    TMR0IE = 1; // タイマー0割込み(T0IE)を許可する
    //GIE = 1; // 全割込み処理を許可する
    while (TMR0_count < time);
    TMR0IE = 0; // タイマー0割込み(T0IE)を拒否する
    //GIE = 0; // 全割込み処理を拒否する
}