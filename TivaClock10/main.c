//*****************************************************************************
//
// main.c
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/debug.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"

#include "rtc.h"
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

int counter = 0;

void increaseCounter(void) {
    counter++;

    // restart after 60 seconds
    if (counter > 60) {
        counter = 0;
    }
}

int main(void) {

    // set up a interrupt callback function
    SysTickIntRegister((*increaseCounter));

    // set the SysTick to the same as the system clock, so 1 second
    SysTickPeriodSet(SysCtlClockGet());

     // enable the SysTick
    SysTickEnable();

    // enable the interrupt for the SysTick
    SysTickIntEnable();

    // set up IO for RTC
    rtcSetup();

    // set up IO for display
    displaySetup();

    // Loop forever
    while (1) {
        // get time from RTC
        int seconds = rtcGetTime();

        // format based on datasheet
        int secL = (seconds & 0b01110000) >> 4;
        int secR = (seconds & 0b00001111);

        // display
        displayDigits(1, 2, 1, secL, secR);

        displaySeconds(counter);
    }
}
