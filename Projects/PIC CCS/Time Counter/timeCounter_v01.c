/*=================================================================
   
   In this file we are going to create simple up down counter
   to count up Time veriables. {ms, sec, minut, hours}
   |-----------------------------------------|
   | @author: Abdul Rehman                   |
   | @created-At: 28-November-2018, 8:00 PM  |
   |-----------------------------------------|

==================================================================*/

   #include <16F887.h>
   #device *= 16 
   #fuses HS,NOWDT,NOPROTECT,NOLVP
   #use delay(clock=8000000)

/*------------------  LOCAL DRIVERS ---------------------------*/
   #include <LCD4Bit.c>    

/*-------- Global Veriable Defination Area ---------------------*/

   #define __VER__ 0.1     //current example version number

//--------- Buttons -----------------

   #define SW_UP     PIN_D1
   #define SW_DOWN   PIN_D2
   #define SW_RESET  PIN_D7
   
//------------ Veriables -------------
long globalTimeStamp = 0;

/*----------- Function Defination Area --------------------------*/
void displayTimeStamp(long &tstamp,int8 ftype);
int8 getHours(long &tstamp);

/*------ Main Starts here --------------------------------------*/
void main(void){
   lcd_init();  // Always call this first. 
   lcd_test_print();
   while(True){
     
   }//while(True) ends here
}//main ends here
/*-----------------------------------------------------------------*/

void displayTimeStamp(long &tstamp, int8 ftype){
   int8 hour=0, minut=0, seconds=0, milli_seconds=0;
   switch(ftype){
      case 1:
      break;
      
      case 2:
      break;
      
      case 3:
      break;
     }
}

int8 getHours(long &tstamp){


}
