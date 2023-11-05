#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#define    Ultrasonic0     PIN0
#define    Ultrasonic1     PIN1
#define    Ultrasonic2     PIN2
#define    Ultrasonic3     PIN3


void ultrasonic_init(void);
void ultrasonic_triger(u8 Copy_Ultrasonic_Type);
void ultrasonic_Distance_Value(u32* Copy_Value);

#endif
