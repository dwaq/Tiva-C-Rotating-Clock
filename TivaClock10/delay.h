#ifndef _DELAY_H
#define _DELAY_H

#include <stdint.h>

#define TIMER_DELAY 200

// Delay for a bit.
void Delay(int time) {
    volatile uint32_t ui32Loop;
    for (ui32Loop = 0; ui32Loop < time; ui32Loop++) {}
}

#endif /* _DELAY_H */
