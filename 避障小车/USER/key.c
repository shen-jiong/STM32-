#include "led.h"
#include "key.h"
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "Systick.h"

//led灯的引脚的初始化
void key_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	//1.使能 GPIO分组 和 AFIO 时钟 
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE );

	//2.禁用Jtag功能， 把PB3， PB4等重新映射为普通IO口 
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_JTAGDisable , ENABLE );
	
	//3.初始化GPIO --> PA2 PA13 PA6 PA7 带上拉的输入
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_13 | GPIO_Pin_6 | GPIO_Pin_7 ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct );
	

}


int  key_ctl_led_beep(void)
{
	while(1)
	{
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)==0)
	{
		delay_ms(50);
		
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)==0){};
		delay_ms(50);
		return 1;
	}
	
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13)==0)
	{
		delay_ms(50);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13)==0){};
		delay_ms(50);
		return 2;
	}
	
	
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
	{
		delay_ms(50);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0){};
		delay_ms(50);
		return 3;
	}
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
	{
		delay_ms(50);
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0){};
		delay_ms(50);
		return 4;
		
	}
	}
}


