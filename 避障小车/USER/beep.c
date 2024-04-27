#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"

void beep_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	
	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE );
		//1.ʹ�� GPIO���� �� AFIO ʱ��
		GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
		//2.����Jtag���ܣ� ��PB3�� PB4������ӳ��Ϊ��ͨIO�� 
		
		//3.��ʼ��GPIO
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init( GPIOA, &GPIO_InitStruct );

		//��ÿһ����һ����ʼ��״̬�� Ϩ�� 
		GPIO_SetBits( GPIOB, GPIO_Pin_1 );
 
		//����Ĭ��״̬ �� ���� 
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

