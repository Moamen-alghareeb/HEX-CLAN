#ifndef INCFILE1_H_
#define INCFILE1_H_


#define PIN1_MOTOR1     PIN0
#define PIN2_MOTOR1     PIN1
#define PIN1_MOTOR2     PIN2
#define PIN2_MOTOR2     PIN3


#define PORT_MOTOR    PORTA_ID

typedef enum{
	M1,
	M2
}MOTOR_type;





void HALL_MOTOR_CCW(MOTOR_type motor);
void HALL_MOTOR_CW(MOTOR_type motor);
void HALL_MOTOR_stop(MOTOR_type motor);


#endif /* INCFILE1_H_ */
