ENTRY (Reset_Handler)

MEMORY
{
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
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
    } >RAM

    .bss :
    {
    	. = ALIGN(4);
    	_bss_start = .;
        *(.bss)       
        _bss_end = .;
    } >RAM
    
}