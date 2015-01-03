ENTRY (Reset_Handler)

MEMORY
{
    RAM1 (rwx) : ORIGIN = 0x10000000, LENGTH = 32K
    RAM2 (rwx) : ORIGIN = 0x2007C000, LENGTH = 16K
    RAM3 (rwx) : ORIGIN = 0x20080000, LENGTH = 16K
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 512K
}

SECTIONS
{
    .  = 0x0;        
    .isr_vectors : 
    {
    	. = ALIGN(4);
    	KEEP(*(.isr_vectors))
    	. = ALIGN(4);
    } >FLASH
    
    .text :
    {
        *(.text)   
		*(.text.*) 
        *(.rodata)
        *(.rodata*)   
        . = ALIGN(4);
        _flash_data_start = .;
    } >FLASH
    
    .data : AT (_flash_data_start)
    {
    	. = ALIGN(4);
    	_data_start = .;
        *(.data)
        *(.data.*)
        *(.ramsection)
        _data_end = .;
    } >RAM1

    .bss :
    {
    	. = ALIGN(4);
    	_bss_start = .;
        *(.bss)       
        _bss_end = .;
    } >RAM1
    
}
