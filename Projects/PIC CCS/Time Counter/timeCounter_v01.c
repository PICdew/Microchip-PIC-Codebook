/*=================================================================
   
   In this file we are going to create simple up down counter
   to count up Time veriables. {ms, sec, minut}
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

typedef struct{
   int8 min;      //min = sec/60; min = centsec/6000;
   int8 sec;      //sec = centsec/100;
   int8 centsec;  //centiseconds = sec*100;
} Timevar;

/*----------- Function Defination Area --------------------------*/
void timevarPrint(Timevar &tvar);
void timevarToCentiSeconds(int32 &timestamp, Timevar &mTimevar); 
void timevarToSeconds(int32 &timestamp, Timevar &mTimevar);
void timevarFromCentiseconds(int32 &centiseconds, Timevar &mTimevar);
//-----------------------------------------------------------------
void secondsToCentiSeconds(int32 &timestamp, int8 centsec);
int8 centisecondsToMinutes(int32 &centiseconds);
int8 centisecondsToSeconds(int32 &centiseconds);
//-----------------------------------------------------------------
void displayTimeStamp(int32 &tstamp,int8 ftype);
int8 getMinutes(long &tstamp);
void addMinutes(long &tstamp, int8 mnToAdd);

/*------ Main Starts here --------------------------------------*/
void main(void){
   Timevar mTimevar,tvar1;
   int32 timeStamp = 0;
   lcd_init();  // Always call this first.
  // lcd_test_print();
   
   
   mTimevar.min = 30;
   mTimevar.sec = 13;
   mTimevar.centsec = 99;
   timevarToSeconds(timeStamp,mTimevar);
   secondsToCentiSeconds(timeStamp,mTimevar.centsec);
   
   //printf(lcd_putc,"%Lu,",timeStamp);
   printf(lcd_putc,"%u,",centisecondsToSeconds( timeStamp));
   
   timevarFromCentiseconds(timeStamp,tvar1);
   timevarPrint(tvar1);
   
   lcd_gotoxy(4,2);
   timevarPrint(mTimevar);
   while(True){
      delay_ms(10);
      timeStamp++;
      timevarFromCentiseconds(timeStamp,mTimevar);
      lcd_gotoxy(4,2);
      timevarPrint(mTimevar);
    
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
//----------------------------------------------------------------
#inline
void timevarPrint(Timevar &tvar){
   printf(lcd_putc,"%02u:%02u:%02u",tvar.min,tvar.sec,tvar.centsec);   
}
#inline
void timevarToSeconds(int32 &timestamp, Timevar &mTimevar){
   timestamp = ((int32)mTimevar.min*60)+mTimevar.sec;  ; //minutes to seconds
}
/*
 timevar to centiseconds converter function
 will automatically call two inline functions
*/
#inline
void timevarToCentiSeconds(int32 &timestamp, Timevar &mTimevar){
   timevarToSeconds(timestamp,mTimevar);
   secondsToCentiSeconds(timestamp,mTimevar.centsec);
}
#inline
void secondsToCentiSeconds(int32 &timeInSeconds, int8 centsec){
   timeInSeconds = (timeInSeconds*100)+centsec;

}
#inline 
int8 centisecondsToMinutes(int32 &centiseconds){
   return centiseconds/6000;
}
#inline 
int8 centisecondsToSeconds(int32 &centiseconds){
   return ((centiseconds/100)%60);
}

#inline
void timevarFromCentiseconds(int32 &centiseconds, Timevar &mTimevar){
   //this function will convert centiseconds to valid time format;
   mTimevar.min = centisecondsToMinutes(centiseconds);
   mTimevar.sec = centisecondsToSeconds(centiseconds);
   mTimevar.centsec = centiseconds % 100;
}
//----------------------------------------------------------------

int8 getMinutes(long &tstamp){
   

}

void addMinutes(long &tstamp, int8 mnToAdd){
/*
   This function will take time stamp in miliseconds 
   and @mnToAdd minutes to add with it 
   it converts @mnToAdd to milliseconds by multitplying it
   with 60000 and add to @&tstamp
*/
   tstamp += (mnToAdd*60000);
}
