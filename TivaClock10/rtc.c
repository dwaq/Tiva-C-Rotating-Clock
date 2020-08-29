#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

// Delay for a bit.
void DelayRTC(int time) {
    volatile uint32_t ui32Loop;
    for (ui32Loop = 0; ui32Loop < time; ui32Loop++) {}
}

// need to bit bang because I didn't connect MCU I2C pins to RTC
void rtcSetup(void) {
    // Enable the GPIO ports
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);

    // Check if the peripheral access is enabled
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC)) {}

    // Set the GPIOs as digital outputs
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_7); // CE
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_6); // I/O
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5); // SCLK

    // set all I/O low
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
}

int rtcGetTime(void) {
    // set CS
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 1);
    DelayRTC(500);

    // send address

    // get data

    // reset CS
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);

    // format data & return
    return 0;
}
