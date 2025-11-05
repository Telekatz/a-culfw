#ifndef __VBUS_LAN_
#define __VBUS_LAN_

#include <stdint.h>

#define SOCK_VBUS   4

int32_t rxtx_vbus(void);
void init_vbus();
void send_vbus_data(uint8_t *data, uint16_t size,  uint8_t cdc);

#endif
