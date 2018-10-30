# Microchip PIC Codebase
PIC16 microcontroller based Embedded system development code base for demonstrating how to use different PIC features using C language



## Examples
This folder contains files for some simple examples
    
 * singleLEDFlasher_ex01.c
    This file blink single LED on PORTD.0 with fix 500ms delay with 8Mhz Crystal
 * pushbutton_ex01.c
    This file print active low state to output LED connected to PORTD.0 and button connected with PORTB.0
    10K pullup resistor is connected in hardware. LED will remain on untill button is pressed and once button
    is released LED turns off
        

## Coding Style


[Google C++ Style will be preffer but not restricted](https://google.github.io/styleguide/cppguide.html#Self_contained_Headers)