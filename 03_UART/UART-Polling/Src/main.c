#include "stm32l432xx.h"
#include "uart.h"

#define LED_RED_SET		(GPIOB->BSRR = GPIO_BSRR_BS3)
#define LED_RED_CLR		(GPIOB->BSRR = GPIO_BSRR_BR3)

#define LED_GREEN_SET	(GPIOB->BSRR = GPIO_BSRR_BS5)
#define LED_GREEN_CLR	(GPIOB->BSRR = GPIO_BSRR_BR5)

#define LED_BLUE_SET	(GPIOB->BSRR = GPIO_BSRR_BS4)
#define LED_BLUE_CLR	(GPIOB->BSRR = GPIO_BSRR_BR4)


int main() {

	char option = '0';
	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	
	GPIOB->MODER &= ~ 	(	0x3U << GPIO_MODER_MODE3_Pos
						|	0x3U << GPIO_MODER_MODE4_Pos	
						|	0x3U << GPIO_MODER_MODE5_Pos
						);

	GPIOB->MODER |= 	(	0x1U << GPIO_MODER_MODE3_Pos
						|	0x1U << GPIO_MODER_MODE4_Pos
						|	0x1U <<	GPIO_MODER_MODE5_Pos
						);
	
	//Turn OFF all LEDs
	GPIOB->BSRR = GPIO_BSRR_BR3	| GPIO_BSRR_BR4 | GPIO_BSRR_BR5;
	
	uart_init(115200);
	
	while (1) {
		uart_puts("\r\nSelect a Color (R/G/B) : ");
		
		uart_getc(&option);

		uart_putc(option);
		
		switch (option) {
			case 'r':
			case 'R':
					LED_GREEN_CLR;
					LED_BLUE_CLR;
					LED_RED_SET;
					break;
			case 'g':
			case 'G':
					LED_BLUE_CLR;
					LED_RED_CLR;
					LED_GREEN_SET;
					break;
			case 'b':
			case 'B':
					LED_RED_CLR;
					LED_GREEN_CLR;
					LED_BLUE_SET;
					break;
			default:
					uart_puts("\r\nERROR! Invalid Choice\r\n");
					break;
		}
	}
	
	return 0;
}
