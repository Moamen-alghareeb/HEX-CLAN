#include "../../LIB/STD_TYPES.h"

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

u8 HAL_LED_u8_Init (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_LED_u8_LedOn (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_LED_u8_LedOff (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_LED_u8_LedToggle (u8 Copy_u8Port , u8 Copy_u8Pin);



#endif /* LED_INTERFACE_H_ */
