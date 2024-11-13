// uart.c
#include <stdint.h>
#include "uart.h"
#include "system.h"

// UART0 registers for LM3S6965
#define UART0_BASE 0x4000C000
#define UART0_DR   (*((volatile uint32_t *)(UART0_BASE + 0x000)))
#define UART0_FR   (*((volatile uint32_t *)(UART0_BASE + 0x018)))
#define UART0_IBRD (*((volatile uint32_t *)(UART0_BASE + 0x024)))
#define UART0_FBRD (*((volatile uint32_t *)(UART0_BASE + 0x028)))
#define UART0_LCRH (*((volatile uint32_t *)(UART0_BASE + 0x02C)))
#define UART0_CTL  (*((volatile uint32_t *)(UART0_BASE + 0x030)))

void uart_init(void) {
    
    system_init();
    // Enable UART0
    UART0_CTL |= 0x1;
    
    // Configure for 115200 baud, 8N1 operation
    UART0_IBRD = 27;  // Integer part
    UART0_FBRD = 8;   // Fractional part
    UART0_LCRH = 0x60; // 8-bit word length, no parity, one stop bit
}

void uart_putc(char c) {
    // Wait until UART is ready to transmit
    while(UART0_FR & (1<<5));
    UART0_DR = c;
}

char uart_getc(void) {
    // Wait until UART receives data
    while(UART0_FR & (1<<4));
    return (char)(UART0_DR & 0xFF);
}

void uart_puts(const char* str) {
    while(*str) {
        uart_putc(*str++);
    }
}