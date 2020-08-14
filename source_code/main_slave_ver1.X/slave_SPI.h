#include <xc.h>
#ifndef _SLAVE_SPI_H_
#define _SLAVE_SPI_H_
extern char SPI_FLAG ;
extern char send_SPI_1;
extern char return_SPI;

void SPI_S_ioport(void) ;

void SPI_interrupt(void);

void SPI_send(char data);

#endif