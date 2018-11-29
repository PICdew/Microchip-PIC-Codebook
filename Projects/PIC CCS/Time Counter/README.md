## Useful Time functions

In this project I had created usefull functions for manipulating time values. I had implemented minutes, seconds and centi seconds structure 
and later on utility functions to convert between centi-seconds to Timevar structure

Main structure is defined as 

```c
typedef struct{
   int8 min;      //min = sec/60; min = centsec/6000;
   int8 sec;      //sec = centsec/100;
   int8 centsec;  //centiseconds = sec*100;
} Timevar; 
```

## Circuit 

![](https://github.com/abdul-rehman-2050/Microchip-PIC-Codebook/blob/master/Projects/PIC%20CCS/Time%20Counter/timecounter_v01.bmp)



## Public Methods 

```c
void timevarPrint(Timevar &tvar);   //will print to lcd
void timevarToCentiSeconds(int32 &timestamp, Timevar &mTimevar); // will convert timevar variable into centi-seconds
/*will convert timevar variable into seconds*/
void timevarToSeconds(int32 &timestamp, Timevar &mTimevar); 
/*This function will convert centiseconds back into timevar structure*/
void timevarFromCentiseconds(int32 &centiseconds, Timevar &mTimevar);   

```


## Example Usage
Here is some example usage of these functions

```C
   Timevar mTimevar; //create empty timevar variable
   int32 timeStamp = 0; //this variable will be used to store time in centi-seconds
   /*Add time values to mTimevar Structure*/
   mTimevar.min = 30;
   mTimevar.sec = 13;
   mTimevar.centsec = 99;
```   
   /* Print values of this structure onto LCD at seconds line*/
```C   
   lcd_gotoxy(4,2);
   timevarPrint(mTimevar);
   
   /*Convert timevar to centi-seconds time stamp mannually [not recomended]*/
    timevarToSeconds(timeStamp,mTimevar);
    secondsToCentiSeconds(timeStamp,mTimevar.centsec);
```

 **Recomended way of Converting Structure into Centi-second timestamp**
 
 ```C
  timevarToCentiSeconds(timeStamp,mTimevar);
 
 ```
 
 ## Private Util Functions
 
 Here are few [private] functions which should not be used directly, but could be used if required
 
 ```C
   void secondsToCentiSeconds(int32 &timestamp, int8 centsec);
   int8 centisecondsToMinutes(int32 &centiseconds);
   int8 centisecondsToSeconds(int32 &centiseconds);
 ```
 
 
 
 
