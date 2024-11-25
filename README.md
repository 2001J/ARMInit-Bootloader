# ARMInit BootLoader
A bare-metal bootloader implementation for the Texas Instruments LM3S6965 microcontroller.


## Overview

This bootloader provides basic system initialization and UART-based communication for the ARM Cortex-M3 based LM3S6965 microcontroller. It currently supports system monitoring, reset functionality, and status reporting.


## Features
- UART communication (115200 baud, 8N1)
- System clock initialization (50MHz)
- Stack pointer monitoring
- System reset capability
- Interactive command interface
- 
### Commands
- `i` - Display bootloader version and build info
- `r` - Trigger system reset
- `s` - Show current stack pointer

## Architecture

### Memory Layout
- Flash Memory: 0x00000000 - 0x40000 (256KB)
    - Bootloader: 0x00000000 - 0x4000
    - Vector Table: 0x00000000 - 0x200
- SRAM: 0x20000000 - 0x10000 (64KB)
    - Stack: Top of SRAM
- Peripherals:
    - UART0: 0x4000C000
    - System Control: 0x400FE000

### Implementation Details
- ARM Cortex-M3 initialization
- Vector table setup
- System clock configuration (50MHz)
- UART0 configuration (115200 baud)
- Reset handler implementation
- Stack pointer initialization
### Error Codes
- Status codes to be implemented in future versions

## Prerequisites
- arm-none-eabi-gcc toolchain
- QEMU for ARM emulation
- Make build system



## Building the BareMetalVM Project

1. Clone the BareMetalVM repository:
   ```sh
   git clone https://github.com/2001J/ARMInit
   
   cd ARMInit
   ```

2. Build the project:
   ```sh
   make
   ```

## Running the ARMInit BootLoader Program

To run the ARMInit-Bootloader program, use the following command:
   ```sh
   make run
   ```

## License

This project is licensed under the Apache License.

## Author

Joseph Paul Koyi
