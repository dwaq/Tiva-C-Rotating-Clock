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
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4); // I/O
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5); // SCLK

    // set all I/O low
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, 0);
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);

    // delay for a while to catch it on scope
    DelayRTC(1000);
}

void sendBit(int bit) {
    // set I/O according to `bit`
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_4, bit << 4);
    // wait 200 ns
    DelayRTC(20);

    // set CLK high
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
    // wait 1000ns
    DelayRTC(100);

    // set CLK low
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
    // wait between 200-800 ns (make it even)
    DelayRTC(100);
}

int readBit(void) {
    // read bit
    int data = GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4);

    // format data into a bit at LSB
    data = (data & GPIO_PIN_4) >> 4;

    // set CLK high
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
    // wait 1000ns
    DelayRTC(100);

    // set CLK low
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
    // wait between 200-800 ns  (make it even)
    DelayRTC(100);

    // return read bit
    return data;
}

int rtcRead(int address) {
    // send address (bits already formatted)
    // bit 7 (must be 1)
    // bit 6 (0 for clock data)
    // bit 5 - 1 are address to read, LSB first
    // bit 0 (1 for read)
    int bit = 0;
    for(bit = 0; bit < 8; bit++) {
        // send LSB
        sendBit(address & 0x1);
        // shift one for next iteration
        address = address >> 1;
    }

    // read response
    // change I/O to input
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, GPIO_PIN_4); // I/O

    int response = 0;
    // in burst mode, so can read 3x bytes and get hours, minutes, seconds
    for(bit = 0; bit < 24; bit++) {
        // read a bit
        int data = readBit();

        // shift data according to bit and add to response
        response += (data << bit);
    }

    // Change I/O back to output
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4); // I/O

    return response;
}

int rtcGetTime(void) {
    // set CS
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, GPIO_PIN_7);
    // needs to be > 4us
    DelayRTC(40);

    // send command for clock burst mode
    // and get 3 bytes of data
    int response = rtcRead(0xBF);

    // reset CS
    GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);

    // format data & return
    return response;
}
