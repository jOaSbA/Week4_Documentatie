#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stdbool.h>

// ENUM met port offsets
typedef enum {
    PORT1 = 0x0000,
    PORT2 = 0x0001,
    PORT3 = 0x0020,
    PORT4 = 0x0021
} PortOffset;

// Functie prototypes
void pinSet(PortOffset port, uint8_t bit, bool val);
void pinMode(PortOffset portOffset, uint8_t bit, bool output);

#endif