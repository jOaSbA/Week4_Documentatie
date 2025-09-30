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

/**
*
* @brief Sets a pin.
* @param[in] port:  The port (PORT1, PORT2, etc)
* @param[in] bit:   The specific pin to set on that port.
* @param[in] val:   The new value of the pin
* 
*/
void pinSet(PortOffset port, uint8_t bit, bool val);

/**
*
* @brief Toggles a pin.
* @param[in] port:  The port (PORT1, PORT2, etc)
* @param[in] pin:	The specific pin to toggle on that port.
*
*/
void pinToggle(PortOffset port, uint8_t bit);

/**
*
* @brief Gets the latch value of a pin.
* @param[in] port: The port (PORT1, PORT2, etc)
* @param[in] bit:  The specific pin to read from that port.
* @return true if the pin is high, false if low
*
*/
bool pinGet(PortOffset port, uint8_t bit);

/**
*
* @brief Configures a pin as an input.
* @param[in] port:          The port (PORT1, PORT2, etc)
* @param[in] bit:           The specific pin to configure
* @param[in] resistor       Enable/disable the pull resistor (true = enable, false = disable)
* @param[in] pullup         If pull resistor is enabled: true = pull-up, false = pull-down
* @param[in] IES:           Interrupt edge select (true = falling edge, false = rising edge)
* @param[in] IE:            Enable/disable interrupt for this pin (true = enable, false = disable)
*
*/
void pinConfigInput(PortOffset port, uint8_t bit, bool resistor, bool pullup, bool IES, bool IE);

/**
*
* @brief Sets the direction of a pin.
* @param[in] port: The port (PORT1, PORT2, etc)
* @param[in] bit:  The specific pin to configure
* @param[in] output:  1 = Output, 0 = Input
*
*/
void pinSetDir(PortOffset port, uint8_t bit, bool output);

/**
*
* @brief Configures a pin for a special peripheral function.
* @param[in] port: The port (PORT1, PORT2, etc)
* @param[in] bit:  The specific pin to configure
* @param[in] pf:   The function to assign {DIGITAL, PRIMARY, SECONDARY, TERTIARY)
*
*/
void pinConfigFunction(PortOffset port, uint8_t bit, purposeFunction pf);

#endif