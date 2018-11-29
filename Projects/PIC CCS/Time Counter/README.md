## Useful Time functions

In this project I had created usefull functions for manipulating time values. I had implemented minutes, seconds and centi seconds structure 
and later on utility functions to convert between centi-seconds to Timevar structure

Main structure is defined as 

`c
typedef struct{
   int8 min;      //min = sec/60; min = centsec/6000;
   int8 sec;      //sec = centsec/100;
   int8 centsec;  //centiseconds = sec*100;
} Timevar; `

## Circuit 

[](https://github.com/abdul-rehman-2050/Microchip-PIC-Codebook/blob/master/Projects/PIC%20CCS/Time%20Counter/timecounter_v01.bmp)
