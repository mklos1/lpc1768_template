#ifndef _ZL27ARM_BUTTONS_H
#define _ZL27ARM_BUTTONS_H

#include "stm32f10x.h"

#define ZL27ARM_SW0
#define ZL27ARM_SW1
#define ZL27ARM_SW2
#define ZL27ARM_SW3

#define ZL27ARM_JOY

#ifdef ZL27ARM_SW0
	#define SW0_PORT		GPIOA
	#define SW0_PIN			GPIO_Pin_0
	#define SW0_INTPORT		GPIO_PortSourceGPIOA
	#define SW0_INTPIN		GPIO_PinSource0
	#define SW0_EXTI_LINE	EXTI_Line0
	#define SW0_INT			EXTI0_IRQn
	inline void zl27arm_SW0_interrupt(void) {
		if (EXTI_GetITStatus(EXTI_Line0) == SET) {
			EXTI_ClearITPendingBit(EXTI_Line0);
		}
	}
#endif

#ifdef ZL27ARM_SW1
	#define SW1_PORT		GPIOA
	#define SW1_PIN			GPIO_Pin_1
	#define SW1_INTPORT		GPIO_PortSourceGPIOA
	#define SW1_INTPIN		GPIO_PinSource1
	#define SW1_EXTI_LINE	EXTI_Line1
	#define SW1_INT			EXTI1_IRQn
	inline void zl27arm_SW1_interrupt(void) {
		if (EXTI_GetITStatus(EXTI_Line1) == SET) {
			EXTI_ClearITPendingBit(EXTI_Line1);
		}
	}
#endif

#ifdef ZL27ARM_SW2
	#define SW2_PORT		GPIOA
	#define SW2_PIN			GPIO_Pin_2
	#define SW2_INTPORT		GPIO_PortSourceGPIOA
	#define SW2_INTPIN		GPIO_PinSource2
	#define SW2_EXTI_LINE	EXTI_Line2
	#define SW2_INT			EXTI2_IRQn
	inline void zl27arm_SW2_interrupt(void) {
		if (EXTI_GetITStatus(EXTI_Line2) == SET) {
			EXTI_ClearITPendingBit(EXTI_Line2);
		}
	}
#endif

#ifdef ZL27ARM_SW3
	#define SW3_PORT		GPIOA
	#define SW3_PIN			GPIO_Pin_3
	#define SW3_INTPORT		GPIO_PortSourceGPIOA
	#define SW3_INTPIN		GPIO_PinSource3
	#define SW3_EXTI_LINE	EXTI_Line3
	#define SW3_INT			EXTI3_IRQn
	inline void zl27arm_SW3_interrupt(void) {
		if (EXTI_GetITStatus(EXTI_Line3) == SET) {
			EXTI_ClearITPendingBit(EXTI_Line3);
		}
	}
#endif

#ifdef ZL27ARM_JOY
	#if !defined(ZL27ARM_SW0) || !defined(ZL27ARM_SW1) || !defined(ZL27ARM_SW2) || !defined(ZL27ARM_SW3)
		#error "Joystrick wymaga także definicji SW0, SW1, SW2 i SW3."
	#endif
	#define JOY_ENTER_PORT		GPIOC
	#define JOY_ENTER_PIN		GPIO_Pin_5
	#define JOY_ENTER_INTPORT	GPIO_PortSourceGPIOC
	#define JOY_ENTER_INTPIN	GPIO_PinSource5
	#define JOY_ENTER_EXTI_LINE	EXTI_Line5
	#define JOY_ENTER_INT		EXTI9_5_IRQn
	inline void zl27arm_joy_enter_interrupt(void) {
		if (EXTI_GetITStatus(EXTI_Line5) == SET) {
			EXTI_ClearITPendingBit(EXTI_Line5);
		}
	}
#endif

void zl27arm_buttons_init(void);

#endif
