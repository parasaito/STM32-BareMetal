#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(uint32_t baud);

void uart_putc(char byte);

void uart_puts(char *string);

void uart_getc(char *data);

#endif 
