/*
 * software_timer.h
 *
 *  Created on: Sep 26, 2024
 *      Author: vinhd
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int second, minute, hour;
extern int timer0_flag, timer1_flag, timer2_flag, timer3_flag, timer4_flag;
extern int led_buffer[];


void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void timer_run();
void display7SEG(int num);
void updateClockBuffer(int hour, int minute);

void setTimer3(int duration);
void setTimer4(int duration);





#endif /* INC_SOFTWARE_TIMER_H_ */
