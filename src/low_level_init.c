#include "low_level_init.h"
#include "lpc17xx.h"
#include "bit_numbers.h"


void clocks_init(void);
void interrupts_init(void);

void MCU_init(void) {

	clocks_init();
	interrupts_init();

}

void clocks_init(void) {

	/* Wyłączamy wszystkie peryferia */
	LPC_SC->PCONP &= ~(BIT1 | BIT2 | BIT3 | BIT4 | BIT6 | BIT7 | BIT8 | BIT9 \
		| BIT10 | BIT12 | BIT13 | BIT14 | BIT15 | BIT16 | BIT17 | BIT18 \
		| BIT19 | BIT21 | BIT22 | BIT23 | BIT24 | BIT25 | BIT25 | BIT26 \
		| BIT27 | BIT29 | BIT30 | BIT31);

	/* Zakres głównego oscylatora 1-20MHz */
	LPC_SC->SCS &= ~BIT4;

	/* Włączamy główny oscylator  i czekamy na jego uruchomienie */
	LPC_SC->SCS |= BIT5;
	while ((LPC_SC->SCS & BIT5) == 0);

	/* Podłączamy główny oscylator do pętli */
	LPC_SC->CLKSRCSEL |= BIT0;

	/* Mnożnik na 12, dzielnik na 1, co powinno dać 288MHz na PLL, dzielnik
	 * na wejściu rdzenia na 3 */
	LPC_SC->PLL0CFG = 11;
	LPC_SC->CCLKCFG = 3;
	LPC_SC->PLL0CON = BIT0;

	/* Sekwencja aktualizująca rejestry w PLL0 */
	LPC_SC->PLL0FEED = 0xAA;
	LPC_SC->PLL0FEED = 0x55;

	/* Czekam na rozpędzenie się pętli. Potem sprawdzamy czy
	 * pętla działa i jest podłączona. Jeżeli nie, umieramy w martwej pętli
	 */
	while((LPC_SC->PLL0STAT & BIT26) == 0);
	LPC_SC->PLL0CON |= BIT1;
	LPC_SC->PLL0FEED = 0xAA;
	LPC_SC->PLL0FEED = 0x55;
	if ((LPC_SC->PLL0STAT & BIT24) == 0 || (LPC_SC->PLL0STAT & BIT25) == 0) {
		while(1);
	}

	/* Ustawienie buforowania pamięci flash */
	LPC_SC->FLASHCFG = BIT14;

	/* Ustawiamy zegary dla peryferiów na pllclk/2 */
	LPC_SC->PCLKSEL1 = BIT3 | BIT5 | BIT29;

	/* Włączamy peryferia, które potrzeba */
	LPC_SC->PCONP = BIT15;

}

void interrupts_init(void) {

}


void NMI_Handler(void)
{

}

