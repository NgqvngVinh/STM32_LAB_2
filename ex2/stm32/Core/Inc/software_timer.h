/*
 * software_timer.h
 *
 *  Created on: Sep 23, 2024
 *      Author: vinhd
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void set2Led(int duration);
void display7SEG(int num);

void TimerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
