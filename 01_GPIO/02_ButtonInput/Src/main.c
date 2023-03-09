#include "stm32l432xx.h"	//Device header


int main()
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN;

	GPIOA->MODER &=~ 3;

	GPIOB->MODER &=~ (3<<6);		
	GPIOB->MODER |= 1<<3;
	
	while(1)
	{
		if(GPIOA->ODR && 0x1)	GPIOB->ODR |= 1<<3;
		
		else 					GPIOB->ODR &=~(1<<3);
	}

    return 0;
}
