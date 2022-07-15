/*
 * File:   main.c
 * Author: mstfmrt
 *
 * Created on July 14, 2022, 12:02 PM
 * 
 * In this project I started programing PICs I created same circuit when I started programming arduino without understanding 6 years ago.
*/


#include "config.h"

#define _XTAL_FREQ 4000000

void delay(){
    __delay_ms(100);
}

void main(void){
    
    TRISB0=0; //B0 pin is in output mode
    TRISB1=0; //B1 pin is in output mode
    TRISB2=0; //B2 pin is in output mode
    RB0=0;
    RB1=0;
    RB2=0;
    while(1){
        RB0=1;
        delay();
        RB0=0;
        RB1=1;
        delay();
        RB1=0;
        RB2=1;
        delay();
        RB2=0;
        RB1=1;
        delay();
        RB1=0;
    }
    return;
}



