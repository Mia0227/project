#include "LPC11XX.H"

#define LED1_ON  LPC_GPIO1->DATA &= ~(1<<8)
#define LED1_OFF LPC_GPIO1->DATA |= (1<<8)


#define KEY1_DOWN (LPC_GPIO2->DATA&(1<<6))!=(1<<6)
#define KEY1_UP   (LPC_GPIO2->DATA&(1<<6))==(1<<6)

void delay(){  
	long int i,j;
	for(i=480;i>0;i--){
		for(j=1000;j>0;j--);
	}	
}

void led_init()
{
 LPC_GPIO1->DIR |= (1<<8); 
 LPC_GPIO1->DATA |= (1<<8); 
}

void PIOINT2_IRQHandler()
{
	long z=0;
 if((LPC_GPIO2->MIS&(1<<6))==(1<<6))
 {
	 while((LPC_GPIO2->DATA&(1<<6))==0)
	 {
		 for(;z<480000;z++){
		 if((LPC_GPIO2->DATA&(1<<6))!=0){
			 LPC_GPIO1->DATA^=(1<<8);
			 break;
		 }
		 
		 }
		 	
		 
		 if((LPC_GPIO2->DATA&(1<<6))==0){
			delay();
			while((LPC_GPIO2->DATA&(1<<6))==0){
				 
					 LED1_ON;
					 delay();
				
					 LED1_OFF;
					 delay();				 				 
			}
	 }
 }
LPC_GPIO2->IC = 0XFFF;  
 }
}

int main()
{
 led_init();
 LPC_GPIO2->IE |= (1<<6); 
 NVIC_EnableIRQ(EINT2_IRQn);
 
 while(1)
 {
  ;
 }
}
