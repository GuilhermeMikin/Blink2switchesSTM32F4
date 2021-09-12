/*
 * app.c
 *
 *  Created on: Sep 11, 2021
 *      Author: mikin
 */

#include <stdint.h>
#include <stdbool.h>
#include "app.h"
#include "hw.h"

void app_init(void)
{

}

void app_loop(void)
{
	uint32_t led_time_on_ms;
	uint32_t led_time_off_ms;

	bool switch_state = hw_switch_state_get();
	bool switch2_state = hw_switch2_state_get();

	if(switch_state && switch2_state){
		led_time_on_ms = 900;
		led_time_off_ms = 450;
	}
	else if(switch_state && !switch2_state)
	{
		led_time_on_ms = 600;
		led_time_off_ms = 300;
	}
	else if(!switch_state && switch2_state)
	{
		led_time_on_ms = 300;
		led_time_off_ms = 150;
	}
	else
	{
		led_time_on_ms = 100;
		led_time_off_ms = 100;
	}

	hw_led_state_set(true);
	hw_delay_ms(led_time_on_ms);

	hw_led_state_set(false);
	hw_delay_ms(led_time_off_ms);

}



