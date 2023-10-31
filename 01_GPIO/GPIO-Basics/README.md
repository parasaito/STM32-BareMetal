# General Purpose Output - Glowing an LED

This project demonstrates a prelimanary code to toggle on a LED connected to GPIO of MCU.

To turn the LED on, the following procedure is followed:
1. Enable clock to `PORTB` through `AHB2ENR` (AHB2 Enable Register) which is accessed through `RCC`(Reset and Clock Control) module.
2. Select `PB3` as an general purpose output using `MODER`(Mode Register)
3. Enable output on `PB3` through `ODR`(Output Data Register).

---

### AHB2ENR (AHB2 Enable Register, Refer RM Page 214)

| 31 | 30 | 29 | 28 | 27 | 26 | 25 | 24 | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 |
| -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| -  |  -  |  -  |  -  |  -  |  -  | -   | -   | -   |  -  |  -  |  -  |   - | RNG_EN | - | AESEN |

| 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
| -- | -- | -- | -- | -- | -- | - | - | - | - | - | - | - | - | - | - |
| -- | - | ADCEN | - | - | - | - | - | GPIOHEN | - | - | GPIOEEN | GPIODEN | GPIOCEN | GPIOBEN | GPIOAEN |

---

### GPIOx_MODER (x = A,B,C...,H, refer page 263 of RM)

| 31 - 30 | 29 - 28 | 27 - 26 | 25 - 24 | 23 - 22 | 21 - 20 | 19 - 18 | 17 - 16 |
| ------- | ------- | ------- | ------- | ------- | ------- | ------- | ------- |
| MODER15 | MODER14 | MODER13 | MODER12 | MODER11 | MODER10 | MODER9  | MODER8  |

| 15 - 14 | 13 - 12 | 11 - 10 | 9 - 8 | 7 - 6 | 5 - 4 | 3 - 2 | 1 - 0 |
| ------- | ------- | ------- | ----- | ----- | ----- | ----- | ----- |
| MODER7  | MODER6  | MODER5  | MODER4| MODER3| MODER2| MODER1| MODER0|


| y | MODERy associated GPIO Behavior | 
| - | ------------------------------- |
| 00| General Purpose **Input** |
| 01| General Purpose **Output** | 
| 10| **Alternate Function** Mode | 
| 11| **Analog** Mode |  


---

### Digital Input

Digital Input is often accompanied with the issue of Switch Bounce. If you are unsure what switch bounce is, then check out this execellent [video](https://www.youtube.com/watch?v=IvU8m_30iK0&pp=ygUNc3dpdGNoIGJvdW5jZQ%3D%3D) by Digikey.

Eliminating  switch bounce can be achieved in two ways : 

### Software debounce

This involves waiting a cetain period between reading two consecutive switch states. 
As soon as switch contacts touch, we follow up our code with a delay. Switch bounce typically lasts for 5-10 ms, this is the amount of delay we would introduce. After the delay, we again check the state of the switch, and accordingly make further decisions.

### Hardware debounce

We employ hardware to eliminate the bounce signal, thus removing the noise received at microcontroller pin altogether. There are various ways of implementing a debouncing circuit including using a Schmitt trigger or even dedicated debouncer chip, but we shall discuss the simplest circuit - an RC network.