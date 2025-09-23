#include <msp430.h>
#include "gpio.h"

void pinSet(uint16_t port, uint16_t bit, bool val){
    val ? *(&P1OUT + port) |= (1 << bit) : *(&P1OUT + port) &= ~(1 << bit);
}

void pinToggle(uint16_t	port, uint16_t bit){
    *(&P1OUT + port) ^= (1 << bit);
}

bool pinGet(uint16_t port, uint16_t bit){
    return (*(&P1OUT + port) & (1 << bit)) != 0;
}

void pinConfigInput(PortOffset port, uint8_t bit, bool pullResistor, bool pullUP, bool IES, bool IE){
    *(&P1DIR + port) &= ~(1 << bit);    //Zet pin als input 

    if(pullResistor){
        *(&P1REN + port) |= (1 << bit);     // Resistor enable
        pullUP ? *(&P1OUT + port) |= (1 << bit) : *(&P1OUT + port) &= ~(1 << bit);  // Pull-up : Pull-down
        } else {
        *(&P1REN + port) &= ~(1 << bit);    // Resistor disable
    }

    IES ? (*(&P1IES + port) |= (1 << bit)) : (*(&P1IES + port) &= ~(1 << bit));     // Interrupt edge select
    IE ? (*(&P1IE + port) |= (1 << bit)) : (*(&P1IE + port) &= ~(1 << bit));        // Interrupt enable

}

void pinSetDir(PortOffset port, uint16_t bit, uint16_t output){
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
