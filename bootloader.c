#include "uart.h"
#include "system.h"

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