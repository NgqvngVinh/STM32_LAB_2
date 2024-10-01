/*
 * software.c
 *
 *  Created on: Sep 26, 2024
 *      Author: vinhd
 */

#ifndef SRC_SOFTWARE_C_
#define SRC_SOFTWARE_C_
#include "software_timer.h"

int timer0 = 0, timer1 = 0, timer2 = 0, timer3 = 0, timer4 = 0;
int timer0_flag = 0, timer1_flag = 0, timer2_flag = 0, timer3_flag = 0, timer4_flag = 0;
int index_led = 0;
int led_buffer[4]={};

void updateClockBuffer(int hour, int minute){
	if( hour >= 10){
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	 }
	else {
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	 }
	if( minute >= 10){
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	 }
	else {
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	 }
	}


void setTimer0(int duration){
	timer0 = duration;
	timer0_flag = 0;
 	 }

void setTimer1(int duration){
	timer1 = duration;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2 = duration;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3 = duration;
	timer3_flag = 0;
}

void setTimer4(int duration){
	timer4 = duration;
	timer4_flag = 0;
}


void timer_run(){
	if(timer0 > 0){
		timer0--;
		if(timer0 <= 0)
			timer0_flag = 1;
	}

	if(timer1 > 0){
		timer1--;
		if(timer1 <= 0)
			timer1_flag = 1;
	}

	//flag cho all led
	if(timer2 > 0){
		timer2--;
		if(timer2 <= 0)
			timer2_flag = 1;
	}

	if(timer3 > 0){
		timer3--;
		if(timer3 <= 0){
			timer3_flag = 1;
		}
	}

	if(timer4 > 0){
		timer4--;
		if(timer4 <= 0){
			timer4_flag = 1;
		}
	}



 	 } //end timer_run



#endif /* SRC_SOFTWARE_C_ */
