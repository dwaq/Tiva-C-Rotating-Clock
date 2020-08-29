#ifndef RTC_H_
#define RTC_H_

// used Arduino & library from https://github.com/msparks/arduino-ds1302
// to manually program the RTC

// RTC pin connections:
// CE   PC7
// I/O  PC4
// SCLK PC5

// set up pins for DS1302 RTC
void rtcSetup(void);

// get the time from the RTC
int rtcGetTime(void);

#endif /* RTC_H_ */
