// system.h
#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

// print_hex declaration
void print_hex(uint32_t num);

// System initialization
void system_init(void);

// System control
void system_reset(void);
void system_halt(void);
uint32_t system_get_clock(void);

// System status
typedef struct {
    uint32_t clock_freq;
    uint32_t stack_ptr;
    uint32_t reset_count;
} system_status_t;

system_status_t system_get_status(void);

// System registers
#define SYSCTRL_BASE     0x400FE000
#define RCGCUART        (*((volatile uint32_t *)(SYSCTRL_BASE + 0x104)))
#define RCGCGPIO        (*((volatile uint32_t *)(SYSCTRL_BASE + 0x108)))

#endif