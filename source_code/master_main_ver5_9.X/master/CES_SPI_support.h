/*
SPIで取得したデータを回転記号に変換
*/
#ifndef _CES_SPI_SUPPORT_H_
#define _CES_SPI_SUPPORT_H_
#include "master_SPI.h"
/*
 * D2S : Data→String
 * D2S0: Data→String[0]
*/

char SPI_special(const char);

signed char SPI_D2S(const char, const char);

/*D2S0の引数は%4を行ってある
戻り値：'@'はerr
*/
char SPI0_D2S0(const char);
char SPI1_D2S0(const char);
char SPI2_D2S0(const char);
char SPI3_D2S0(const char);
char SPI4_D2S0(const char);
char SPI5_D2S0(const char);
#endif
