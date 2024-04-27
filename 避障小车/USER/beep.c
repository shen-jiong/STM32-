#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"

void beep_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE );
		//1.使能 GPIO分组 和 AFIO 时钟
		GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
		//2.禁用Jtag功能， 把PB3， PB4等重新映射为普通IO口 
		
		//3.初始化GPIO
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init( GPIOA, &GPIO_InitStruct );

		//给每一个灯一个初始化状态： 熄灭 
		GPIO_SetBits( GPIOB, GPIO_Pin_1 );
 
		//设置默认状态 ： 不响 
}

 void beep_ctl( int ON_OFF )
{
						if( ON_OFF == 0 )
						{
						 GPIO_ResetBits(GPIOA, GPIO_Pin_1);

						}
						else 
						{
						GPIO_SetBits(GPIOA, GPIO_Pin_1);
						}
} 

