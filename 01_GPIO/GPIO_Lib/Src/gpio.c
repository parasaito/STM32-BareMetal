#include "gpio.h"

//TODO : Error  handling on invalid inputs

void gpio_init(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t mode)
{
    pin <<= 1;
    
    if (GPIOx == GPIOA) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    }
    else if (GPIOx == GPIOB) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    }
    else if (GPIOx == GPIOC) {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    }
    
    GPIOx->MODER &= ~(0x3UL << pin);
    
    switch (mode) {
        case 1:
            GPIOx->MODER |= 0x1UL << pin;
            break;
        case 2:
            GPIOx->MODER |= 0x2UL << pin;
            break;
        case 3:
            GPIOx->MODER |= 0x3UL << pin;
            break;
        default:
            break;
    }
}