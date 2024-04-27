
#ifndef __LED_H__
#define __LED_H__ 

//主要包含 宏定义、函数声明等 

//灯的编号 
#define LED1 1
#define LED2 2 
#define LED3 3
#define LED4 4
#define LED5 5
#define LED6 6
#define LED7 7 
#define LED8 8
#define LED_ALL 9

//灯的状态 
#define ON  0 	//亮
#define OFF 1	//灭



void led_init(void);    //函数声明 
void led_ctl( int LED_ID, int ON_OFF );




#endif



