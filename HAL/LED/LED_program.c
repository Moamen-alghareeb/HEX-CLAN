#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"
#include "../../MCAL/DIO/DIO_interface.h"

u8 HAL_LED_u8_Init (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinDirection(Copy_u8Port ,Copy_u8Pin , PIN_OUTPUT);
	return Local_u8ErrorState;
}

u8 HAL_LED_u8_LedOn (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinValue(Copy_u8Port ,Copy_u8Pin , PIN_HIGH);
	return Local_u8ErrorState;
}
u8 HAL_LED_u8_LedOff (u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_SetPinValue(Copy_u8Port ,Copy_u8Pin , PIN_LOW);
	return Local_u8ErrorState;

}
u8 HAL_LED_u8_LedToggle (u8 Copy_u8Port , u8 Copy_u8Pin){

	u8 Local_u8ErrorState = NOK;
	Local_u8ErrorState = MCAL_DIO_u8_TogglePinValue(Copy_u8Port ,Copy_u8Pin);
	return Local_u8ErrorState;
}
