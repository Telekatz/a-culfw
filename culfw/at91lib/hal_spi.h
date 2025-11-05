#ifndef __hal_spi_H
#define __hal_spi_H

typedef enum {
  SPI_0 = 0,
}SPI_port;

void spi_init(void);
uint8_t spi_send(uint8_t data, SPI_port port);
uint8_t spi_wait_SO_low(SPI_port port);

#endif /*__ spi_H */
