#include <msp430.h>
#include "..\include\gpio_lib.h"

//ledmatrix
uint8_t ledm_x[8] = {9, 14, 8, 12, 1, 7, 2, 5};
uint8_t ledm_y[8] = {13, 3, 4, 10, 6, 11, 15, 16};

void pinSet(PortOffset port, uint8_t bit, bool val){
    val ? (*(&P1OUT + port) |= (1 << bit)) : (*(&P1OUT + port) &= ~(1 << bit));
}

void pinToggle(PortOffset	port, uint8_t bit){
    *(&P1OUT + port) ^= (1 << bit);
}

bool pinGet(PortOffset port, uint8_t bit){
    return (*(&P1IN + port) & (1 << bit)) != 0;
}

void pinConfigInput(PortOffset port, uint8_t bit, bool resistor, bool pullup, bool IES, bool IE){
    *(&P1DIR + port) &= ~(1 << bit);    //Zet pin als input 

    if(resistor){
        *(&P1REN + port) |= (1 << bit);     // Resistor enable
        pullup ? (*(&P1OUT + port) |= (1 << bit)) : (*(&P1OUT + port) &= ~(1 << bit));  //pullup ? (true)Pull-up : (false)Pull-down
    } else {
        *(&P1REN + port) &= ~(1 << bit);    // Resistor disable
    }

    IES ? (*(&P1IES + port) |= (1 << bit)) : (*(&P1IES + port) &= ~(1 << bit));     // Interrupt edge select
    IE ? (*(&P1IE + port) |= (1 << bit)) : (*(&P1IE + port) &= ~(1 << bit));        // Interrupt enable

}

void pinSetDir(PortOffset port, uint8_t bit, bool output){
    output ? (*(&P1DIR + port) |= (1 << bit)) : (*(&P1DIR + port) &= ~(1 << bit));
}

void pinConfigFunction(PortOffset port, uint8_t bit, purposeFunction pf){
    switch(pf){
        case DIGITAL:
            *(&P1SEL0 + port) &= ~(1 << bit);
            *(&P1SEL1 + port) &= ~(1 << bit);
            break;
        case PRIMARY:
            *(&P1SEL0 + port) |= (1 << bit);
            *(&P1SEL1 + port) &= ~(1 << bit);
            break;
        case SECONDARY:
            *(&P1SEL0 + port) &= ~(1 << bit);
            *(&P1SEL1 + port) |= (1 << bit);
            break;
        case TERTIARY:
            *(&P1SEL0 + port) |= (1 << bit);
            *(&P1SEL1 + port) |= (1 << bit);
            break;  
    }      
}
