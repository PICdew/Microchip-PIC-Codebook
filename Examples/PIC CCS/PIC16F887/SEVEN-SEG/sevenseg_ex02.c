/*==========================================================

@Description: This code is TWO digit auto Counter [0-99], 
              Common Andoe Seven Segment display,multiplexed

@Author:      Abdul Rehman
@Crystal:     8Mhz (doesn't really matter)
@ChipName:    PIC16F887

=============================================================*/




#include<16F887.h>
#device *=16
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)

//-------------------------------------------------------------
   #define OUT_SEG_CODE(CODE) output_b(CODE)
   
   #define COM1   PIN_D7
   #define COM2   PIN_D6

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
                     
                     
int8 counter=0;
int8 units=0,tens=0;

void mux2(){

   OUT_SEG_CODE(seg_codes[units]);   
   output_high(COM2);output_low(COM1);
   delay_ms(1);
   output_high(COM2);output_high(COM1);
   delay_ms(1);
   
   OUT_SEG_CODE(seg_codes[tens]);   
   output_high(COM1);output_low(COM2);
   delay_ms(1);
   output_high(COM2);output_high(COM1);
   delay_ms(1);
}


void mdelay(){
   int8 i=0;
   for(i=0;i<100;i++){
      mux2();
      delay_ms(6);
   }
}

//--------------------------------------------------------------
void main(){
   while(True){
      counter++;
      if(counter>99)counter=0;
      units = counter%10;
      tens  = counter/10;
      mdelay();
   }
}
//---------------------------------------------------------------
