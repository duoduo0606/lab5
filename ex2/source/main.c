/*	Author: yxing024
 *  Partner(s) Name: hao wu
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

typedef enum States {start, init, add, release, waitb, minus, reset } States;

int ex2Tick(int);

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    States state = start;
    while (1) {
        state = ex2Tick(state);
    }
    return 1;
}

int ex2Tick(int state) {
    static unsigned char cntC = 0x00;
    
    unsigned char A0 = PINA & 0x01;
    unsigned char A1 = PINA & 0x02;

    
    switch (state) { // Transitions
        case start:
            state = init;
            break;
        case init:
	  if (A0) { state = add; } 
	  if (A1) { state = minus; } 
            break;
        case add:
          if (!A0) { state = release; } 
	  if (A0) { state = waitb; } 
	  if (A1) { state = reset; } 
            break;
        case release:
          if (A0) { state = add; } 
	  if (A1) { state = minus; }
            break;
        case waitb:
          if ((!A0)&(!A1)) { state = release; } 
	 
            break;
        case minus:
          if (!A1) { state = release; } 
	  if (A1) { state = waitb; } 
	  if (A0) { state = reset; } 
            break;
        case reset:
            state = waitb;
            break;
        default:
            state = start;
            break;
    }
    switch (state) { // Actions
        case start: break;
        case init: 
            cntC = 0;
            break;
        case add: 
	    if (cntC < 9){cntC++;}
	    break;
        case release: break;
        case waitb: break;
        case minus:
	    if (cntC > 0){cntC--;}
            break;
        case reset: 
	  cntC = 0;
	    break;
    }
    PORTC = state;//cntC;
    return state;
}
