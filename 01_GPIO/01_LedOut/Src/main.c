#include "stm32l432xx.h" //Device header

int main() {
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
  GPIOB->MODER &= ~(3 << 6);
  GPIOB->MODER |= 1 << 6;

  while (1) {
    GPIOB->ODR |= (1 << 3);
  }

  return 0;
}
