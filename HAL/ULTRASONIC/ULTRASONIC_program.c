#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_private.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"




u8 flag=0;
u32 ontime=0;
u32 rising=0;
u8 ticktime=32; //micro sec
void Capture () // ISR for input capture interrupt
{
	if (flag == 0) // if rising edge detected
	{
		flag = 1; // set flag to 1
		TIMER1_voidSetTimerValue(0);// reset timer1 counter
		TIMER1_voidSetCompMatchTopValue(0);
		rising =ICU_voidGetValue();
		ICU_voidSetTriggerEdge(FALLING_EDGE); // set input capture edge select to falling edge
	}
	else // if falling edge detected
	{
		flag = 0; // set flag to 0
		ontime =(ICU_voidGetValue()-rising) * ticktime;
		ICU_voidSetTriggerEdge(RISING_EDGE); // set input capture edge select to rising edge
	}
}
void ultrasonic_init(){
	TIMER1_voidInit();
	ICU_voidInit();
	ICU_u8SetCallBack(Capture);
}
 void ultrasonic_triger(u8 Copy_Ultrasonic_Type){
	 MCAL_DIO_u8_SetPinValue(Copy_Ultrasoic_Port,Copy_Ultrasonic_Type,PIN_HIGH);
	 _delay_us(15);
	 MCAL_DIO_u8_SetPinValue(Copy_Ultrasoic_Port,Copy_Ultrasonic_Type,PIN_LOW);

 }

 void ultrasonic_Distance_Value(u32*Copy_Value){

	 *Copy_Value=ontime*343/20000;

 }




