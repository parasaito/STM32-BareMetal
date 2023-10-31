#include "stm32l432xx.h" //Device header

int main() {
	
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  
  GPIOB->MODER &= ~(0x3UL << GPIO_MODER_MODE3_Pos);

  GPIOB->MODER |= 0x1UL << GPIO_MODER_MODE3_Pos;

  while (1) {
      GPIOB->ODR |= GPIO_ODR_OD3;
  }

  return 0;
}
