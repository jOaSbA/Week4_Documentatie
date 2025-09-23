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

typedef enum{
    DIGITAL = 0,
    PRIMARY = 1,
    SECONDARY = 2,
    TERTIARY = 3
} purposeFunction;

// Functie prototypes
void pinSet(PortOffset port, uint8_t bit, bool val);
void pinToggle(PortOffset port, uint16_t bit);
bool pinGet(PortOffset port, uint16_t bit);
void pinConfigInput(PortOffset port, uint8_t bit, bool pullResistor, bool pullUP, bool IES, bool IE);
void pinSetDir(PortOffset port, uint16_t bit, uint16_t val);
void pinConfigFunction(PortOffset port, uint8_t bit, purposeFunction pf);

#endif