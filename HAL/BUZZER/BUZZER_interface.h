#include "../../LIB/STD_TYPES.h"

#ifndef BUZZER_BUZZER_INTERFACE_H_
#define BUZZER_BUZZER_INTERFACE_H_

u8 HAL_BUZZER_u8_Init (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_BUZZER_u8_BuzzerOn (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_BUZZER_u8_BuzzerOff (u8 Copy_u8Port , u8 Copy_u8Pin);
u8 HAL_Buzzer_u8_BuzzerToggle (u8 Copy_u8Port , u8 Copy_u8Pin);


#endif /* BUZZER_BUZZER_INTERFACE_H_ */
