/*

   @summary:  | External Interrupt on Pin_B0 is triggered 
   @input:    | Switch connected on PIN_B0
   @output:   | led Connected to PIN_D0
   @author:   | Abdul Rehman
   @test:     | Tested on Proteous

*/





#include <16F887.h>
#device *= 16 
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

#define LED PIN_D0

// external interrupt when button pushed and released
#INT_EXT
void ext_isr() {
   static short led_state = 0;
   if(led_state==0){
      led_state=1;
      output_high(LED);
   }else{
      led_state = 0;
      output_low(LED);
   }
   
}
   
   


void main(){
   
   ext_int_edge(H_TO_L);      // init interrupt triggering for button press
   enable_interrupts(INT_EXT);// turn on interrupts
   enable_interrupts(GLOBAL);
   while(True);   
}
