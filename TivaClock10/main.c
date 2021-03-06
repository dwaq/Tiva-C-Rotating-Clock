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

// keep track of time
int hourL,hourR,minL,minR,seconds;

// every second, increase a counter
int refresh = 0;
void everySecond(void) {
    refresh++;
}

int main(void) {

    // set up a interrupt callback function
    SysTickIntRegister((*everySecond));

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
        // when counter has been increased by one second SysTick
        if (refresh != 0) {
            // get time from RTC
            int time = rtcGetTime();

            // format based on datasheet
            hourL = (time & 0b000100000000000000000000) >> 20;
            hourR = (time & 0b000011110000000000000000) >> 16;

            minL = (time & 0b0111000000000000) >> 12;
            minR = (time & 0b0000111100000000) >> 8;

            int secL = (time & 0b01110000) >> 4;
            int secR = (time & 0b00001111);

            seconds = (secL * 10) + secR;

            // reset counter
            refresh = 0;
        }
        // display the time
        displayDigits(hourL, hourR, true, minL, minR);

        // add one to make 0 display at the top-most position
        displaySeconds(seconds+1);
    }
}
