//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

void decimalpoint(void);
void setDigit(int digit, int number);
void setSegment(int number);

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

#define TIMER_DELAY 200

//
// Delay for a bit.
//
void Delay(int time)
{
    volatile uint32_t ui32Loop;
    for(ui32Loop = 0; ui32Loop < time; ui32Loop++){}
}

// cycle through and display each digit
// dp is for decimal point: 0 for off; 1 for on
void displayDigits(int dig1, int dig2, int dp, int dig3, int dig4)
{
  setDigit(1, dig1);
  setDigit(2, dig2);
  setDigit(3, dig3);
  setDigit(4, dig4);
  if (dp)
  {
    // display decimal point (special parameter)
    decimalpoint();
  }

}
/*
GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0);  // Bit 8
setSegment(counter);
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);  // Bit 8

GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);  // Bit 9
setSegment(counter);
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);  // Bit 9

decimalpoint();

GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);  // Bit 10
setSegment(counter);
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);  // Bit 10

GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);  // Bit 11
setSegment(counter);
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);  // Bit 11
*/
// display a number on the selected digit 1, 2, 3, or 4
void setDigit(int digit, int number) {
    // turn on specific digit
    switch (digit) {
    case 1:
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, 0);  // Bit 8
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);  // Bit 8
        break;
    case 2:
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);  // Bit 9
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);  // Bit 9
        break;
    case 3:
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);  // Bit 10
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);  // Bit 10
        break;
    case 4:
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);  // Bit 11
        setSegment(number);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);  // Bit 11
        break;
    //default:
    // bad - should't be here
    }
}

// display a number or symbol using the 7 segments
// number can be between 0-9 or settings screen uses A-F
void setSegment(int number)
{
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
        //default:
        // case BLANK falls through here
        // just turns off the segment by initial "reset all segments" code
    };
    Delay(500);
}

void displaySeconds(int digit){
    if (digit >= 56)
    {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);  // Bit 7
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 56)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);  // Bit 7
        digit = 48;
    }
    if (digit >= 48)
    {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);  // Bit 6
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 48)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);  // Bit 6
        digit = 40;
    }
    if (digit >= 40)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, 0);  // Bit 5
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 40)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);  // Bit 5
        digit = 32;
    }
    if (digit >= 32)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);  // Bit 4
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 32)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);  // Bit 4
        digit = 24;
    }
    if (digit >= 24)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, 0);  // Bit 3
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 24)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_3, GPIO_PIN_3);  // Bit 3
        digit = 16;
    }
    if (digit >= 16)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0);  // Bit 2
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 16)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, GPIO_PIN_2);  // Bit 2
        digit = 8;
    }
    if (digit >= 8)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);  // Bit 1
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 8)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1);  // Bit 1
        digit = 0;
    }
    if (digit >= 0)
    {
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, 0);  // Bit 0
        GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, ~(~0 << (digit - 0)));
        Delay(TIMER_DELAY);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_PIN_0);  // Bit 0
    }
}


void decimalpoint(void){
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);  // Bit 9
    GPIOPinWrite(GPIO_PORTB_BASE, 0xFF, 0b01111111);
    Delay(TIMER_DELAY);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);  // Bit 9
}

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int main(void)
{
    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)){}
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)){}
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}

    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
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

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

    int counter = 0;

    //
    // Loop forever.
    //
    while(1)
    {
        //for(xn = 0x1; xn <= 0x80; xn <<= 1){  // clockwise
        //for(xn = 0x80; xn >= 0x1; xn >>= 1){  // counter-clockwise
        /*
        // all Bits on
        GPIOPinWrite(GPIO_PORTE_BASE, 0x3F, 0); //b0-5
        GPIOPinWrite(GPIO_PORTA_BASE, 0xFC, 0); //b6-11

        while(1){
            GPIOPinWrite(GPIO_PORTB_BASE, 0b01100000, 0);
            Delay(TIMER_DELAY0);
            GPIOPinWrite(GPIO_PORTB_BASE, 0b01100000, 0b01100000);
            Delay(TIMER_DELAY0);
        }
        GPIOPinWrite(GPIO_PORTB_BASE, 0b01000000, 0);
        */
        // all X's on
        //int xn;
        /*
        for(xn = 0x1; xn < 0x80; xn <<= 1){
            GPIOPinWrite(GPIO_PORTB_BASE, xn, 0);
            Delay(TIMER_DELAY);
            GPIOPinWrite(GPIO_PORTB_BASE, xn, xn);
            Delay(TIMER_DELAY);
        }
        */


        /*
        int Bit;

        // turn on bits 0-5
        for(Bit = 0x1; Bit <= 0x20; Bit <<= 1){
            GPIOPinWrite(GPIO_PORTE_BASE, Bit, 0);

            int xn;

            // turn on X's
            for(xn = 0x1; xn <= 0x80; xn <<= 1){
                GPIOPinWrite(GPIO_PORTB_BASE, xn, 0);
                Delay(TIMER_DELAY);
            }

            // turn off X's
            for(xn = 0x1; xn <= 0x80; xn <<= 1){
                GPIOPinWrite(GPIO_PORTB_BASE, xn, xn);
                Delay(TIMER_DELAY);
            }
        }

        // turn on bits 6-11
        for(Bit = 0x4; Bit <= 0x80; Bit <<= 1){
            GPIOPinWrite(GPIO_PORTA_BASE, Bit, 0);

            int xn;

            // turn on X's
            for(xn = 0x1; xn <= 0x80; xn <<= 1){
                GPIOPinWrite(GPIO_PORTB_BASE, xn, 0);
                Delay(TIMER_DELAY);
            }

            // turn off X's
            for(xn = 0x1; xn <= 0x80; xn <<= 1){
                GPIOPinWrite(GPIO_PORTB_BASE, xn, xn);
                Delay(TIMER_DELAY);
            }
        }
        */


        displayDigits(1, 2, 1, 3, 4);

        displaySeconds(counter);

        counter++;

        if (counter == 60)
        {
            counter = 0;
        }


    }
}


/*

*/


/*
        // led number to display
        counter++;



        // restart at 60
        if (counter == 60)
        {
            counter = 0;
        }
*/

/*
// turn on
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);  // X0
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, GPIO_PIN_1);  // X1
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_PIN_2);  // X2
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_PIN_3);  // X3
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_PIN_4);  // X4
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, GPIO_PIN_5);  // X5
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, GPIO_PIN_6);  // X6
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, GPIO_PIN_7);  // X7
Delay(TIMER_DELAY);
*/

/*
// turn off
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0);  // X0
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);  // X1
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_2, 0);  // X2
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_3, 0);  // X3
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0);  // X4
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_5, 0);  // X5
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_6, 0);  // X6
Delay(TIMER_DELAY);
GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_7, 0);  // X7
Delay(TIMER_DELAY);
*/
