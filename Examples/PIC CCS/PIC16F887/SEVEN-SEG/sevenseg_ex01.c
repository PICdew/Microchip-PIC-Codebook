/*==========================================================

@Description: This code is single digit auto Counter [0-9], 
              Common Andoe Seven Segment display,

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
//--------------------------------------------------------------
void main(){
      while(True){
      int8 i=0;
      for(i=0;i<10;i++){
         OUT_SEG_CODE(seg_codes[i]);   
         delay_ms(500);
      }
   }
}
//---------------------------------------------------------------
