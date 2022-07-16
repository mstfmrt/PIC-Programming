/*
 * File:   main.c
 * Author: mustafa
 *
 * Created on July 15, 2022, 4:35 PM
 * 
 * In this project with one button you can set a timer up to 31 min. It shows minutes in binary.
 */


#include "config.h"

#define _XTAL_FREQ 4000000
#define WAIT 25


void main(void) {
    unsigned char timer =1;
    TRISB=0B00100000;//sets b5 as input others as output
    PORTB= 1; //with binary conversion sets output pins high or low
    int sTC = WAIT;
    int i;
    while(1){
        timer = 1;
        PORTB = timer;
        sTC = WAIT;
        while(sTC!=0){
            if(RB5){
                if(timer>30){
                    timer =1;
                }
                else{
                    timer++;
                }
                PORTB=timer;
                sTC=WAIT;
            }
            sTC--;
            __delay_ms(200);
        }
        while(timer != 0){
            for(i = 0;i<60;++i){
                PORTB = timer;
                __delay_ms(500);
                PORTB =0;
                __delay_ms(500);
            }
            timer--;
        
        }
        for(i=0;i<5;++i){
            PORTB = 31;
            __delay_ms(500);
            PORTB =0;
            __delay_ms(500);
            
        }
    }
    
    return;
}
