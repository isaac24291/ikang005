/*    Author: Isaac Kang
 *    Partner(s) Name:
 *    Lab Section: 21
 *    Assignment: Lab #8  Exercise #3
 *    Exercise Description: [optional - include for your own benefit]
 *
 *    I acknowledge all content contained herein, excluding template or example
 *    code, is my own original work.
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    
    ADC_init();

    unsigned short convADC;
    unsigned short ledMax = 0x0C7;
    
    while (1) {
        convADC = ADC;
        if (convADC >= ledMax / 2){
            PORTB = 0x01;
        }
        else{
            PORTB = 0x00;
        }
    }
    return 1;
}