#include "uart.h"
#include "stm32l432xx.h"
#include "system_stm32l4xx.h"

#include <stdint.h>

void uart_init(uint32_t baud) {

  	RCC->APB1ENR1 &= ~ (RCC_APB1ENR1_USART2EN);
  	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;
	
  	RCC->AHB2ENR &= ~ (RCC_AHB2ENR_GPIOAEN);
  	RCC->AHB2ENR |=	RCC_AHB2ENR_GPIOAEN;
	
  	GPIOA->MODER &= ~(	0x3UL << GPIO_MODER_MODE2_Pos 
	  			     | 	0x3UL << GPIO_MODER_MODE15_Pos
				     );
						
  	GPIOA->MODER |=	(	0x2UL << GPIO_MODER_MODE2_Pos 
  				   	| 	0x2UL << GPIO_MODER_MODE15_Pos
			  	   	);
	
	
  	GPIOA->AFR[0] &= ~ (0xFUL << GPIO_AFRL_AFSEL2_Pos);
  	GPIOA->AFR[0] |= 0x7UL << GPIO_AFRL_AFSEL2_Pos; 
	
  	GPIOA->AFR[1] &= ~ (0xFUL << GPIO_AFRH_AFSEL15_Pos);
  	GPIOA->AFR[1] |= 0x3UL << GPIO_AFRH_AFSEL15_Pos; 
	
  	// Disable USART before configuration
  	
  	USART2->CR1 &= ~ (USART_CR1_UE);		/* USART Enable bit */
  	
	USART2->CR1 &= ~(	(USART_CR1_M1 | USART_CR1_M0)	/* Word length - 00(8),01(9),10(7) */
					|	USART_CR1_EOBIE					/* End of Block Interrupt Enable */
					|	USART_CR1_RTOIE					/* RX Timeout Interrupt Enable */
					|	USART_CR1_DEAT					/* Driver Enable Assertion Time */
					|	USART_CR1_DEDT					/* Driver Enable De-assertion Time */
					|	USART_CR1_OVER8					/* Oversampling Mode - oversample by 16 on receiver */
					| 	USART_CR1_CMIE					/* Character Match Interrupt Enable */
					| 	USART_CR1_MME					/* Mute Mode Enable */
					|	USART_CR1_WAKE					/* Receiever Wake up method */
					|	USART_CR1_PCE					/* Parity Control Enable */
					|	USART_CR1_PS					/* Parity Selection */
					|	USART_CR1_PEIE					/* PE Interrupt Enable */
					|	USART_CR1_TXEIE					/* TX buffer Empty Interrupt Enable */
					|	USART_CR1_TCIE					/* TX Complete Interrupt Enable */
					|	USART_CR1_RXNEIE				/* RX buffer Not-Empty Interrupt Enable */
					|	USART_CR1_IDLEIE				/* IDLE Interrupt Enable */
					|	USART_CR1_TE					/* Transmitter Enable */
					|	USART_CR1_RE					/* Receiever Enable */
					|	USART_CR1_UESM					/* USART Enable in Stop Mode */
  				  	);
	
	USART1->CR2 &= ~( 	0xFF << USART_CR2_ADD_Pos				/* USART Node Address */
					|	USART_CR2_RTOEN							/* Receive Time Out Enable */
					|	USART_CR2_ABRMODE						/* Auto Baud Rate Mode */
					|	USART_CR2_ABREN							/* Auto Baud Rate Enable */
					|	USART_CR2_MSBFIRST						/* MSB First */
					|	USART_CR2_DATAINV						/* Data Inversion */
					|	USART_CR2_TXINV							/* TX Active level Inversion*/
					|	USART_CR2_RXINV							/* RX Active level inversion */
					|	USART_CR2_SWAP							/* Swap TX/RX Pins */
					|	USART_CR2_LINEN							/* LIN Mode Enable */
					|	0xFF << USART_CR2_STOP_Pos				/* STOP bits */
					|	USART_CR2_CLKEN							/* USART Clock Enable */
					|	0xFFF
					);
	
	USART1->CR3 &= ~(	USART_CR3_TCBGTIE
					|	USART_CR3_DEM	
		
					);
					
	USART1->CR3 |=	(	USART_CR3_OVRDIS
					|	USART_CR3_ONEBIT	
					);
				
  	USART2->BRR = (uint32_t)(SystemCoreClock / baud);

					
	//USART2->BRR = 35;	//testing 115200 baud for now
	
  	// Enable USART transmit and receive
  	USART2->CR1 |= 	(	USART_CR1_TE 			/* TX Enable */
  				 	| 	USART_CR1_RE			/* RX Enable */
			  	   	);
	
	USART2->CR1 |= USART_CR1_UE;

}

void uart_putc(char byte) 
{
  	while (! (USART2->ISR & USART_ISR_TXE));
	
  	USART2->TDR = 0xFFFF & byte;
}

void uart_puts(char *string) 
{
  	while (*string) {
  	  	uart_putc(*(string++));
  }
}

void uart_getc(char *data) 
{
	while (! (USART2->ISR & USART_ISR_RXNE));

	*data = USART2->RDR;
}
