#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "BUZZER_config.h"
#include "BUZZER_interface.h"
#include "BUZZER_private.h"


u8 HAL_BUZZER_u8_Init (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinDirection(Copy_u8Port ,Copy_u8Pin , PIN_OUTPUT);
	return Local_u8ErrorState;
}

u8 HAL_BUZZER_u8_BuzzerOn (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinValue(Copy_u8Port ,Copy_u8Pin , PIN_HIGH);
	return Local_u8ErrorState;
}
u8 HAL_BUZZER_u8_BuzzerOff (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinValue(Copy_u8Port ,Copy_u8Pin , PIN_LOW);
	return Local_u8ErrorState;
}
u8 HAL_Buzzer_u8_BuzzerToggle (u8 Copy_u8Port , u8 Copy_u8Pin){

	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_TogglePinValue(Copy_u8Port ,Copy_u8Pin);
	return Local_u8ErrorState;
}
