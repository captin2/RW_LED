#include "stm32f10x.h"
//----------------APB2  ---------------------
#define RCC_APB2ENR		*((unsigned volatile int*)0x40021018)
//----------------GPIOA -----------------------
#define GPIOA_CRL		*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR		*((unsigned volatile int*)0x4001080C)
//----------------GPIOB -----------------------
#define GPIOB_CRH		*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR		*((unsigned volatile int*)0x40010C0C)
//----------------GPIOC-----------------------
#define GPIOC_CRH		*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR		*((unsigned volatile int*)0x4001100C)



 static void Delay_ms()
 {
   u32 i=5000000;
		while(i--);
 }
 int main(void)
 {	
	RCC_APB2ENR|=1<<2|1<<3;			
	
	GPIOA_CRL&=0xFF0FFFFF;						//PA5
	GPIOA_CRL|=0X00200000;		
	GPIOA_ODR&=~(1<<5);			
	
	GPIOB_CRH&=0xFFFFFF0F;						//PB9
	GPIOB_CRH|=0x00000020;		
	GPIOB_ODR&=~(1<<9);			
	 
	GPIOB_CRH&=0xF0FFFFFF;						//PB14	
	GPIOB_CRH|=0x02000000;		
	GPIOC_ODR&=~(1<<14);				
	 

	 

	while(1){
		
		
//		GPIOA_ODR|=1<<5;
//		GPIOB_ODR|=1<<9;
//		GPIOB_ODR|=1<<14;	
		//A
		GPIOA_ODR|=1<<5;
		GPIOB_ODR&=~(1<<9);	
		GPIOB_ODR&=~(1<<14);	
	 	Delay_ms();
		

		
		//B
		GPIOA_ODR&=~(1<<5);
		GPIOB_ODR|=1<<9;	
		GPIOB_ODR&=~(1<<14);	
	 	Delay_ms();

		
		
		//C
		GPIOA_ODR&=~(1<<5);
		GPIOB_ODR&=~(1<<9);	
		GPIOB_ODR|=1<<14;	
	 	Delay_ms();

		
		}
}