#include "LPC11xx.h"
#include "timer16.h"
#include "LED2.h"


int main()
{
   LED_INIT();										//set the P1.8 output pin
   T16B0_init();           				//initial timer
   while(1)
   { 
      LED_ON();					 	 		    //set up led(P1.8) led on
      T16B0_delay_ms(1000);				//delay 1s
      
      LED_OFF();								  //set up led(P1.8) led off
      T16B0_delay_ms(250);				//delay 0.25s
   }
}
