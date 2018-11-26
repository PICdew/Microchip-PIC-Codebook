/*

Source: https://www.ccsinfo.com/forum/viewtopic.php?p=4022

*/


#include <16F887.h>
#device *= 16 
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=8000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)



#use fast_io(A) 
#use fast_io(B) 
#use fast_io(C) 



int16   Count; 
int16   Frequency; 
int1    OneSecondGone = 0;


#int_timer2 
void t2_isr(void) 
{ 
    static int16 RollOver = 0; 

    Count = get_timer1(); 
    RollOver++; 
    if (Rollover == 250) 
    { 
        OneSecondGone = true; 
        Rollover = 0; 
        set_timer1(0);        
        Frequency = Count; 
    } 
} 



void main(){
    set_tris_a(0); 
    set_tris_c(255); 
    setup_timer_2(T2_DIV_BY_4,250,8); 
    setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1); 
    enable_interrupts(int_timer2); 
    enable_interrupts(global); 
    while(true) 
    { 
        if (OneSecondGone) 
        { 
            if (Frequency > 999) 
            { 
                printf("\rFequency = \%1.4f kHz       ",(float)Frequency / 1000); 
            } 
            else 
            { 
                printf("\rFequency = \%lu Hz          ",Frequency); 
            } 
            OneSecondGone = false; 
        } 
    } 

}
