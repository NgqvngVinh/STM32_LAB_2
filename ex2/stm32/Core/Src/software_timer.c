/*
 * software_timer.c
 *
 *  Created on: Sep 23, 2024
 *      Author: vinhd
 */

#ifndef SRC_SOFTWARE_TIMER_C_
#define SRC_SOFTWARE_TIMER_C_
#include "software_timer.h"

int counter1 = 201;
//int counter2 = 0;
//int counter3 = 0;
//int counter4 = 0;
int counter5 = 100;
//int timer1_flag = 0;
//int timer2_flag = 0;
//int timer3_flag = 0;
//int timer4_flag = 0;
int timer5_flag = 0;

//void setTimer1(int duration){
//	counter1 = duration;
//	timer1_flag = 0;
//}
//
//void setTimer2(int duration){
//	counter2 = duration;
//	timer2_flag = 0;
//}
//void setTimer3(int duration){
//	counter3 = duration;
//	timer3_flag = 0;
//}
//void setTimer4(int duration){
//	counter4 = duration;
//	timer4_flag = 0;
//}
void set2Led(int duration){
	counter5 = duration;
	timer5_flag = 0;
}

void TimerRun(){
// 4 flag doc lap ko chay
//	if(counter1 > 0){
//		counter1--;
//		if(counter1 <=0){
//			timer1_flag = 1;
//		}
//	}
//
//	if(counter2 > 0){
//		counter2--;
//		if(counter2 <=0){
//			timer2_flag = 1;
//		}
//	}
//
//	if(counter3 > 0){
//		counter3--;
//		if(counter3 <=0){
//			timer3_flag = 1;
//		}
//	}
//
//	if(counter4 > 0){
//		counter4--;
//		if(counter4 <= 0){
//			timer4_flag = 1;
//		}
//	}
//
//	if(counter5 > 0){
//		counter5--;
//		if(counter5 <=0){
//			timer5_flag = 1;
//		}
//	}
//

//1 flag 4 den, 1 flag 2led
	if(counter1 > 0){
		counter1--;
		if(counter1 <= 0){
			counter1 = 200;
		}
	}

	if(counter5 > 0){
			counter5--;
			if(counter5 <=0){
				timer5_flag = 1;
			}
		}

}




#endif /* SRC_SOFTWARE_TIMER_C_ */
