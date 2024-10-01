/*
 * software_timer.c
 *
 *  Created on: Sep 23, 2024
 *      Author: vinhd
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_
#include "software_timer.h"
//implement functions in here
//0,5s la 50
int counter1 = 0;
int counter2 = 0;
int timer1_flag = 100;
int timer2_flag = 100;
void setTimer1(int duration){
	counter1 = duration;
	timer1_flag = 0;

}
void setTimer2(int duration){
	counter2 = duration;
	timer2_flag = 0;
}
void TimerRun(){
	if(counter1 > 0){
		counter1--;
		if(counter1 <= 0){
			timer1_flag = 1;
		}
	}
	if(counter2 > 0){
		counter2--;
		if(counter2 <= 0){
			timer2_flag = 2;
		}
	}
}

#endif /* SRC_SOFTWARE_TIMER_C_ */
