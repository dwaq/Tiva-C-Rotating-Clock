#include "display.h"
#include "delay.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define BLANK 0x10

// set all LED pins to outputs
void displaySetup(void) {
    // Enable the GPIO ports
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Check if the peripheral access is enabled
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)) {}
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {}
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)) {}
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {}

    // Set the GPIOs as digital outputs
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_0); // X0
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1); // X1
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_2); // X2
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_3); // X3
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4); // X4
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_5); // X5

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2); // X6
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_3); // X7
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_4); // X8
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5); // X9
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6); // X10
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_7); // X11

    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0); // Bit0
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_1); // Bit1
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_2); // Bit2
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_3); // Bit3
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_4); // Bit4
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_5); // Bit5
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_6); // Bit6
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_7); // Bit7
}

// cycle through and display each digit
// dp is for decimal point: 0 for off; 1 for on
void displayDigits(int dig1, int dig2, int dp, int dig3, int dig4) {
    // don't display anything on dig1 if it's '0'
    if(dig1 == 0)
        setDigit(1, BLANK);
    else
        setDigit(1, dig1);

    setDigit(2, dig2);
    setDigit(3, dig3);
    setDigit(4, dig4);
    if (dp) {
        // display decimal point (special parameter)
        decimalpoint();
    }
}

// display a number on the selected digit 1, 2, 3, or 4
void setDigit(int digit, int number) {
    // turn on specific digit
    switch (digit) {
    case 1:
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0); // Bit 8
        Delay(DISPLAY_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4); // Bit 8
        break;
    case 2:
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0); // Bit 9
        Delay(DISPLAY_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5); // Bit 9
        break;
    case 3:
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0); // Bit 10
        Delay(DISPLAY_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6); // Bit 10
        break;
    case 4:
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0); // Bit 11
        Delay(DISPLAY_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7); // Bit 11
        break;
        //default:
        // bad - should't be here
    }
}

// display a number or symbol using the 7 segments
// number can be between 0-9 or settings screen uses A-F
void setSegment(int number) {
    // first, reset all segments

    // then set the corresponding segments
    switch (number) {
    case 0:
        // A B C D E F
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11000000);
        break;
    case 1:
        // B C
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11111001);
        break;
    case 2:
        // A B D E G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10100100);
        break;
    case 3:
        // A B C D G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10110000);
        break;
    case 4:
        // B C F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10011001);
        break;
    case 5:
        // A C D F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10010010);
        break;
    case 6:
        // A C D E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10000010);
        break;
    case 7:
        // A B C
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11111000);
        break;
    case 8:
        // A B C D E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10000000);
        break;
    case 9:
        // A B C D F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10010000);
        break;
    case 0xA:
        // A B C E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10001000);
        break;
    case 0xB:
        // A B C D E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10000000);
        break;
    case 0xC:
        // A D E F
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11000110);
        break;
    case 0xD:
        // A B C D E F
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11000000);
        break;
    case 0xE:
        // A D E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10000110);
        break;
    case 0xF:
        // A E F G
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b10001110);
        break;
    default:
        // case BLANK falls through here
        // turns off all of the segments
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b11111111);
        break;
    };
}

void decimalpoint(void) {
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0); // Bit 9
    GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b01111111);
    Delay(TIMER_DELAY);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5); // Bit 9
}

void displaySeconds(int digit) {
    if (digit > 56) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 56)));
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0); // Bit 7
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3); // Bit 7
        digit = 56;
    }
    if (digit > 48) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 48)));
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0); // Bit 6
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2); // Bit 6
        digit = 48;
    }
    if (digit > 40) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 40)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0); // Bit 5
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5); // Bit 5
        digit = 40;
    }
    if (digit > 32) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 32)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0); // Bit 4
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4); // Bit 4
        digit = 32;
    }
    if (digit > 24) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 24)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0); // Bit 3
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, GPIO_PIN_3); // Bit 3
        digit = 24;
    }
    if (digit > 16) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 16)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0); // Bit 2
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, GPIO_PIN_2); // Bit 2
        digit = 16;
    }
    if (digit > 8) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 8)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0); // Bit 1
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1); // Bit 1
        digit = 8;
    }
    if (digit >= 0) {
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, (~0 << (digit - 0)));
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 0); // Bit 0
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_PIN_0); // Bit 0
    }
}
