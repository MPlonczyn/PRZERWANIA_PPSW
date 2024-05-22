#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

#define NULL 	'\0'

enum LedState{
	LED_STOP,
	LED_GO_RIGHT,
	LED_GO_LEFT,
};

enum LedState eLedState = LED_GO_RIGHT;

void Automat(){
	
	LedInit();
	KeyboardInit();
			
	switch(eLedState){
			
		case LED_STOP:
		if(eKeyboardRead() == BUTTON_0){
			eLedState = LED_GO_LEFT;
		}
		else if(eKeyboardRead() == BUTTON_2){
			eLedState = LED_GO_RIGHT;
		}
		else{
			eLedState = LED_STOP;
		}
		break;	
				
		case LED_GO_RIGHT:
		if(eKeyboardRead() == BUTTON_1){
			eLedState = LED_STOP;
		}
		else{
			eLedState = LED_GO_RIGHT;
			LedStepRight();
		}
		break;
			//gittest
		case LED_GO_LEFT:
		if(eKeyboardRead() == BUTTON_1){
			eLedState = LED_STOP;
		}
		else{
			eLedState = LED_GO_LEFT;
			LedStepLeft();
		}
		break;
	}
}


int main(){
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(200000,&Automat);

	while(1){
		iMainLoopCtr++;
	}
}

