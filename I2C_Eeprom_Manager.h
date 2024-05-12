#ifndef _EE_MAN_H_
#define _EE_MAN_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include "i2c.h"

#define EE_MAN_1KBIT                            1
#define EE_MAN_2KBIT                            2
#define EE_MAN_4KBIT                            4
#define EE_MAN_8KBIT                            8
#define EE_MAN_16KBIT                           16
#define EE_MAN_32KBIT                           32
#define EE_MAN_64KBIT                           64
#define EE_MAN_128KBIT                          128
#define EE_MAN_256KBIT                          256
#define EE_MAN_512KBIT                          512

#define EE_MAN_RTOS_DISABLE                     0
#define EE_MAN_RTOS_CMSIS_V1                    1
#define EE_MAN_RTOS_CMSIS_V2                    2
#define EE_MAN_RTOS_THREADX                     3

#define EE_MAN_SIZE      EE_MAN_256KBIT

#define EE_MAN_RTOS      EE_MAN_RTOS_DISABLE

#define EE_MAN_USE_WP_PIN      false

#define EE_MAN_ADDRESS_DEFAULT 0xA0

typedef struct
{
  I2C_HandleTypeDef      *HI2c;
  uint8_t                Address;
  uint8_t                Lock;
#if EE_MAN_USE_WP_PIN == true
  GPIO_TypeDef           *WpGpio;
  uint16_t                WpPin;
#endif

} EE_MAN_HandleTypeDef;

#if EE_MAN_USE_WP_PIN == false
bool EE_MAN_Init(EE_MAN_HandleTypeDef *Handle, I2C_HandleTypeDef *HI2c, uint8_t I2CAddress);
#else
bool EE_MAN_Init(EE_MAN_HandleTypeDef *Handle, I2C_HandleTypeDef *HI2c, uint8_t I2CAddress, GPIO_TypeDef *WpGpio, uint16_t WpPin);
#endif
bool EE_MAN_Read(EE_MAN_HandleTypeDef *Handle, uint32_t Address, uint8_t *Data, size_t Len, uint32_t Timeout);
bool EE_MAN_Write(EE_MAN_HandleTypeDef *Handle, uint32_t Address, uint8_t *Data, size_t Len, uint32_t Timeout);

#ifdef __cplusplus
}
#endif
#endif
