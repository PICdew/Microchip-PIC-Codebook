#include<16F887.h>
#device *=16
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

#include <LCD4Bit.c>
#include <Timevar_Utils.c>

//====================================================================
// ISRs  Timer0_freq = MCU_freq / {4 * Prescaler * (256 - TMR0)}  
//====================================================================

volatile int32 centseconds=0;
int8 changeFlag=0;

#INT_TIMER0
void timer0_isr(void)
{
   clear_interrupt(INT_TIMER0);
   set_timer0(100);  //time is 9.98 millisecond
   centseconds++;
   output_toggle(PIN_B0);
   changeFlag=1;
}

void main(){
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);
   set_timer0(100);//prescaler 8 and value 56 produce 10msec delay with 1Khz frequency
   clear_interrupt(INT_TIMER0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   lcd_init();
   while(True){
      if(changeFlag==1){
         Timevar mTvar;
         changeFlag=0;
         lcd_gotoxy(4,1);
         printf(lcd_putc,"%08Lu",centseconds);
         timevarFromCentiseconds(centseconds,mTvar);
         lcd_gotoxy(4,2);
         printf(lcd_putc,"%02u:%02u:%02u",mTvar.min,mTvar.sec,mTvar.centsec);
         
      }
   }
}
