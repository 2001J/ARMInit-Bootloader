#include "uart.h"
#include "system.h"

#define BOOTLOADER_VERSION "1.0.0"
#define BUILD_DATE __DATE__
#define BUILD_TIME __TIME__


void print_bootloader_info(void) {
    uart_puts("\r\n=== Bootloader Info ===\r\n");
    uart_puts("Version: ");
    uart_puts(BOOTLOADER_VERSION);
    uart_puts("\r\nBuild: ");
    uart_puts(BUILD_DATE);
    uart_puts(" ");
    uart_puts(BUILD_TIME);
    uart_puts("\r\nTarget: LM3S6965\r\n");
    uart_puts("===================\r\n");
}

int main(void) {
    uart_init();
    
    uart_puts("Bootloader v1.0\r\n");
    
    // Now we can use system functions
    system_status_t status = system_get_status();
    uart_puts("System clock: ");
    print_hex(status.clock_freq);
    uart_puts("\r\n");
    
    while(1) {
        char cmd = uart_getc();
        switch(cmd) {
            case 'i':
                print_bootloader_info();
                break;
            case 'r':
                uart_puts("Resetting...\r\n");
                system_reset();
                break;
            case 's':
                status = system_get_status();
                uart_puts("Stack ptr: ");
                print_hex(status.stack_ptr);
                uart_puts("\r\n");
                break;
        }
    }
}