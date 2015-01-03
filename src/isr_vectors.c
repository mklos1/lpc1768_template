
#define STACK_POINTER 0x10007FFC

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
void WDG_Handler(void);
void Timer0_Handler(void);
void Timer1_Handler(void);
void Timer2_Handler(void);
void Timer3_Handler(void);
void Uart0_Handler(void);
void Uart1_Handler(void);
void Uart2_Handler(void);
void Uart3_Handler(void);
void PWM1_Handler(void);
void I2C0_Handler(void);
void I2C1_Handler(void);
void I2C2_Handler(void);
void SPI_Handler(void);
void SSP0_Handler(void);
void SSP1_Handler(void);
void PLL0_Handler(void);
void RTC_Handler(void);
void EINT0_Handler(void);
void EINT1_Handler(void);
void EINT2_Handler(void);
void EINT3_Handler(void);
void ADC_Handler(void);
void BOD_Handler(void);
void USB_Handler(void);
void CAN_Handler(void);
void GPDMA_Handler(void);
void I2S_Handler(void);
void ETH_Handler(void);
void RIT_Handler(void);
void ETH_Handler(void);
void MCPWM_Handler(void);
void QE_Handler(void);
void PLL1_Handler(void);
void ETH_Handler(void);
void USBAI_Handler(void);
void CANAI_Handler(void);


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
	WDG_Handler,
	Timer0_Handler,
	Timer1_Handler,
	Timer2_Handler,
	Timer3_Handler,
	Uart0_Handler,
	Uart1_Handler,
	Uart2_Handler,
	Uart3_Handler,
	PWM1_Handler,
	I2C0_Handler,
	I2C1_Handler,
	I2C2_Handler,
	SPI_Handler,
	SSP0_Handler,
	SSP0_Handler,
	PLL0_Handler,
	RTC_Handler,
	EINT0_Handler,
	EINT1_Handler,
	EINT2_Handler,
	EINT3_Handler,
	ADC_Handler,
	BOD_Handler,
	USB_Handler,
	CAN_Handler,
	GPDMA_Handler,
	I2S_Handler,
	ETH_Handler,
	RIT_Handler,
	ETH_Handler,
	MCPWM_Handler,
	QE_Handler,
	PLL1_Handler,
	ETH_Handler,
	USBAI_Handler,
	CANAI_Handler,
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
}

void __attribute__((weak)) NMI_Handler(void)
{
	while(1);
}

void __attribute__((weak)) HardFault_Handler(void)
{
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

void __attribute__((weak)) WDG_Handler(void){
	while(1);
}

void __attribute__((weak)) Timer0_Handler(void){
	while(1);
}

void __attribute__((weak)) Timer1_Handler(void){
	while(1);
}

void __attribute__((weak)) Timer2_Handler(void){
	while(1);
}

void __attribute__((weak)) Timer3_Handler(void){
	while(1);
}

void __attribute__((weak)) Uart0_Handler(void){
	while(1);
}

void __attribute__((weak)) Uart1_Handler(void){
	while(1);
}

void __attribute__((weak)) Uart2_Handler(void){
	while(1);
}

void __attribute__((weak)) Uart3_Handler(void){
	while(1);
}

void __attribute__((weak)) PWM1_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C0_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C1_Handler(void){
	while(1);
}

void __attribute__((weak)) I2C2_Handler(void){
	while(1);
}

void __attribute__((weak)) SPI_Handler(void){
	while(1);
}

void __attribute__((weak)) SSP0_Handler(void){
	while(1);
}

void __attribute__((weak)) SSP1_Handler(void){
	while(1);
}

void __attribute__((weak)) PLL0_Handler(void){
	while(1);
}

void __attribute__((weak)) RTC_Handler(void){
	while(1);
}

void __attribute__((weak)) EINT0_Handler(void){
	while(1);
}

void __attribute__((weak)) EINT1_Handler(void){
	while(1);
}

void __attribute__((weak)) EINT2_Handler(void){
	while(1);
}

void __attribute__((weak)) EINT3_Handler(void){
	while(1);
}

void __attribute__((weak)) ADC_Handler(void){
	while(1);
}

void __attribute__((weak)) BOD_Handler(void){
	while(1);
}

void __attribute__((weak)) USB_Handler(void){
	while(1);
}

void __attribute__((weak)) CAN_Handler(void){
	while(1);
}

void __attribute__((weak)) GPDMA_Handler(void){
	while(1);
}

void __attribute__((weak)) I2S_Handler(void){
	while(1);
}

void __attribute__((weak)) ETH_Handler(void){
	while(1);
}

void __attribute__((weak)) RIT_Handler(void){
	while(1);
}

void __attribute__((weak)) MCPWM_Handler(void){
	while(1);
}

void __attribute__((weak)) QE_Handler(void){
	while(1);
}

void __attribute__((weak)) PLL1_Handler(void){
	while(1);
}

void __attribute__((weak)) USBAI_Handler(void){
	while(1);
}

void __attribute__((weak)) CANAI_Handler(void){
	while(1);
}

