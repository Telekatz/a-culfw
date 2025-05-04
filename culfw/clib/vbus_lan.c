#include "board.h"
#ifdef VBUS_LAN

#include <socket.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <utility/trace.h>
#include "vbus_lan.h"
#include <socket.h>
#include "hw_autodetect.h"
#include "ethernet.h"
#include "hal_usart.h"

extern uint8_t gDATABUF[];

uint8_t vbus_data = 0;

const uint8_t VBUS_txt_quit[]  = "+OK: See ya...\r\n";
const uint8_t VBUS_txt_hello[] = "+HELLO\r\n";
const uint8_t VBUS_txt_pass[]  = "+OK: Password accepted\n\r";
const uint8_t VBUS_txt_data[]  = "+OK: Data incoming...\n\r";

int32_t rxtx_vbus() {
  int32_t ret;
  uint16_t size = 00;

  if((size = getSn_RX_RSR(SOCK_VBUS)) > 0) {
    ret = recv(SOCK_VBUS, gDATABUF, size);
    if(ret <= 0) return ret;


    if(!strncmp((char*)gDATABUF,"QUIT",4)) {
      vbus_data = 0;
      send(SOCK_VBUS, (uint8_t*)VBUS_txt_quit, sizeof(VBUS_txt_quit));
      close(SOCK_VBUS);
      return 1;
    }

    if(!strncmp((char*)gDATABUF,"PASS",4)) {
      send(SOCK_VBUS, (uint8_t*)VBUS_txt_pass, sizeof(VBUS_txt_pass));
      return 1;
    }

    if(!strncmp((char*)gDATABUF,"DATA",4)) {
      vbus_data = 1;
      send(SOCK_VBUS, (uint8_t*)VBUS_txt_data, sizeof(VBUS_txt_data));
      return 1;
    }

  }

  return 1;
}

void send_vbus_data(uint8_t *data, uint16_t size,  uint8_t cdc) {

  if((VBUS_LAN == cdc) && vbus_data) {
#ifdef USE_HW_AUTODETECT
    if(has_ethernet())
 #endif
      Net_Write(data, size, SOCK_VBUS);
  }
}

void init_vbus() {
  send(SOCK_VBUS, (uint8_t*)VBUS_txt_hello, sizeof(VBUS_txt_hello));
  vbus_data = 0;
  HAL_UART_Set_Baudrate(VBUS_LAN,9600);
}

#endif

