#ifndef _SPI_H
#define _SPI_H

#include <avr/io.h>                     // for _BV
#include <stdint.h>                     // for uint8_t

/* prototypes */
void spi_init(void);
#ifdef USE_HAL
uint8_t spi_send(uint8_t data, SPI_port port);
#else
uint8_t spi_send(uint8_t data);
#endif

#define spi_wait()  while (!(SPSR & _BV(SPIF)))

#endif
