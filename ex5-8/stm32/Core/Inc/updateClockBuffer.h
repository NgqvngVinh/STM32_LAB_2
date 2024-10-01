/*
 * updateClockBuffer.h
 *
 *  Created on: Sep 25, 2024
 *      Author: vinhd
 */

#ifndef INC_UPDATECLOCKBUFFER_H_
#define INC_UPDATECLOCKBUFFER_H_

extern int second, minute, hour;
extern int timer0_flag, timer1_flag, timer2_flag;
extern int led_buffer[];


//void updateClockBuffer(); //b5,6,7
void setTimer0(int duration);//b5,6,7,8
void setTimer1(int duration); //b8
void setTimer2(int duration); //b8
void timer_run(); //b8
void display7SEG(int num);
void update7SEG();
void updateClockBuffer(int hour, int minute);





#endif /* INC_UPDATECLOCKBUFFER_H_ */
