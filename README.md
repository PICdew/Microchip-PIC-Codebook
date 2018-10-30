# Microchip PIC Codebase
PIC16 microcontroller based Embedded system development code base for demonstrating how to use different PIC features using C language



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
        

## Coding Style


[Google C++ Style will be preffer but not restricted](https://google.github.io/styleguide/cppguide.html#Self_contained_Headers





## Collaboration
Any kind of collaboration like more examples, examples for more architectures, corrections, comments, etc. are very welcome. Feel free to open an issue or fork and pull request.