/*
   IN THE NAME OF ALLAH
   
http://ccspicc.blogspot.com/2016/03/pic16f877a-timer0-module-and-interrupt.html   
Timer0_freq = MCU_freq / {4 * Prescaler * (256 - TMR0)}  
where TMR0 is timer0 preload value.  

in this file we created 1msec delay using timer0 
*/


#include <16F887.h>
#device *= 16 

#fuses NOWDT, HS, PROTECT, CPD, NOWRT, BROWNOUT, NODEBUG, NOLVP, PUT
#use delay(clock=8000000)

//====================================================================
// PORT Definations
//====================================================================

#define LED_1       PIN_D0


//------------------- Variable Decleration Area ---------------------

int16 ms=0;


//====================================================================
// ISRs
//====================================================================

#INT_TIMER0
void timer0_isr(void)
{
   clear_interrupt(INT_TIMER0);
   set_timer0(6);
   ms++;
   if(ms>500)
   {
      ms=0;
      output_toggle(PIN_B0);
   }
  
}


//====================================================================
// MAIN Function
//====================================================================
void main()
{ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
   set_timer0(6);//prescaler 8 and value 6 produce 1msec delay with 1Khz frequency
   clear_interrupt(INT_TIMER0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   output_high(LED_1);  //off LED connected as Common Anode State
   while(TRUE);
  
}//main ends here
