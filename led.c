#include "LPC11xx.h"
#include "timer16.h"
#include "LED2.h"

void init()
{
   LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);   //enable IOCON clock
   LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);  //disable IOCON clock
	 LED_INIT(1,8);													 //set the P1.8 output pin  
}
int main()
{
   init();
   T16B0_init();           				//initial timer
   while(1)
   { 
      LED_ON(1,8);					 	 		//set up led(P1.8) led on
      T16B0_delay_ms(1000);				//delay 1s
      
      LED_OFF(1,8);								//set up led(P1.8) led off
      T16B0_delay_ms(250);				//delay 0.25s
   }
}
