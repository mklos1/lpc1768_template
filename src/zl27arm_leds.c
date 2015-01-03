#include "zl27arm_leds.h"

#include "stm32f10x.h"

void zl27arm_leds_init(void) {

	GPIO_InitTypeDef GPIO_InitStructure;

#ifdef ZL27ARM_LED1
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED1_PORT, LED1_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED2
	GPIO_InitStructure.GPIO_Pin = LED2_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED2_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED2_PORT, LED2_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED3
	GPIO_InitStructure.GPIO_Pin = LED3_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED3_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED3_PORT, LED3_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED4
	GPIO_InitStructure.GPIO_Pin = LED4_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED4_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED4_PORT, LED4_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED5
	GPIO_InitStructure.GPIO_Pin = LED5_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED5_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED5_PORT, LED5_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED6
	GPIO_InitStructure.GPIO_Pin = LED6_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED6_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED6_PORT, LED6_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED7
	GPIO_InitStructure.GPIO_Pin = LED7_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED7_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED7_PORT, LED7_PIN, Bit_RESET);
#endif

#ifdef ZL27ARM_LED8
	GPIO_InitStructure.GPIO_Pin = LED8_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LED8_PORT, &GPIO_InitStructure);
	GPIO_WriteBit(LED8_PORT, LED8_PIN, Bit_RESET);
#endif

}

#ifdef ZL27ARM_LED1
inline void zl27arm_led1(unsigned int _state) {
	GPIO_WriteBit(LED1_PORT, LED1_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED2
inline void zl27arm_led2(unsigned int _state) {
	GPIO_WriteBit(LED2_PORT, LED2_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED3
inline void zl27arm_led3(unsigned int _state) {
	GPIO_WriteBit(LED3_PORT, LED3_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED4
inline void zl27arm_led4(unsigned int _state) {
	GPIO_WriteBit(LED4_PORT, LED4_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED5
inline void zl27arm_led5(unsigned int _state) {
	GPIO_WriteBit(LED5_PORT, LED5_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED6
inline void zl27arm_led6(unsigned int _state) {
	GPIO_WriteBit(LED6_PORT, LED6_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED7
inline void zl27arm_led7(unsigned int _state) {
	GPIO_WriteBit(LED7_PORT, LED7_PIN, (BitAction)_state);
}
#endif
#ifdef ZL27ARM_LED8
inline void zl27arm_led8(unsigned int _state) {
	GPIO_WriteBit(LED8_PORT, LED8_PIN, (BitAction)_state);
}
#endif
