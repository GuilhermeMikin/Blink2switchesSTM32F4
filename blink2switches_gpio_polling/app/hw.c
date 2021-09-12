/*
 * hw.c
 *
 *  Created on: Sep 11, 2021
 *      Author: mikin
 */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"


bool hw_switch_state_get(void)
{
	GPIO_PinState switch_state = HAL_GPIO_ReadPin(USER_SW_GPIO_Port, USER_SW_Pin);

	return switch_state == GPIO_PIN_SET ? true : false;

}

bool hw_switch2_state_get(void)
{
	GPIO_PinState switch2_state = HAL_GPIO_ReadPin(USER_SW2_GPIO_Port, USER_SW2_Pin);

	return switch2_state == GPIO_PIN_SET ? true : false;

}

void hw_led_state_set(bool state)
{
	GPIO_PinState led_state = state ? GPIO_PIN_RESET : GPIO_PIN_SET;

	HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, led_state);
}

void hw_delay_ms(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}
