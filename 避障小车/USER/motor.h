#ifndef __MOTOR_H
#define __MOTOR_H


void motor_init(void);

void set_left_a( int a );

void set_left_b( int b );

void set_right_a( int a );

void set_right_b( int b );

void move_front( void );

void move_back(void);

void move_left(void);

void move_right(void);
	
void stop(void);

void move_right_PWM(void);

void move_left_PWM(void);

void move_front_PWM(void);

#endif





