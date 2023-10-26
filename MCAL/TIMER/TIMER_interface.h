/******************************************************************************/
/******************************************************************************/
/********************          Author:  Moamen Alghareeb       ****************/
/********************          Layer:   MCAL                   ****************/
/********************          SWC:     TIMER                    ****************/
/********************          Version: 1.0                    ****************/
/******************************************************************************/
/******************************************************************************/
#include"STD_TYPES.h"

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H



/**********************************  TIMER 0 Functions  *******************************/
void TIMER0_voidInit(void);
void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER0_voidSetTimerValue(u8 Copy_u8Value);
u8 TIMER0_u8OVFSetCallBack(void (*Copy_pvTimer0OVFFunc)(void));
u8 TIMER0_u8CompSetCallBack(void (*Copy_pvTimer0CompFunc)(void));

/**********************************  TIMER 1 Functions  *******************************/
void TIMER1_voidInit(void);
void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16  TIMER1_voidGetTimerValue(void);
void TIMER1_voidSetCompMatchAValue(u8 Copy_u8Value);
void TIMER1_voidSetCompMatchBValue(u8 Copy_u8Value);
void TIMER1_voidSetCompMatchTopValue(u8 Copy_u8Value);
u8 TIMER1_u8OVFSetCallBack(void (*Copy_pvTimerOVFFunc)(void));
u8 TIMER1_u8CompASetCallBack(void (*Copy_pvTimerCompFunc)(void));
u8 TIMER1_u8CompBSetCallBack(void (*Copy_pvTimerCompFunc)(void));

/**********************************  TIMER 2 Functions  *******************************/
void TIMER2_init(void);
void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER2_voidSetTimerValue(u8 Copy_u8Value);
u8 TIMER2_u8OVFSetCallBack(void (*Copy_pvTimerOVFFunc)(void));
u8 TIMER2_u8CompSetCallBack(void (*Copy_pvTimer2CompFunc)(void));


#endif
