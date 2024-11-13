MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
    SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .data : 
    {
        . = ALIGN(4);
        *(.data*)
        . = ALIGN(4);
    } > SRAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
    } > SRAM

    . = ALIGN(4);
    _estack = ORIGIN(SRAM) + LENGTH(SRAM);
}