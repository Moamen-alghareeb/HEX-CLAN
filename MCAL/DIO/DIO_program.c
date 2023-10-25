#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_std_types.h"
#include "BIT_MATH.h"

/*ghareeb*/
static const Dio_ConfigType *Dio_PortPins = NULL_PTR;
static u8 Dio_Status = DIO_NOT_INITIALIZED;


void Dio_Init(const Dio_ConfigType *ConfigPtr) {
    u8 Local_u8_ErrorStatus = NOK;
    u8 Local_u8_Counter = 0;
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr) {
        Local_u8_ErrorStatus = NULL;
    } else {
        //	Dio_PortPins = (ConfigPtr->pins); /* address of the first pin structure --> pin[0] */

        if (DIO_NOT_INITIALIZED == Dio_Status) {
            Dio_Status = DIO_INITIALIZED;
            Dio_PortPins = ConfigPtr;
            u8 pinNum;
            volatile u8 *Port_Ptr = NULL_PTR;

            /* Point to the correct PORT register according to the Port Id stored in the Port_Id member */
            for (Local_u8_Counter = 0; Local_u8_Counter < DIO_CONFIGURED_CHANNLES; ++Local_u8_Counter) {

                if (Dio_PortPins->pins[Local_u8_Counter] == NULL_PTR) {
                    /* Do Nothing */
                } else {
                    switch (Dio_PortPins->pins[Local_u8_Counter]->Port_Id) {
                        case 1:
                            Port_Ptr = &PORTA;
                            break;
                        case 2:
                            Port_Ptr = &PORTB;
                            break;
                        case 3:
                            Port_Ptr = &PORTC;
                            break;
                        case 4:
                            Port_Ptr = &PORTD;
                            break;
                    }

                    pinNum = getPinNum(Dio_PortPins->pins[Local_u8_Counter]->Pin_Id);

                    if (Port_Ptr != NULL_PTR) {

                        /*Set Pin Direction*/
                        if (Dio_PortPins->pins[Local_u8_Counter]->dir == INPUT) {
                            SET_BIT(*Port_Ptr, pinNum);
                        } else if (Dio_PortPins->pins[Local_u8_Counter]->dir == OUTPUT) {
                            CLR_BIT(*Port_Ptr, pinNum);
                        } else {
                            /* Do Nothing */
                        }

                        /*Set Pin Value*/
                        if (Dio_PortPins->pins[Local_u8_Counter]->level == STD_HIGH) {
                            SET_BIT(*Port_Ptr, pinNum);
                        } else if (Dio_PortPins->pins[Local_u8_Counter]->level == STD_LOW) {
                            CLR_BIT(*Port_Ptr, pinNum);
                        } else {
                            /* Do Nothing */
                        }
                    } else {
                        /* Do Nothing */
                    }
                }
            }
        } else {
            /* Do Nothing */
        }
    }
}


u8 MCAL_DIO_u8_SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
    u8 Local_u8ErrorState = 0;

    if (Copy_u8Pin <= PIN7) {
        if (Copy_u8Direction == PIN_INPUT) {
            switch (Copy_u8Port) {
                case PORTA_ID:
                    CLR_BIT(DDRA, Copy_u8Pin);
                    break;
                case PORTB_ID:
                    CLR_BIT(DDRB, Copy_u8Pin);
                    break;
                case PORTC_ID:
                    CLR_BIT(DDRC, Copy_u8Pin);
                    break;
                case PORTD_ID:
                    CLR_BIT(DDRD, Copy_u8Pin);
                    break;
                default:
                    Local_u8ErrorState = 1;
                    break;
            }
        } else if (Copy_u8Direction == PIN_OUTPUT) {
            switch (Copy_u8Port) {
                case PORTA_ID:
                    SET_BIT(DDRA, Copy_u8Pin);
                    break;
                case PORTB_ID:
                    SET_BIT(DDRB, Copy_u8Pin);
                    break;
                case PORTC_ID:
                    SET_BIT(DDRC, Copy_u8Pin);
                    break;
                case PORTD_ID:
                    SET_BIT(DDRD, Copy_u8Pin);
                    break;
                default:
                    Local_u8ErrorState = 1;
                    break;
            }
        } else {
            Local_u8ErrorState = 1;
        }
    } else {
        Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

u8 MCAL_DIO_u8_SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
    u8 Local_u8ErrorState = 0;

    switch (Copy_u8Port) {
        case PORTA_ID :
            DDRA = Copy_u8Direction;
            break;
        case PORTB_ID :
            DDRB = Copy_u8Direction;
            break;
        case PORTC_ID :
            DDRC = Copy_u8Direction;
            break;
        case PORTD_ID :
            DDRD = Copy_u8Direction;
            break;
        default:
            Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

u8 MCAL_DIO_u8_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
    u8 Local_u8ErrorState = 0;

    if (Copy_u8Pin <= PIN7) {
        if (Copy_u8Value == PIN_LOW) {
            switch (Copy_u8Port) {
                case PORTA_ID:
                    CLR_BIT(PORTA, Copy_u8Pin);
                    break;
                case PORTB_ID:
                    CLR_BIT(PORTB, Copy_u8Pin);
                    break;
                case PORTC_ID:
                    CLR_BIT(PORTC, Copy_u8Pin);
                    break;
                case PORTD_ID:
                    CLR_BIT(PORTD, Copy_u8Pin);
                    break;
                default:
                    Local_u8ErrorState = 1;
                    break;
            }
        } else if (Copy_u8Value == PIN_HIGH) {
            switch (Copy_u8Port) {
                case PORTA_ID:
                    SET_BIT(PORTA, Copy_u8Pin);
                    break;
                case PORTB_ID:
                    SET_BIT(PORTB, Copy_u8Pin);
                    break;
                case PORTC_ID:
                    SET_BIT(PORTC, Copy_u8Pin);
                    break;
                case PORTD_ID:
                    SET_BIT(PORTD, Copy_u8Pin);
                    break;
                default:
                    Local_u8ErrorState = 1;
                    break;
            }
        } else {
            Local_u8ErrorState = 1;
        }
    } else {
        Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

u8 MCAL_DIO_u8_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
    u8 Local_u8ErrorState = 0;

    switch (Copy_u8Port) {
        case PORTA_ID :
            PORTA = Copy_u8Value;
            break;
        case PORTB_ID :
            PORTB = Copy_u8Value;
            break;
        case PORTC_ID :
            PORTC = Copy_u8Value;
            break;
        case PORTD_ID :
            PORTD = Copy_u8Value;
            break;
        default:
            Local_u8ErrorState = 1;
    }

    return Local_u8ErrorState;
}

u8 MCAL_DIO_u8_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value) {
    u8 Local_u8ErrorState = 0;

    if ((Copy_pu8Value != NULL) && (Copy_u8Pin <= PIN7)) {
        switch (Copy_u8Port) {
            case PORTA_ID :
                *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);
                break;
            case PORTB_ID :
                *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);
                break;
            case PORTC_ID :
                *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);
                break;
            case PORTD_ID :
                *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = 1;
        }
    } else {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}

u8 MCAL_DIO_u8_TogglePinValue(u8 copy_u8Port, u8 copy_u8Pin) {
    u8 Local_u8ErrorState = 0;
    switch (copy_u8Port) {
        case PORTA_ID:
            TOGGLE_BIT(PORTA, copy_u8Pin);
            break;
        case PORTB_ID:
            TOGGLE_BIT(PORTB, copy_u8Pin);
            break;
        case PORTC_ID:
            TOGGLE_BIT(PORTC, copy_u8Pin);
            break;
        case PORTD_ID:
            TOGGLE_BIT(PORTD, copy_u8Pin);
            break;
        default:
            Local_u8ErrorState = 1;
            break;
    }
    return Local_u8ErrorState;
}





