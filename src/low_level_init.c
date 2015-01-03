#include "low_level_init.h"

#include "stm32f10x.h"
#include "zl27arm_leds.h"
#include "zl27arm_buttons.h"

void clocks_init(void);
void interrupts_init(void);



void MCU_init(void) {

	clocks_init();
	interrupts_init();

	RCC_ClockSecuritySystemCmd(ENABLE);

	zl27arm_leds_init();
	zl27arm_buttons_init();

}

void clocks_init(void) {
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	if (RCC_WaitForHSEStartUp() == SUCCESS) {
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_8);
		RCC_PLLCmd(ENABLE);
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		RCC_HCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while (RCC_GetSYSCLKSource() != 0x08);
		} else {
			while(1);
		}

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | \
			RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);

}

void interrupts_init(void) {
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = RCC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/* Przerwanie NMI jest generowane m. in. przez system nadzoru zegara. Jeżeli zegar zewnętrzny
 * padnie, wtedy można przełączyć się na zegar wewnętrzny. Niestety, aby płynnie przechodzić między
 * domenami zegara bez zmiany konfiguracji peryferiów, zegar systemowy nie może być szybszy niż maks
 * co się dla uzyskać PLL napędzanej z HSI, czyli 64MHz. Obsługa jest mało koszerna, gdyż trwa długo
 * ale jak pada zegar, to chyba jest to mało ważne, czy obsługjemy inne przerwania, ważne, żeby
 * przywrócić system do działania.
 */
void NMI_Handler(void)
{
	if (RCC_GetITStatus(RCC_IT_CSS) == SET) {
		RCC_HSEConfig(RCC_HSE_ON);
		if (RCC_WaitForHSEStartUp() == SUCCESS) {
			RCC_PLLCmd(ENABLE);
			while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
			while (RCC_GetSYSCLKSource() != 0x08);
		} else {
			RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_16);
			RCC_PLLCmd(ENABLE);
			while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
			RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
			while (RCC_GetSYSCLKSource() != 0x08);
		}
		RCC_ClearITPendingBit(RCC_IT_CSS);
	}
}

