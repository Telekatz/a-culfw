#ifndef _BOARD_H
#define _BOARD_H

#include <avr/io.h>

#define BUSWARE_COC

#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
#define SPI_SS			4
#define SPI_MISO		6
#define SPI_MOSI		5
#define SPI_SCLK		7

#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT          SPI_PORT
#define CC1100_CS_PIN		SPI_SS

#define CC1100_OUT_DDR		DDRB
#define CC1100_OUT_PORT         PORTB
#define CC1100_OUT_PIN          1
#define CC1100_OUT_IN           PINB

#define CC1100_IN_DDR		DDRD
#define CC1100_IN_PORT          PIND
#define CC1100_IN_PIN           2
#define CC1100_IN_IN            PIND
#define CC1100_INT		INT0
#define CC1100_INTVECT          INT0_vect
#define CC1100_ISC		ISC00
#define CC1100_EICR             EICRA

#define LED_DDR                 DDRC
#define LED_PORT                PORTC
#define LED_PIN                 6

#define BOARD_ID_STR            "CSM868"
#define BOARD_ID_STR433         "CSM433"

#define HAS_UART                
#define UART_BAUD_RATE          38400
#define USART_RX_vect           USART0_RX_vect
#define USART_UDRE_vect         USART0_UDRE_vect

#define TTY_BUFSIZE             1024  // 4 buffers < 16k SRAM

#define HAS_FHT_80b                   // PROGMEM: 1374b, RAM: 90b
#define HAS_FHT_8v                    // PROGMEM:  586b  RAM: 23b
#define HAS_FHT_TF
#define HAS_RF_ROUTER                 // PROGMEM: 1248b  RAM: 44b

#define FHTBUF_SIZE          174      //                 RAM: 174b
#define RCV_BUCKETS            4      //                 RAM: 25b * bucket
#define RFR_DEBUG                     // PROGMEM:  354b  RAM: 14b
#define FULL_CC1100_PA                // PROGMEM:  108b
#define HAS_RAWSEND                   //
#define HAS_FASTRF                    // PROGMEM:  468b  RAM:  1b
#define HAS_ASKSIN
#define HAS_ASKSIN_FUP
#define HAS_MORITZ
#define HAS_ESA
#define HAS_TX3
#define HAS_INTERTECHNO
#define HAS_HOMEEASY
#define HAS_TCM97001
#define HAS_MANCHESTER
#define HAS_REVOLT
#define HAS_HOERMANN
#define HAS_MBUS
#define HAS_MEMFN
#define HAS_HMS
#define HAS_CC1101_RX_PLL_LOCK_CHECK_TASK_WAIT
#define HAS_CC1101_PLL_LOCK_CHECK_MSG
#define HAS_CC1101_PLL_LOCK_CHECK_MSG_SW
#define HAS_IT

#define HAS_ONEWIRE         10      // OneWire Device Buffer, RAM: 10 * 8 Byte
#define OW_SPU			    // StrongPullUp support
#ifdef RADIO_ONLY
#undef  HAS_ONEWIRE
#endif

#define HAS_MBUS

#undef  HAS_RTC
#define RTC_ADDR                0xd0

#define BUSWARE_CSM
#define BUSWARE_COC
#define RPI_TTY_FIX

#endif

