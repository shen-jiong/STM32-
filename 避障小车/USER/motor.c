/*

#include "led.h"
#include "key.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "Systick.h"
#include "motor.h"


void motor_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	//1.使能 GPIO分组 和 AFIO 时钟 
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );

	//2.禁用Jtag功能， 把PB3， PB4等重新映射为普通IO口 
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
	
	//3.初始化GPIO --> PB4 PB5 PB6 PB7 推挽输出
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode =  GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStruct );
	
	//设置默认值
  GPIO_SetBits( GPIOB, GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7  );
	
}


void motor_front(void)
{
   GPIO_SetBits(GPIOB ,GPIO_Pin_4 | GPIO_Pin_6);
	GPIO_ResetBits(GPIOB ,GPIO_Pin_5 | GPIO_Pin_7);
	
}

*/


#include "motor.h"
#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"
#include "led.h"

void motor_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO , ENABLE );
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
	GPIO_InitStruct.GPIO_Pin  =  GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_SetBits(GPIOB,GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
}
       

void set_left_a( int a )
{
	if( a == 0 )
	{
		GPIO_ResetBits(GPIOB ,GPIO_Pin_4 );
	}
	else 
	{
		GPIO_SetBits(GPIOB ,GPIO_Pin_4 );
	}
}

void set_left_b( int b )
{
	if( b == 0 )
	{
		GPIO_ResetBits(GPIOB ,GPIO_Pin_5 );
	}
	else 
	{
		GPIO_SetBits(GPIOB ,GPIO_Pin_5 );
	}
}

void set_right_a( int a )
{
	if( a == 0 )
	{
		GPIO_ResetBits(GPIOB ,GPIO_Pin_6 );
	}
	else 
	{
		GPIO_SetBits(GPIOB ,GPIO_Pin_6 );
	}
}

void set_right_b( int b )
{
	if( b == 0 )
	{
		GPIO_ResetBits(GPIOB ,GPIO_Pin_7 );
	}
	else 
	{
		GPIO_SetBits(GPIOB ,GPIO_Pin_7 );
	}
}

void move_front( void )
{
	set_left_a( 1 );
	set_left_b( 0 );

	set_right_a( 1 );
	set_right_b( 0 );
}

void move_back(void)
{
	set_left_a( 0 );
	set_left_b( 1 );

	set_right_a( 0 );
	set_right_b( 1 );
	
}

void move_left(void)
{
	set_left_a( 1 );
	set_left_b( 0 );

	set_right_a( 1 );
	set_right_b( 1 );
	
}
	
void move_right(void)
{
	set_left_a( 1 );
	set_left_b( 1 );

	set_right_a( 1 );
	set_right_b( 0 );
	
}

void stop(void)
{
	set_left_a( 1 );
	set_left_b( 1 );

	set_right_a( 1 );
	set_right_b( 1 );
	
}

 void move_front_PWM()
{
		unsigned char i = 2;

		set_left_a( 1 );
		set_right_a( 1 );

		while( i-- )
		{
				set_left_b( 0 );
				set_right_b( 0 );
				delay_ms( 50 );     //前进80ms

				set_left_b( 1 );
				set_right_b( 1 );
				delay_ms( 50 );     //停止20ms（让惯性带动车子转动）
		}
}

 void move_right_PWM()
{
	
		unsigned char i = 2;

		set_left_a( 1 );
		set_right_a( 1 );

		while( i-- )
		{
				set_left_b( 1 );
				set_right_b( 0 );
				delay_ms( 50 );     //前进80ms

				set_left_b( 1 );
				set_right_b( 1 );
				delay_ms( 50 );     //停止20ms（让惯性带动车子转动）
		}
}



 void move_left_PWM()
{
	
		unsigned char i = 2;

		set_left_a( 1 );
		set_right_a( 1 );

		while( i-- )
		{
				set_left_b( 0 );
				set_right_b( 1 );
				delay_ms( 50 );     //前进80ms

				set_left_b( 1 );
				set_right_b( 1 );
				delay_ms( 50 );     //停止20ms（让惯性带动车子转动）
		}
}
