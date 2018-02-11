//*****************************************************************************
//
// main.c
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/debug.h"

#include "display.h"

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char * pcFilename, uint32_t ui32Line) {
    while (1);
}
#endif

int main(void) {

    displaySetup();

    int counter = 0;

    // Loop forever
    while (1) {
        displayDigits(1, 2, 1, 3, 4);

        displaySeconds(counter);

        counter++;

        if (counter == 60) {
            counter = 0;
        }

    }
}
