/*
 * updateClockBuffer.h
 *
 *  Created on: Sep 25, 2024
 *      Author: vinhd
 */

#ifndef SRC_UPDATECLOCKBUFFER_C_
#define SRC_UPDATECLOCKBUFFER_C_
#include "updateClockBuffer.h"


//b5
//int led_buffer;
int TIMER_CYCLE = 10;  //b6


//b6,8
int timer0 = 0, timer1 = 0, timer2 = 0;
int timer0_flag = 0, timer1_flag = 0, timer2_flag = 0;
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

	if(timer2 > 0){
		timer2--;
		if(timer2 <= 0)
			timer2_flag = 1;
	}

 	 } //end timer_run






#endif /* SRC_UPDATECLOCKBUFFER_C_ */
