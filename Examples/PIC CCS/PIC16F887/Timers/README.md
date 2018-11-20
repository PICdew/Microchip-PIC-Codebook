# PIC16F887 Timers Introduction
We are going to describe some useful in formation about PIC16F887 timers. Most of the content is taken from [this site](https://exploreembedded.com/wiki/PIC16f877a_Timer). 



## Visual Explaination 

![](https://exploreembedded.com/wiki/images/6/69/Timer.gif)


## Number of Available Timers

|Timer name | size | Min Delay | Max Delay  |Count Register| Control Register |
|-----------|------|-----------|------------|--------------| ---------------- |
|Timer0 |8-bit  | 0.2usec | 13.107ms  |TMR0        |	OPTION_REG            |
|Timer1 |16-bit | 0.2usec | 104.857ms |TMR1H,TMR1L |    T1CON                 |
|Timer2 |8-bit  | 0.2usec | 819usec   |TMR2        |    T2CON                 |


## Calculations

Here are the formulas to calculate values for all three timers

* RegValue = 256-((Delay * Fosc)/(Prescalar*4))  //**For timer0**
* RegValue = 65536-((Delay * Fosc)/(Prescalar*4)) //**For timer1**
* RegValue = 256-((Delay * Fosc)/(Prescalar*4))   //**For timer2**
