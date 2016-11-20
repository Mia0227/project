#include "LPC11xx.h"                        /* LPC11xx definitions */
#include "timer16.h"
#include "LED2.h"

int main(void){
	
	SystemInit();								//initial system
  T16B0_init();								//initial timer
	LED_INIT(1,8);									//set the P1.8 output pin & set high to P1.8  
	LPC_GPIO2->DIR &=~ (1<<0);  //set the P2.0 intput pin
	
	while(1){
		int i=0;
		if((LPC_GPIO2->DATA&(1<<0))==0){        //if the button(P2.0) is pressed
			while((LPC_GPIO2->DATA&(1<<0))==0){	  //while the button(P2.0) is pressed
				T16B0_delay_ms(250);							  //delay 0.25s
				while((LPC_GPIO2->DATA&(1<<0))==0){	//while the button(P2.0) is still pressed
					T16B0_delay_ms(250);							//delay 0.25s
					LED_STATUS(1,8);											//change the led(P1.8) state
					i=1;															//Long press i=1
				}
			}
			if(i==1){                             //if(long press)
			LED_OFF(1,8);														//set up led(P1.8) led off
			}
			else																	//else   ->Short press
			LED_STATUS(1,8);														//change the led(P1.8) state
		}
	}
}

		