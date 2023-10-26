/******************************************************************************/
/******************************************************************************/
/********************          Author:  Moamen Alghareeb       ****************/
/********************          Layer:   MCAL                   ****************/
/********************          SWC:     TIMER                    ****************/
/********************          Version: 1.0                    ****************/
/******************************************************************************/
/******************************************************************************/


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/******************************************************************************************/
/*********************************** TIMER 0 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-CTC
 * 						*/
#define TIMER0_WAVE_GENERATION_SENSE		NORMAL


/****************************Compare Output  MODE Selection*************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER0_CTC_SENSE		NO_OPERATION

/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/

#define TIMER0_CLOCK_SELECT_SENSE				CLK8



/******************************************************************************************/
/*********************************** TIMER 1 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-CTC * 						*/
#define TIMER1_WAVE_GENERATION_SENSE		NORMAL

/****************************TOP Selection*************************/
/*options:
 * for CTC mode use *OCR and *ICR options only
 * 			1-OCR
 * 			2-ICR
 * 			3-BIT8
 * 			4-BIT9
 * 			5-BIT10
 * 						*/
#define TIMER1_TOP_SENSE				ICR
/****************************CTC output MODE *************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER1_CTC_SENSE					NO_OPERATION

/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/
#define TIMER1_CLOCK_SELECT_SENSE				CLK64

/******************************************************************************************/
/*********************************** TIMER 2 CONFIGS***************************************/
/******************************************************************************************/


/*************************Waveform Generation Mode Selection************************/
/*options:
 * 			1-NORMAL
 * 			2-CTC
 * 						*/
#define TIMER2_WAVE_GENERATION_SENSE		NORMAL


/****************************Compare Output  MODE Selection*************************/
/*options:
 * 			1-NO_OPERATION
 * 			2-TOGGLE
 * 			3-CLR
 * 			4-SET
 * 						*/
#define TIMER2_CTC_SENSE		NO_OPERATION

/************************************ Clock Select **********************************/
/*options:
 * 			1-OFF
 * 			2-CLK
 * 			3-CLK8
 * 			4-CLK64
 * 			5-CLK256
 * 			6-CLK1024
 * 			7-COUNTER_FALLING
 * 			8-COUNTER_RISING
 * 						*/

#define TIMER2_CLOCK_SELECT_SENSE				CLK64


#endif
