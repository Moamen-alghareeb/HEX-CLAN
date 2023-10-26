/**********************************************************************/
/**********************************************************************/
/***********************   OMAR & Ahmed Maher   ***********************/
/***********************   Layer :MCAL    		***********************/
/***********************   SWC (DRIVER):ADC 	**********************/
/***********************   DATA : 26-10-2023	 *********************/
/***********************   VERSION : 1.00   	*********************/
/********************************************************************/
/********************************************************************/
/*preprocessor file guard */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define ADC_STATE		ENABLE




void ADC_void_Init (void);

u8 ADC_u8_StartSingleConversionSyn (u8 Copy_u8Channnel , u16 * Copy_u16Result);

u8 ADC_u8_StartSingleConversionAsyn (u8 Copy_u8Channel ,u16 *Copy_u16Result , void (*Copy_PvNotification)(void));







#endif
