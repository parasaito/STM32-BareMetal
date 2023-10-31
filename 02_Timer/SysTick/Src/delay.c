#include "delay.h"
#include "system_stm32l4xx.h"
#include "stm32l432xx.h"
#include "core_cm4.h"

void delayms(uint32_t time)
{
	SysTick->LOAD = SystemCoreClock/1000 - 1;
	
	if (SysTick->LOAD > 16777215) {
		return;
	}

	SysTick->VAL = 0UL;

	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);
	
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
		
	for (int i = 0; i < time; i++)
	{
		while (! (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	}
	
	SysTick->CTRL = 0;       
}

void delayus(uint32_t time)
{
	SysTick->LOAD = SystemCoreClock/1000000 - 1;

	SysTick->VAL = 0UL;

	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk);
	
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
		
	for (int i = 0; i < time; i++)
	{
		while (! (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	}
	
	SysTick->CTRL = 0;       
}


