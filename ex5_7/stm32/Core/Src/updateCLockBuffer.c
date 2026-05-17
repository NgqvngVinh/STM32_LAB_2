/*
 * updateCLockBuffer.c
 *
 *  Created on: Sep 25, 2024
 *      Author: vinhd
 */

#ifndef SRC_UPDATECLOCKBUFFER_C_
#define SRC_UPDATECLOCKBUFFER_C_
#include "updateCLockBuffer.h"

int led_buffer[4] = {1 , 2 , 3 , 4};
extern int second, minute, hour;

void updateClockBuffer(int hour, int minute) {

	if(hour >- 10){
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	}
	else{
		led_buffer[2] = 0;
		led_buffer[3] = hour;
	}


	if(minute >= 10){
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	}
	else {
    	led_buffer[2] = 0;
    	led_buffer[3] = minute;
    }


//
//    led_buffer[0] = minute_tens;    // Lưu chữ số hàng chục vào led_buffer
//    led_buffer[1] = minute_units;   // Lưu chữ số hàng đơn vị vào led_buffer
}

#endif /* SRC_UPDATECLOCKBUFFER_C_ */
