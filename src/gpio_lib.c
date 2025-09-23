#include <msp430.h>
#include "gpio.h"

void pinSet(uint16_t port, uint16_t bit, bool val){
    val ? (&P1OUT + port) |= (1 << bit) : (&P1OUT + port) &= ~(1 << bit);
}

