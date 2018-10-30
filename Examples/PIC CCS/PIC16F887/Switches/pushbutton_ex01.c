/*
   @summary:  |Read @pushbutton ActiveLow state and put ActiveLow on @LED
              |LED will remain on untill button is pressed and will go off(high)
              |when button is released. 
             
    @INPUT:   |PORTB.0,   @pushButton
    @OUTPUT:  |PORTD.0,   @LED
    @Crystal: |8Mhz
    @Autor:   |Abdul Rehman
    

*/


#include <16F887.h>
#device *= 16 
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)



#define LED   PIN_D0
#define SW1   PIN_B0



void main(){
   
   while(True){
      if(!input(SW1)){   //READ Active LOW state
         output_low(LED);
      }else{   //IF button is not pressed Turn LED Off(put active high)
         output_high(LED);
      }      
   }
}
