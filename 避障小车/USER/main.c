#include "stm32f10x.h"
#include "SysTick.h"
#include "system.h"

#include "beep.h"
#include "led.h"
#include "key.h"
#include "motor.h"
#include "key.h"
#include "track.h"

int main(void)
{	
  SysTick_Init(72);
	motor_init();
	track_init();
	auto_drive();
}



