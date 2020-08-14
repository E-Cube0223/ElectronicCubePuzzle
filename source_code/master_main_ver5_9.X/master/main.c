#include "XTAL.h"
#include <xc.h>
#include <htc.h>
#include <stdio.h>
#include "operation_CES.h"
#include "master_SPI.h"
#include "SerialLED_PIC18F25K22.h"
#include "CES_SPI_support.h"
#include "sound.h"
#include "EEROM_WR.h"
#include "animation.h"
#include "solution_CES.h"
#include "IDA_CES.h"

// CONFIG1H
#pragma config FOSC = INTIO67 // Oscillator Selection bits (Internal oscillator block)
#pragma config PLLCFG = OFF   // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON  // Primary clock enable bit (Primary clock enabled)
#pragma config FCMEN = OFF    // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF     // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = ON   // Brown-out Reset Enable bits (Brown-out Reset enabled and controlled by software (SBOREN is enabled))
#pragma config BORV = 190   // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF   // Watchdog Timer Enable bits (Watch dog timer is always disabled. SWDTEN has no effect.)
#pragma config WDTPS = 32768 // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1 // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON     // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5 // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON     // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0  // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTB5  // ECCP2 B output mux bit (P2B is on RB5)
#pragma config MCLRE = EXTMCLR // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON    // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

void ioport(void);

unsigned char LED_ARRAY[LED_ARRAY_X][LED_ARRAY_Y]; //LEDカラーパターン配列
unsigned char POWER = 0;                           //LED輝度

__EEPROM_DATA(0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF); //一つ目をFFに初期化することで全データが初期化する必要があることを表す

char Special_input_0 = 0;
void Special_input(char SS);

// メインの処理
unsigned int rand_seed = 0;
signed char GET_COMMAND = 0;

char if_game_end(void);

void main(void)
{
    // クロックソース INTOSC 16MHz HF
    OSCCON = 0b01110000;

    //PLLEN = 0;      // 16HHz
    PLLEN = 1; // 64MHz

    ioport();
    SPI_M_ioport();
    EEROM_WR_ioport();

    //LED発光パターン初期設定
    set_all_LED_ARRAY(no_color);
    POWER = 200;
    LED_RET(); //ごみを出すためのリセットコード

    set_CES();
    convert_ROTtoLED();
    OUT_LED_ARRAY(LED_ARRAY, POWER);

    SPI_RET();

    char EEROM_FLAG = 0;
    
    while (1)
    {
        rand_seed++;
        if (rand_seed > 65533)
            rand_seed = 0;

        EEROM_FLAG = 0;
        for (char i = 0; i < 6; i++)
        {
            char SPI_DATA = SPI_readM_2(i);
            GET_COMMAND = SPI_D2S(i, SPI_DATA);
            if (GET_COMMAND != 0)
            {
                re1();
                EEROM_FLAG = 1;
            }
            if (GET_COMMAND == 100)
            {
                for (char q = 0; q < 9; q++)
                    fa1();
                Special_input(i);
            }
            else if (GET_COMMAND == -2)
            {
                //SPI通信で0~13以外のデータがあった場合
            }
            else if (GET_COMMAND != 0)
            {
                command_turn_CE(CE_LIST[GET_COMMAND].name);
                for (int i = 0; i < 3; i++)
                {
                    command_turn_ARRAY(CE_LIST[GET_COMMAND].name);
                    convert_ROTtoLED();
                    OUT_LED_ARRAY(LED_ARRAY, POWER);
                    __delay_ms(150);
                }
                TURN_COUNT = 0;
            }
        }

        if (EEROM_FLAG == 1)
        {
            EEROM_W_DEFF();
        }

        set_CES();
        convert_ROTtoLED();
        OUT_LED_ARRAY(LED_ARRAY, POWER);
        __delay_ms(5);

        if (game_flag == GAME_FLAG_ON)
        {
            if (if_game_end() == 1)
            {
                __delay_ms(1000);
                animation_3(green, 2);
                EEROM_GAME_OFF();
                continue;
            }
        }
    }
    //never_calledのため
    animation_2();
}

char if_game_end(void)
{
    char deff, err_flag = 0;
    for (char i = 0; i < 6; i++)
    {
        deff = LED_Light[i][0];
        for (char j = 1; j < 9; j++)
            if (deff != LED_Light[i][j])
                err_flag++;
    }
    if (err_flag == 0)
        return 1;
    return 0;
}

void ioport(void)
{
    ANSELA = 0b00000001; // AN0をアナログPINに設定
    TRISA = 0b00000001;  // AN0のみ入力に設定
    PORTA = 0b00000000;  // 出力ピンの初期化
    ANSELB = 0;          // 全てデジタルIO
    PORTB = 0;
    TRISB = 0; // 入出力設定    //1=入力

    ADCON2 = 0b00010110; //左詰　４TAD　FOCS/６４
    ADCON1 = 0b00000000; //左詰め　FOCS/64 VDDを参照
}

void Special_input(char SS)
{
    switch (SS)
    {
    case 0:
        Special_input_0++;
        if (Special_input_0 >= 5)
            Special_input_0 = 0;
        switch (Special_input_0)
        {
        case 0:
            POWER = 0;
            sound_flag = 1;

            set_all_LED_ARRAY(no_color);

            OUT_LED_ARRAY(LED_ARRAY, POWER);
            while (1)
            {
                if (SPI_special(0) == 1)
                {
                    POWER = 200;
                    break;
                }
            }
            break;
        case 1:
            sound_flag = 0;
            POWER = 100;
            break;
        case 2:
            sound_flag = 1;
            POWER = 100;
            break;
        case 3:
            sound_flag = 0;
            POWER = 200;
            break;
        case 4:
            sound_flag = 1;
            POWER = 200;
            break;
        }
        break;
    case 1:
        animation_1(1);
        shuffle_state_CE(rand_seed);
        EEROM_GAME_ON();
        break;
    case 2:
        if (if_solution_end() == 0)
            break;
        initialization_shortest_command();
        char if_can_get, deep_flag;
        CE IDA_CE;
        mode_cube_end = 1;
        make_justice_axis();
        over_write_CE_from_A_to_B(state_CE, &IDA_CE);
        deep_flag = 0;
        while (shortest_depth < want_ddpth)
        {
            if_can_get = Create_Shoretest_command_Most_deep();
            if (SPI_special(2) == 1)
            {
                deep_flag = 2;
                break;
            }
            if (shortest_depth >= want_ddpth)
                break;
            if (if_can_get == 0)
            { //正常終了
                over_write_CE_from_A_to_B(IDA_CE, &state_CE);
                for (int j = 0; j <= shortest_depth; j++)
                {
                    command_turn_CE(CE_IDA_LIST[shortest_command[j]].name);
                }
                if (if_solution_end() == 0)
                {
                    deep_flag = 1;
                    break;
                }
            }
        }
        over_write_CE_from_A_to_B(IDA_CE, &state_CE);
        if (deep_flag == 0)
        {
            made_cube(1, 2);
        }
        else if (deep_flag == 2)
        {
            made_cube(0, 2);
        }
        else if (deep_flag == 1)
        {
            set_all_LED_ARRAY(orange);
            OUT_LED_ARRAY(LED_ARRAY, POWER);
            __delay_ms(1000);
            convert_ROTtoLED();
            OUT_LED_ARRAY(LED_ARRAY, POWER);
            for (char i = 0; i <= shortest_depth; i++)
                command_turn_ARRAY_2(CE_IDA_LIST[shortest_command[i]].name);
        }
        //over_write_CE(deff_CE);
        //EEROM_GAME_OFF();
        break;
    case 3:
        EEROM_W_SAVE();
        break;
    case 4:
        EEROM_R_SAVE();
        break;
    case 5:
        while (1)
        {
            rand_seed++;
            if (rand_seed > 65533)
                rand_seed = 0;

            if (animation_3(blue, 5) == 1)
                break;

            if (animation_1(5) == 1)
                break;
            // if (animation_2() == 1)
            //     break;
            if (animation_4(rand_seed) == 1)
                break;
        }
        SPI_RET_2();
        convert_ROTtoLED();
        break;
    }
}
