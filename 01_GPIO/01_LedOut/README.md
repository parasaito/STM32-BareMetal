This project demonstrates a prelimanary code to toggle on a LED connected to GPIO of MCU.

To turn the LED on, the following procedure is followed:
1. Enable clock to PORTB through AHB2ENR (AHB2 Enable Register) which is accessed through RCC(Reset and Clock Control) structure.
2. Select PB3 as an general purpose output using MODER(Mode Register)
3. Enable output on PB3 through ODR(Output Data Register).


- AHB2ENR (AHB2 Enable Register, Refer RM Page 214)

| 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
|    |    |    |    |    |    |    |    |    |    |    |    |    | RNG_EN | | AESEN |

| 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| | | ADCEN | | | | | GPIOHEN | | | GPIOEEN | GPIODEN | GPIOCEN | GPIOBEN | GPIOAEN |

- GPIOx_MODER (x = A,B,C...,H, refer page 263 of RM)

| 31 30 | 29 28 | 27 26 | 25 24 | 23 22 | 21 20 | 19 18 | 17 16 |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| MODER15 | MODER14 | 


- 00 : Input (default state)
- 01 : General purpose output
- 10 : Alternate Function mode
- 11 : Analog mode
