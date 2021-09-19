/*
 * hw.c
 *
 *  Created on: Sep 19, 2021
 *      Author: mikin
 */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "app.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_0)
	{
		app_switch_interrupt();
	}
	else if(GPIO_Pin == GPIO_PIN_1)
	{
		app_switch2_interrupt();
	}
}

 bool hw_switch_state_get(void)
 {
	GPIO_PinState switch_state = HAL_GPIO_ReadPin(USER_SW_GPIO_Port, USER_SW_Pin);
	GPIO_PinState switch2_state = HAL_GPIO_ReadPin(USER_SW2_GPIO_Port, USER_SW2_Pin);
	//return switch_state == GPIO_PIN_SET ? true : false;

	if(switch_state == GPIO_PIN_SET)
		return true;
	else
		return false;

	if(switch2_state == GPIO_PIN_SET)
		return true;
	else
		return false;
 }

 void hw_led_toggle(void)
 {
	 HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
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

 uint32_t hw_tick_ms_get(void)
 {
	 return HAL_GetTick();
 }

 void hw_cpu_sleep(void)
 {
	 __WFI();
 }
