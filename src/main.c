#include "stm32f10x.h"

#include "low_level_init.h"

static void enable_interrupts(void) {asm("cpsie i");}
static void disable_interrupts(void) {asm("cpsid i");}

/*
 * Trochę niekonwencjonalne użycie funkcji main. Zwykle jest tak, że funkcja main
 * zwraca wartość, ale gdy mamy tzw baremetal - czyli brak systemu operacyjnego
 * funkcja main nie może zwrócić wartości, gdyż zwykle jest wołana jako ostatnia w
 * wektorze resetu. Jeżeli funkcja main wyjdzie, a wektor resetu tego nie przewiduje
 * wtedy jest niebezpieczeństwo, że procesor zacznie wykonywać bliżej nieokreślony kod.
 */
void main(void) {

	MCU_init();
	while(1);
}

