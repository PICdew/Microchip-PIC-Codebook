#include<16F887.h>
#device *=16
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

void main(){
   
   output_high(PIN_D0);
   output_low(PIN_D1);
   output_high(PIN_D2);
   output_low(PIN_D3);
   output_high(PIN_D4);
   output_low(PIN_D5);
   output_high(PIN_D6);
   
   while(True){
   }

}
