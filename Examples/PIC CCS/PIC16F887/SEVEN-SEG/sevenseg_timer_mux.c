/*

   ---------------------------------------------------------------------
   @Description: 4 digit Seven segment multiplexing via timer interrupt
   @Author:      Abdul Rehman
   @Date:        19-Dec-2018
   @Time:        7:33 PM  -> 8:50 PM
   ---------------------------------------------------------------------

*/

#include <16F887.h>
#device *= 16 

#fuses NOWDT, HS, PROTECT, CPD, NOWRT, BROWNOUT, NODEBUG, NOLVP, PUT
#use delay(clock=8000000)


//-------------------------------------------------------------
   #define OUT_SEG_CODE(CODE) output_b(CODE)
   
   #define COM1   PIN_D7
   #define COM2   PIN_D6
   #define COM3   PIN_D5
   #define COM4   PIN_D4

int8 seg_digits[4]={1,2,3,4};
int8 seg_commons[4]={71,70,69,68};
int8 cur_segment = 0;
int16 ms_counter =0;

int8 seg_codes[]=
                     {
                       0b00000011,  //0
                       0b10011111,  //1
                       0b00100101,  //2
                       0b00001101,  //3
                       0b10011001,  //4
                       0b01001001,  //5
                       0b01000001,  //6
                       0b00011111,  //7
                       0b00000001,  //8
                       0b00001001,  //9
                       0b11111111,  //All-Off
                     };
                     


//====================================================================
// ISRs
//====================================================================

#INT_TIMER0
void timer0_isr(void)
{
   ms_counter++;
   
   if(ms_counter<=4){
      output_high(seg_commons[0]);   
      output_high(seg_commons[1]);
      output_high(seg_commons[2]);
      output_high(seg_commons[3]);
   
   }
   
   if(ms_counter>4){
      ms_counter=0;
      OUT_SEG_CODE(seg_codes[seg_digits[cur_segment]]);   
      output_low(seg_commons[cur_segment]);
      cur_segment++;
      if(cur_segment>4)cur_segment=0;
   }
   
   
   clear_interrupt(INT_TIMER0);
   set_timer0(6); 
}



//====================================================================
// MAIN Function
//====================================================================
void main()
{ 
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   set_timer0(6);//prescaler 8 and value 6 produce 1msec delay with 1Khz frequency
   clear_interrupt(INT_TIMER0);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   while(TRUE){
   
   }
}//main ends here


