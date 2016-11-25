#include "LPC11xx.h"                        /* LPC11xx definitions */
#include "LED2.h"   

int main(void){
	SystemInit();				//initial system
	LED_INIT();					//set the P1.8 output pin 

	while(1)
	{
	LED_ON();						//set up led(P1.8) led on
	delay(4800000);			//delay 0.5s	
	LED_OFF();					//set up led(P1.8) led off
	delay(4800000);			//delay 0.5s
	}
}
