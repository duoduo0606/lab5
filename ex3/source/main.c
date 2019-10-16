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

typedef enum States {start, wait, add, waitadd, restart, rewait,  minus,  waitminus } States;

int ex3Tick(int);

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
    States state = start;
    while (1) {
        state = ex3Tick(state);
    }
    return 1;
}

int ex3Tick(int state) {
    static signed char cntC = 0x00;
     static unsigned char tmp = 0x00;
    unsigned char A0 = ((~PINA) & 0x01);
    

    
    switch (state) { // Transitions
        case start:
            state = wait;
            break;
        case wait:
	  if (A0) { state = add; } 
	  else if (cntC ==6){state = restart;}
            break;
        case add:
          if (A0) { state = waitadd; } 	  
	  
            break;
        case waitadd:
          if (!A0) { state = wait; } 
	 
	    break;
    case restart:
           state = rewait;
            break;
        case rewait:
	  if (A0) { state = minus; } 
	  else if (cntC ==0 ){state = start;}
            break;
        case minus:
          if (A0) { state = waitminus; } 	  
	 
            break;
        case waitminus:
          if (!A0) { state = rewait; } 
	 
	    break;
   
    }
    switch (state) { // Actions
       case start:
	 cntC = 0;
	 tmp = 0;
            break;
        case wait:
	 
	 
            break;
        case add:
	  
	  tmp = (2<<cntC)-1;
	  cntC++;
            break;
        case waitadd:
        
	    break;
    case restart:
      tmp = 0;

            break;
        case rewait:
	  
            break;
        case minus:
         cntC--;

	 tmp =(63 - ((2<<cntC)-1));
	 
            break;
        case waitminus:
          
	    break;
	    
    }
    PORTC = tmp;
    return state;
}
