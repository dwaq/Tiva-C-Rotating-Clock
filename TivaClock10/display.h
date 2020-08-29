#ifndef _DISPLAY_H
#define _DISPLAY_H

// Setting up all pins
void displaySetup(void);

// For 7 segment display:
void displayDigits(int dig1, int dig2, int dp, int dig3, int dig4);
void setDigit(int digit, int number);
void setSegment(int number);
void decimalpoint(void);

// For LEDs:
void displaySeconds(int digit);

#endif /* _DISPLAY_H */
