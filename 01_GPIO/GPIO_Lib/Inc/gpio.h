#ifndef GPIO_H
#define GPIO_H

#include "stm32l432xx.h"

void gpio_init(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t mode);

#endif //GPIO_H