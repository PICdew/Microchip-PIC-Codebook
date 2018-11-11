#include<16F887.h>
#device *=16
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)





void main(){
   printf("hello world\n");
   while(True){
      int8 inChar = getc();
      putc(inChar);
   }

}
