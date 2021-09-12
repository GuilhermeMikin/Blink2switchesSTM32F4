/*
 * hw.h
 *
 *  Created on: Sep 11, 2021
 *      Author: mikin
 */

#ifndef HW_H_
#define HW_H_


bool hw_switch_state_get(void);
bool hw_switch2_state_get(void);
void hw_led_state_set(bool state);
void hw_delay_ms(uint32_t time_ms);


#endif /* HW_H_ */
