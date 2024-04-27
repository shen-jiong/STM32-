#include "motor.h"
#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"
#include "led.h"
#include "motor.h"
#include "track.h"

void track_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO , ENABLE );
	
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
	GPIO_InitStruct.GPIO_Pin  =  GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}
  
void auto_track(void)
{
	unsigned char l, r;

	while( 1 )
	{
		l = GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_0 );
		r = GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_1 );

		if( l == 0 && r == 0 )  //两边都没有压线
		{
			move_front_PWM();
		}
		else if(l == 1 && r == 0 )    //左边压线， 右边没有 
		{
		move_left_PWM();
		}
		else if(l == 0 && r == 1 )    //左边压线， 右边没有 
		{
		move_right_PWM();
		}
		else if(l == 1 && r == 1 )    //左边压线， 右边没有 
		{
		stop();
		}
	}
}

void auto_drive(void)
{

	unsigned char l, r;

	while( 1 )
	{
		l = GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_0 );
		r = GPIO_ReadInputDataBit( GPIOB , GPIO_Pin_1 );

		if( l == 1 && r == 1 )  
		{
			move_front();
		}
		else if(l == 0 && r == 1 )    
		{
		move_back();
		delay_ms(500);
		stop();
		move_right();
		delay_ms(500);
		}
		else if(l == 1 && r == 0 )    
		{
		move_back();
		delay_ms(500);
		stop();
		move_left();
		delay_ms(500);
		}
		else if(l == 0 && r == 0 )    
		{
		move_back();
		delay_ms(500);
		stop();
		move_left();
		delay_ms(500);
	  delay_ms(500);
		}
	}

}



