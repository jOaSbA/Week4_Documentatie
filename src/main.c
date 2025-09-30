#include <msp430.h>
#include "gpio_lib.h"

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;       // Stop WDT
  PM5CTL0 &= ~LOCKLPM5; //unlock GPIO

  while(1)
  {
    
    pinSet(PORT2, 2, bool 1);

    __delay_cycles(500000);
  }
}
