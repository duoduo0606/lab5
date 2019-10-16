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


int main(void) {
    /* Insert DDR and PORT initializations */
  DDRA = 0x00;  PORTA = 0xFF;
  DDRC = 0xFF;  PORTC = 0x00;
  unsigned char PA = 0x00;
  unsigned char tmpC = 0x00;



    /* Insert your solution below */
    while (1)
      {
	PA = (0x0F &(~PINA));
        tmpC = 0x00;
   switch (PA){
      case 0:
      tmpC = 0x40;
      break;
      case 1:
      tmpC = 0x60;
      break;
      case 2:
      tmpC = 0x60;
      break;
      case 3:
      tmpC = 0x70;
      break;
      case 4:
      tmpC = 0x70;
      break;
      case 5:
      tmpC = 0x38;
      break;
      case 6:
      tmpC = 0x38;
      break;
      case 7:
      tmpC = 0x3C;
      break;
      case 8:
      tmpC = 0x3C;
      break;
      case 9:
      tmpC = 0x3C;
      break;
      case 10:
      tmpC = 0x3E;
      break;
      case 11:
      tmpC = 0x3E;
      break;
      case 12:
      tmpC = 0x3E;
      break;
      case 13:
      tmpC = 0x3F;
      break;
      case 14:
      tmpC = 0x3F;
      break;
      case 15:
      tmpC = 0x3F;
      break;
 }
     PORTC = tmpC;
}
    return 1;
}
