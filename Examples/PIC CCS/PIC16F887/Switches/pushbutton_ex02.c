/*
   IN THE NAME OF ALLAH
   
   
This project will On LED whenever switch is pressed and after one second will 
off the LED. 
*/


#include <16F887.h>
#device *= 16 

#fuses NOWDT, HS, PROTECT, CPD, NOWRT, BROWNOUT, NODEBUG, NOLVP, PUT
#use delay(clock=8000000)


//====================================================================
// PORT Definations
//====================================================================

#define LED_1       PIN_D0
#define SW_1        PIN_B0
void main()
{
   
   output_float(SW_1);  //enable switch on PIN
   output_high(LED_1);  //off LED connected as Common Anode State
   while(TRUE)
   {
     
      if(input_state(SW_1) == 0)
      {
         output_low(LED_1);
         delay_ms(1000);
         output_high(LED_1);
         
         
      }

   }//while(True) ends here

}//main ends here
