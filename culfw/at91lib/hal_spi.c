#include "board.h"
#include <stdint.h>
#include "hal_spi.h"

void spi_init(void) {
  AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_SPI0);

  AT91C_BASE_PIOA->PIO_PPUER =  SPI_MISO | SPI_MOSI | SPI_SCLK;
  AT91C_BASE_PIOA->PIO_ASR =  SPI_MISO | SPI_MOSI | SPI_SCLK;
  AT91C_BASE_PIOA->PIO_PDR =  SPI_MISO | SPI_MOSI | SPI_SCLK;


  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SWRST;
  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SWRST;

  AT91C_BASE_SPI0->SPI_CR = AT91C_SPI_SPIEN;
  AT91C_BASE_SPI0->SPI_MR= AT91C_SPI_MSTR| AT91C_SPI_MODFDIS;
  AT91C_BASE_SPI0->SPI_CSR[0] = AT91C_SPI_NCPHA | (48<<8);
}

uint8_t spi_send(uint8_t data, SPI_port port) {
  // Send data
  switch(port) {
  case SPI_0:
    while ((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_TXEMPTY) == 0);
    AT91C_BASE_SPI0->SPI_TDR = data;
    while ((AT91C_BASE_SPI0->SPI_SR & AT91C_SPI_RDRF) == 0);
    return AT91C_BASE_SPI0->SPI_RDR & 0xFF;
    break;
  }
}
