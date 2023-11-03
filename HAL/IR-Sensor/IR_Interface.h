/********************************************************************
 ****************************LAYER: HAL *****************************
 *************************MODULE: IRSensor***************************
 *********************FILE Name: IR_Interface.h**********************
 DESCRIPTION: Initialization of IR-Sensor Main Functions Header File*
 ************************UPDATED: 3/11/2023**************************
 *************************AUTHOR: HEX CLAN***************************
 ********************************************************************
 */

#ifndef IR_DRIVER_IR_INTERFACE_H_
#define IR_DRIVER_IR_INTERFACE_H_


/*******************************************************************************
 ***********************Function Prototypes*************************************
 1)HAL_IR_Void_Init
 ******************************************************************************/


/**************************************************************************************
 * Function Name: HAL_IR_Void_Init
 * Parameters (in): None
 * Parameters (input): None
 * Parameters (out): None
 * Return value:(Error State)-IR_Invalid_Initialization.
 * Description: Function to Initialize the IR-Sensor module.
 ************************************************************************************/
IR_Invalid_Initialization HAL_IR_Void_Init();


#endif /* IR_DRIVER_IR_INTERFACE_H_ */
