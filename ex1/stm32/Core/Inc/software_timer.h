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

void setTimer1(int duration); //set time co 1 bat
void setTimer2(int duration); //set time co 2 bat
void TimerRun(); //handle tac vu ngat timer


#endif /* INC_SOFTWARE_TIMER_H_ */
