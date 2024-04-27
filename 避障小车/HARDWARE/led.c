#include "led.h"

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


//led灯的引脚的初始化
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	//1.使能 GPIO分组 和 AFIO 时钟 
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE );

	//2.禁用Jtag功能， 把PB3， PB4等重新映射为普通IO口 
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
	
	//3.初始化GPIO --> PB0~PB7, 输出推挽
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(  GPIOB, &GPIO_InitStruct );
	
	//给每一个灯一个初始化状态： 熄灭 
	GPIO_SetBits( GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7  );
	
}

/*
	led_ctl: led灯的控制
		LED_ID: 灯的编号 
				#define LED1 1
				#define LED2 2 
				...
		ON_OFF : 灯的状态 
				#define ON  0 	//亮
				#define OFF 1	//灭
*/
void led_ctl( int LED_ID, int ON_OFF )
{
	switch( LED_ID )
	{
		case LED1 : GPIO_WriteBit( GPIOB, GPIO_Pin_0, (BitAction)ON_OFF ); break;
		case LED2 : GPIO_WriteBit( GPIOB, GPIO_Pin_1, (BitAction)ON_OFF ); break;
		case LED3 : GPIO_WriteBit( GPIOB, GPIO_Pin_2, (BitAction)ON_OFF ); break;
		case LED4 : GPIO_WriteBit( GPIOB, GPIO_Pin_3, (BitAction)ON_OFF ); break;
		case LED5 : GPIO_WriteBit( GPIOB, GPIO_Pin_4, (BitAction)ON_OFF ); break;
		case LED6 : GPIO_WriteBit( GPIOB, GPIO_Pin_5, (BitAction)ON_OFF ); break;
		case LED7 : GPIO_WriteBit( GPIOB, GPIO_Pin_6, (BitAction)ON_OFF ); break;
		case LED8 : GPIO_WriteBit( GPIOB, GPIO_Pin_7, (BitAction)ON_OFF ); break;
		default : 
			break;
	}
	

	/*
	if( LED_ID == LED1 )   //灯1 
	{
		if( ON_OFF == ON )   //点亮 
		{
			//输出低电平0
			GPIO_WriteBit( GPIOB, GPIO_Pin_0, Bit_RESET );
		}
		else 	//熄灭
		{
			GPIO_WriteBit( GPIOB, GPIO_Pin_0, Bit_SET );
		}
	}
	else if( LED_ID == LED2 )   //灯2 
	{
		if( ON_OFF == ON )   //点亮 
		{
			//输出低电平0
			GPIO_WriteBit( GPIOB, GPIO_Pin_1, Bit_RESET );
		}
		else 	//熄灭
		{
			GPIO_WriteBit( GPIOB, GPIO_Pin_1, Bit_SET );
		}
	}
	else if( LED_ID == LED2 )   //灯3 
	{
		GPIO_WriteBit( GPIOB, GPIO_Pin_2, (BitAction)ON_OFF );
	}
	//...
	*/

	
}

 



