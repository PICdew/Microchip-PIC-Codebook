#ifndef __TIMEVAR_UTILS_C__
#define __TIMEVAR_UTILS_C__

/*
This library will only work upto 99 minutes 59 seconds and 99 centi-seconds
one-centiseconds = one-second/100;
*/

typedef struct{
   int8 min;      //min = sec/60; min = centsec/6000;
   int8 sec;      //sec = centsec/100;
   int8 centsec;  //centiseconds = sec*100;
} Timevar;

//----------------------------------------------------------------
#inline
void timevarToSeconds(int32 &timestamp, Timevar &mTimevar){
   timestamp = ((int32)mTimevar.min*60)+mTimevar.sec;  ; //minutes to seconds
}


/*
takes refference of timeInSeconds variable of int32 and 
@centsec and convert seconds into centiseconds by 
multiplying it with 100 and add provided @centsec of type int8
*/
#inline
void secondsToCentiSeconds(int32 &timeInSeconds, int8 centsec){
   timeInSeconds = (timeInSeconds*100)+centsec;

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

/*
this will extracts minutes from 
@centiseconds refference timestamp
*/
#inline 
int8 centisecondsToMinutes(int32 &centiseconds){
   return centiseconds/6000;
}

/*
This function will extract seconds from 
@centiseconds timestamp
*/
#inline 
int8 centisecondsToSeconds(int32 &centiseconds){
   return ((centiseconds/100)%60);
}

/*
This method will call above functions to extract minutes and seconds
and put it in provided @mTimevar refference variable of type Timevar 

*/
#inline
void timevarFromCentiseconds(int32 &centiseconds, Timevar &mTimevar){
   //this function will convert centiseconds to valid time format;
   mTimevar.min = centisecondsToMinutes(centiseconds);
   mTimevar.sec = centisecondsToSeconds(centiseconds);
   mTimevar.centsec = centiseconds % 100;
}
//---------------------------------------------------------------
#endif

