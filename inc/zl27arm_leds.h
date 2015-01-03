#ifndef _ZL27ARM_LEDS_H
#define _ZL27ARM_LEDS_H

#define ZL27ARM_LED1
#define ZL27ARM_LED2
#define ZL27ARM_LED3
#define ZL27ARM_LED4
#define ZL27ARM_LED5
#define ZL27ARM_LED6
#define ZL27ARM_LED7
#define ZL27ARM_LED8

#ifdef ZL27ARM_LED1
	#define LED1_PORT		GPIOB
	#define LED1_PIN		GPIO_Pin_8
	void zl27arm_led1(unsigned int _state);
#endif
#ifdef ZL27ARM_LED2
	#define LED2_PORT		GPIOB
	#define LED2_PIN		GPIO_Pin_9
	void zl27arm_led2(unsigned int _state);
#endif
#ifdef ZL27ARM_LED3
	#define LED3_PORT		GPIOB
	#define LED3_PIN		GPIO_Pin_10
	void zl27arm_led3(unsigned int _state);
#endif
#ifdef ZL27ARM_LED4
	#define LED4_PORT		GPIOB
	#define LED4_PIN		GPIO_Pin_11
	void zl27arm_led4(unsigned int _state);
#endif
#ifdef ZL27ARM_LED5
	#define LED5_PORT		GPIOB
	#define LED5_PIN		GPIO_Pin_12
	void zl27arm_led5(unsigned int _state);
#endif
#ifdef ZL27ARM_LED6
	#define LED6_PORT		GPIOB
	#define LED6_PIN		GPIO_Pin_13
	void zl27arm_led6(unsigned int _state);
#endif
#ifdef ZL27ARM_LED7
	#define LED7_PORT		GPIOB
	#define LED7_PIN		GPIO_Pin_14
	void zl27arm_led7(unsigned int _state);
#endif
#ifdef ZL27ARM_LED8
	#define LED8_PORT		GPIOB
	#define LED8_PIN		GPIO_Pin_15
	void zl27arm_led8(unsigned int _state);
#endif

#define LED_ON			1
#define LED_OFF			0

void zl27arm_leds_init(void);

#endif
