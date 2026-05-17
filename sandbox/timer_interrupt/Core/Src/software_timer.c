/*
 * software_timer.c
 *
 *  Created on: Sep 22, 2024
 *      Author: vinhd
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_
#include "software_timer.h"
int timer1_counter = 0;
int timer1_flag = 0;

/*code sai, ham timer_Run la ham xu ly tac vu timer khi ngat-->
phai de cho counter chay o ham nay moi dung, con ham setTimer chi co
nv set co timer ve 0 thoi*/

//void setTimer(duration){
//	timer1_counter = duration;
//	timer1_counter = 100;
//	timer1_flag = 0;
//	if(timer1_counter > 0){
//		timer1_counter--;
//		if(timer1_counter <= 0){
//			timer1_counter = 100;
//			timer1_flag = 1;
//		}
//	}
//}
//void timerRun(){
//	if(timer1_flag = 1){
//		timer1_flag = 0;
//	}
//}

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void timerRun(){
//dem tg va bao len bang 1 bien
	//	timer1_counter = 100; chi xu ly tac vu timer, khong set tg yeu cau dau vao trong ham nay.
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}

#endif /* SRC_SOFTWARE_TIMER_C_ */
