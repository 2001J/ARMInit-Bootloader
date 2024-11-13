// uart.h
#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_putc(char c);
void uart_puts(const char* str);
char uart_getc(void);

#endif