// system.c
#include "system.h"
#include "uart.h"

// Static variables for system status
static volatile uint32_t s_reset_count = 0;
static volatile uint32_t s_clock_freq = 50000000; // Default 50MHz

void system_init(void) {
    // Enable UART and GPIO clocks
    RCGCUART |= 0x01;  // Enable UART0
    RCGCGPIO |= 0x01;  // Enable PORTA (UART pins)

    s_clock_freq = 50000000;  // Default 50MHz
    s_reset_count++;
    
    // Wait a few cycles for the clock to stabilize
    volatile uint32_t dummy;
    for(dummy = 0; dummy < 1000; dummy++);
}

void system_reset(void) {
    // System Control Block -> Application Interrupt and Reset Control Register
    volatile uint32_t* SCB_AIRCR = (volatile uint32_t*)0xE000ED0C;
    *SCB_AIRCR = 0x05FA0004;  // Write reset value with vector key
    while(1);  // Wait for reset
}

void system_halt(void) {
    // Disable all interrupts
    __asm volatile ("cpsid i");
    while(1);
}

uint32_t system_get_clock(void) {
    return s_clock_freq;
}

system_status_t system_get_status(void) {
    system_status_t status;
    
    status.clock_freq = s_clock_freq;
    status.reset_count = s_reset_count;
    
    // Get current stack pointer
    uint32_t sp;
    __asm volatile ("mov %0, sp" : "=r" (sp));
    status.stack_ptr = sp;
    
    return status;
}

void print_hex(uint32_t num) {
    char hex_chars[] = "0123456789ABCDEF";
    for(int i = 28; i >= 0; i -= 4) {
        uart_putc(hex_chars[(num >> i) & 0xF]);
    }
}