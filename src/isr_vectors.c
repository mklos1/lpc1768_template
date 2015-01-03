/* Adres wskazuje na ostatnie podwojne slowo w pamieci SRAM.
 * STM32F103 maja 20kB SRAM.
 */
#include "stm32f10x.h"
#include "zl27arm_leds.h"
#include "zl27arm_buttons.h"

#define STACK_POINTER 0x20004FFC

#define RAMFUNC __attribute__ ((long_call, section (".ramsection")))

extern int main(void);

void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void Usage_Handler(void);
void SVCall_Handler(void);
void DebugMonitor_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void WWDG_Handler(void);
void PVD_Handler(void);
void Tamper_Handler(void);
void RTC_Handler(void);
void Flash_Handler(void);
void RCC_Handler(void);
void EXTI0_Handler(void);
void EXTI1_Handler(void);
void EXTI2_Hander(void);
void EXTI3_Hander(void);
void EXTI4_Hander(void);
void DMA1_CH1_Handler(void);
void DMA1_CH2_Handler(void);
void DMA1_CH3_Handler(void);
void DMA1_CH4_Handler(void);
void DMA1_CH5_Handler(void);
void DMA1_CH6_Handler(void);
void DMA1_CH7_Handler(void);
void ADC12_Handler(void);
void USB_HP_CAN_TX_Handler(void);
void USB_LP_CAN_RX0_Handler(void);
void CAN_RX1_Handler(void);
void CAN_SCE_Handler(void);
void EXTI95_Handler(void);
void TIM1_BRK_Handler(void);
void TIM1_UP_Handler(void);
void TIM1_TRG_COM_Handler(void);
void TIM1_CC_Handler(void);
void TIM2_Handler(void);
void TIM3_Handler(void);
void TIM4_Handler(void);
void I2C1_EV_Handler(void);
void I2C1_ER_Handler(void);
void I2C2_EV_Handler(void);
void I2C2_ER_Handler(void);
void SPI1_Handler(void);
void SPI2_Handler(void);
void USART1_Handler(void);
void USART2_Handler(void);
void USART3_Handler(void);
void EXTI1510_Handler(void);
void RTCAlarm_Handler(void);
void USBWakeup_Handler(void);
void TIM8_BRK_Handler(void);
void TIM8_UP_Handler(void);
void TIM8_TRG_COM_Handler(void);
void ADC3_Handler(void);
void FSMC_Handler(void);
void SDIO_Handler(void);
void TIM5_Handler(void);
void SPI3_Handler(void);
void UART4_Handler(void);
void UART5_Handler(void);
void TIM6_Handler(void);
void TIM7_Handler(void);
void DMA2_CH1_Handler(void);
void DMA2_CH2_Handler(void);
void DMA2_CH3_Handler(void);
void DMA2_CH45_Handler(void);

extern unsigned int* _flash_data_start;
extern unsigned int* _data_start;
extern unsigned int* _data_end;
extern unsigned int* _bss_start;
extern unsigned int* _bss_end;

__attribute__ ((section(".isr_vectors")))
void (*const vector_table[]) (void) = {
	(void*) STACK_POINTER,
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	Usage_Handler,
	0,
	0,
	0,
	0,
	SVCall_Handler,
	DebugMonitor_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,
	WWDG_Handler,
	PVD_Handler,
	Tamper_Handler,
	RTC_Handler,
	Flash_Handler,
	RCC_Handler,
	EXTI0_Handler,
	EXTI1_Handler,
	EXTI2_Hander,
	EXTI3_Hander,
	EXTI4_Hander,
	DMA1_CH1_Handler,
	DMA1_CH2_Handler,
	DMA1_CH3_Handler,
	DMA1_CH4_Handler,
	DMA1_CH5_Handler,
	DMA1_CH6_Handler,
	DMA1_CH7_Handler,
	ADC12_Handler,
	USB_HP_CAN_TX_Handler,
	USB_LP_CAN_RX0_Handler,
	CAN_RX1_Handler,
	CAN_SCE_Handler,
	EXTI95_Handler,
	TIM1_BRK_Handler,
	TIM1_UP_Handler,
	TIM1_TRG_COM_Handler,
	TIM1_CC_Handler,
	TIM2_Handler,
	TIM3_Handler,
	TIM4_Handler,
	I2C1_EV_Handler,
	I2C1_ER_Handler,
	I2C2_EV_Handler,
	I2C2_ER_Handler,
	SPI1_Handler,
	SPI2_Handler,
	USART1_Handler,
	USART2_Handler,
	USART3_Handler,
	EXTI1510_Handler,
	RTCAlarm_Handler,
	USBWakeup_Handler,
	TIM8_BRK_Handler,
	TIM8_UP_Handler,
	TIM8_TRG_COM_Handler,
	ADC3_Handler,
	FSMC_Handler,
	SDIO_Handler,
	TIM5_Handler,
	SPI3_Handler,
	UART4_Handler,
	UART5_Handler,
	TIM6_Handler,
	TIM7_Handler,
	DMA2_CH1_Handler,
	DMA2_CH2_Handler,
	DMA2_CH3_Handler,
	DMA2_CH45_Handler,
};

void Reset_Handler(void)
{
	unsigned int* flash = _flash_data_start;
	unsigned int* ram = _data_start;
	while (ram < _data_end) {
		*(ram++) = *(flash++);
	}
	ram = _bss_start;
	while (ram < _bss_end) {
		*(ram++) = 0;
	}
	main();
	NVIC_SystemReset(); //Soft-reset na wypadek, gdyby main() jednak wyszła
}

void __attribute__((weak)) NMI_Handler(void)
{
	while(1);
}

void __attribute__((weak)) HardFault_Handler(void)
{
	GPIO_WriteBit(LED1_PORT, LED8_PIN, Bit_SET);
	while(1);
}

void __attribute__((weak)) MemManage_Handler(void){
	while(1);
}

void __attribute__((weak)) BusFault_Handler(void){
	while(1);
}

void __attribute__((weak)) Usage_Handler(void){
	while(1);
}

void __attribute__((weak)) SVCall_Handler(void){
	while(1);
}

void __attribute__((weak)) DebugMonitor_Handler(void){
	while(1);
}

void __attribute__((weak)) PendSV_Handler(void){
	while(1);
}

void __attribute__((weak)) SysTick_Handler(void){
	while(1);
}

void __attribute__((weak)) WWDG_Handler(void){
	while(1);
}

void __attribute__((weak)) PVD_Handler(void){
	while(1);
}

void __attribute__((weak)) Tamper_Handler(void){
	while(1);
}

void __attribute__((weak)) RTC_Handler(void){
	while(1);
}

void __attribute__((weak)) Flash_Handler(void){
	while(1);
}

void __attribute__((weak)) RCC_Handler(void){
	while(1);
}

void __attribute__((weak)) EXTI0_Handler(void){
	#ifdef ZL27ARM_SW0
		zl27arm_SW0_interrupt();
	#endif
}

void __attribute__((weak)) EXTI1_Handler(void){
	#ifdef ZL27ARM_SW1
		zl27arm_SW1_interrupt();
	#endif
}

void __attribute__((weak)) EXTI2_Hander(void){
	#ifdef ZL27ARM_SW2
		zl27arm_SW2_interrupt();
	#endif
}

void __attribute__((weak)) EXTI3_Hander(void){
	#ifdef ZL27ARM_SW3
		zl27arm_SW3_interrupt();
	#endif
}

void __attribute__((weak)) EXTI4_Hander(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH1_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH2_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH3_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH4_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH5_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH6_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA1_CH7_Handler(void){
	while(1);
}

void __attribute__((weak)) ADC12_Handler(void){
	while(1);
}

void __attribute__((weak)) USB_HP_CAN_TX_Handler(void){
	while(1);
}

void __attribute__((weak)) USB_LP_CAN_RX0_Handler(void){
	while(1);
}

void __attribute__((weak)) CAN_RX1_Handler(void){
	while(1);
}

void __attribute__((weak)) CAN_SCE_Handler(void){
	while(1);
}

void __attribute__((weak)) EXTI95_Handler(void){
	#ifdef ZL27ARM_JOY
		void zl27arm_joy_enter_interrupt(void);
	#endif
	while(1);
}

void __attribute__((weak)) TIM1_BRK_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM1_UP_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM1_TRG_COM_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM1_CC_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM2_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM3_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM4_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C1_EV_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C1_ER_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C2_EV_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C2_ER_Handler(void){
	while(1);
}

void __attribute__((weak)) SPI1_Handler(void){
	while(1);
}

void __attribute__((weak)) SPI2_Handler(void){
	while(1);
}

void __attribute__((weak)) USART1_Handler(void){
	while(1);
}

void __attribute__((weak)) USART2_Handler(void){
	while(1);
}

void __attribute__((weak)) USART3_Handler(void){
	while(1);
}

void __attribute__((weak)) EXTI1510_Handler(void){
	while(1);
}

void __attribute__((weak)) RTCAlarm_Handler(void){
	while(1);
}

void __attribute__((weak)) USBWakeup_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM8_BRK_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM8_UP_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM8_TRG_COM_Handler(void){
	while(1);
}

void __attribute__((weak)) ADC3_Handler(void){
	while(1);
}

void __attribute__((weak)) FSMC_Handler(void){
	while(1);
}

void __attribute__((weak)) SDIO_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM5_Handler(void){
	while(1);
}

void __attribute__((weak)) SPI3_Handler(void){
	while(1);
}

void __attribute__((weak)) UART4_Handler(void){
	while(1);
}

void __attribute__((weak)) UART5_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM6_Handler(void){
	while(1);
}

void __attribute__((weak)) TIM7_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA2_CH1_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA2_CH2_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA2_CH3_Handler(void){
	while(1);
}

void __attribute__((weak)) DMA2_CH45_Handler(void){
	while(1);
}
