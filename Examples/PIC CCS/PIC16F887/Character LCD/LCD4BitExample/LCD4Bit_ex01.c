/*===============================================================

   Example Usage of LCD4Bit Character Library Driver Usage
   @Author: Abdul Rehman
   @Licence: 
   @Note: Use this on your own. Author is not responsible for anything

=================================================================*/

#include <16F887.h>
#device *= 16 
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
/*------------------  LOCAL DRIVERS ---------------------------*/
#include <LCD4Bit.c>    // Our Library undertest 

/*-------- Global Veriable Defination Area ---------------------*/
#define __VER__ 1.0     //current example version number

/*----------- Function Defination Area --------------------------*/
void printWelcomeMessage();   //

/*------ Main Starts here --------------------------------------*/
void main(void){
   lcd_init();  // Always call this first. 
   while(True){
      printWelcomeMessage();
   }//while(True) ends here
}//main ends here
/*-----------------------------------------------------------------*/

void printWelcomeMessage(){
   lcd_putc("\fLCD 4BIT Driver\n"); 
   printf(lcd_putc, "     V# %1.2f", __VER__);
   delay_ms(1500);
   lcd_putc("\fDeveloper:");
   lcd_gotoxy(2,2);
   lcd_putc("Abdul Rehman");
   delay_ms (1000);
   lcd_putc("\f Compiled On \n ");
   printf(lcd_putc, __DATE__);
   delay_ms(1000);
}
