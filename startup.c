#include <stdint.h>

extern uint32_t _estack;
extern int main(void);

void Reset_Handler(void);
void Default_Handler(void);

// Minimal vector table
__attribute__((section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    (void (*)(void))(&_estack),
    Reset_Handler,
    Default_Handler,  // NMI
    Default_Handler,  // Hard Fault
};

void Reset_Handler(void) {
    // Start main program
    main();
    
    // Loop forever if main returns
    while(1);
}

void Default_Handler(void) {
    while(1);
}