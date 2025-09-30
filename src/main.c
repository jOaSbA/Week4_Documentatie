#include <msp430.h>
#include "..\include\gpio_lib.h"

int main(void)
{
  WDTCTL = WDTPW | WDTHOLD;       // Stop WDT
  PM5CTL0 &= ~LOCKLPM5;           //unlock GPIO

  pinSetDir(PORT1, 2, true);
  
  while(1)
  {
    
    pinSet(PORT1, 2, 1);

    __delay_cycles(500000);
  }
}
