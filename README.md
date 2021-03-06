# Microchip PIC Codebook
This codebook contains sample applications and demo examples for illustrating how to use different features of Microchip PIC microcontrollers in C language(Examples in other languages are welcome).


## Examples
This folder contains files for some simple examples
    
 * **singleLEDFlasher_ex01.c**
    This file blink single LED on PORTD.0 with fix 500ms delay with 8Mhz Crystal
 
 * **pushbutton_ex01.c**
    This file print active low state to output LED connected to PORTD.0 and button connected with PORTB.0
    10K pullup resistor is connected in hardware. LED will remain on untill button is pressed and once button
    is released LED turns off
 
 * **pushbutton_ex02.c** 
    This file uses another method of reading microcontroller pin as an Input using input_state function. Also output_float function is used to make PIN_B0 floating input

 * **timer0Blinky_ex01.c**
    In this file we used Timer0 of PIC16F887 microcontroller to generate 1 milli second delay and we incremented 
     a veriable and once this veriable is > 500 we toggle the state of LED and thus a flashing effect is generated 
    via timer0
    
 * **exISR_ex01.c**  Using external Interrupt from PIN_B0 we maintain LED status with static veriable and 
 turn LED on if previous status == 1 and turn LED off if previous status == 0. Also update the status veriable
 
 * **usart_ex01.c** This file will echo every character back to sender via RS232 Protocol using internall Enchanced Usart of microcontroller
 
 * **sevenseg_ex01.c** single digit seven segment interface. Auto increment Up Counter from 0-9
 
 * **sevenseg_ex02.c** two digit up counter from 0-99. Multiplexing of two digit seven segments
 
 * **sevenseg_timer_mux.c** 4 digit 7segment multiplexing using timer0 interrupt
        
        
## Projects

**FrequencyCounterV01.c** Frequency Counter display over Usart PIC16F887 with 8MHz Crystal, able to count frequency randing from 1Hz upto 65KHz

## Coding Style


[Google C++ Style will be preffered but not a limitation to contribute](https://google.github.io/styleguide/cppguide.html#Self_contained_Headers)





## Contributions
Any kind of contributions, like more examples, examples for more architectures, corrections, comments, etc. are very welcome. Feel free to open an issue or fork and pull request.
