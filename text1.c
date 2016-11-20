#include "LPC11xx.h"                        /* LPC11xx definitions */
#include "LED2.h"   

void delay(){  //0.5s
	long int i;
	for(i=4800000;i>0;i--){
	}	
}
int main(void){
	SystemInit();			//initial system
	LED_INIT(1,8);		//set the P1.8 output pin 

	while(1)
	{
	LED_ON(1,8);			//set up led(P1.8) led on
	delay();					//delay 0.5s	
	LED_OFF(1,8);			//set up led(P1.8) led off
	delay();					//delay 0.5s
	}
}
