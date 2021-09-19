/*
 * app.h
 *
 *  Created on: Sep 19, 2021
 *      Author: mikin
 */

#ifndef APP_H_
#define APP_H_

void app_init(void);
void app_loop(void);
void app_tick_1ms(void);
void app_switch_interrupt(void);
void app_switch2_interrupt(void);
void truthtable_switch_state(void);

#endif /* APP_H_ */
