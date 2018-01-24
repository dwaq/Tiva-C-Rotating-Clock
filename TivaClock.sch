EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:TivaClock-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_01x10 J1
U 1 1 5A5BEAC9
P 2800 2300
F 0 "J1" H 2800 2800 50  0000 C CNN
F 1 "Conn_01x10" H 2800 1700 50  0000 C CNN
F 2 "" H 2800 2300 50  0001 C CNN
F 3 "" H 2800 2300 50  0001 C CNN
	1    2800 2300
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x10 J3
U 1 1 5A5BEB8A
P 3350 2300
F 0 "J3" H 3350 2800 50  0000 C CNN
F 1 "Conn_01x10" H 3350 1700 50  0000 C CNN
F 2 "" H 3350 2300 50  0001 C CNN
F 3 "" H 3350 2300 50  0001 C CNN
	1    3350 2300
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x10 J4
U 1 1 5A5BED0F
P 7800 2300
F 0 "J4" H 7800 2800 50  0000 C CNN
F 1 "Conn_01x10" H 7800 1700 50  0000 C CNN
F 2 "" H 7800 2300 50  0001 C CNN
F 3 "" H 7800 2300 50  0001 C CNN
	1    7800 2300
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x10 J2
U 1 1 5A5BED3B
P 8500 2300
F 0 "J2" H 8500 2800 50  0000 C CNN
F 1 "Conn_01x10" H 8500 1700 50  0000 C CNN
F 2 "" H 8500 2300 50  0001 C CNN
F 3 "" H 8500 2300 50  0001 C CNN
	1    8500 2300
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x20 J?
U 1 1 5A5BED71
P 5200 4550
F 0 "J?" H 5200 5550 50  0000 C CNN
F 1 "Conn_01x20" H 5200 3450 50  0000 C CNN
F 2 "" H 5200 4550 50  0001 C CNN
F 3 "" H 5200 4550 50  0001 C CNN
	1    5200 4550
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x20 J?
U 1 1 5A5BEDA4
P 5950 4650
F 0 "J?" H 5950 5650 50  0000 C CNN
F 1 "Conn_01x20" H 5950 3550 50  0000 C CNN
F 2 "" H 5950 4650 50  0001 C CNN
F 3 "" H 5950 4650 50  0001 C CNN
	1    5950 4650
	-1   0    0    1   
$EndComp
Text Label 4550 3650 0    60   ~ 0
DS18B20
Text Label 4550 3750 0    60   ~ 0
1302RST
Text Label 4550 3850 0    60   ~ 0
1302IO
Text Label 4550 3950 0    60   ~ 0
1302CLK
Text Label 4550 4050 0    60   ~ 0
BEEP
Text Label 4550 4450 0    60   ~ 0
RESET
Text Label 4550 4550 0    60   ~ 0
RXD
Text Label 4550 4650 0    60   ~ 0
TXD
Text Label 4550 4750 0    60   ~ 0
MODE
Text Label 4550 4850 0    60   ~ 0
PLUS
Text Label 4550 4950 0    60   ~ 0
Bit8
Text Label 4550 5050 0    60   ~ 0
Bit9
Text Label 4550 5150 0    60   ~ 0
Bit10
Text Label 4550 5250 0    60   ~ 0
Bit11
Text Label 4550 5550 0    60   ~ 0
GND
Text Label 6300 5550 0    60   ~ 0
Bit0
Text Label 6300 5450 0    60   ~ 0
Bit1
Text Label 6300 5350 0    60   ~ 0
Bit2
Text Label 6300 5250 0    60   ~ 0
Bit3
Text Label 6300 5150 0    60   ~ 0
Bit4
Text Label 6300 5050 0    60   ~ 0
Bit5
Text Label 6300 4950 0    60   ~ 0
Bit6
Text Label 6300 4850 0    60   ~ 0
Bit7
Text Label 6300 4550 0    60   ~ 0
VCC
Text Label 6300 4450 0    60   ~ 0
X7
Text Label 6300 4350 0    60   ~ 0
X6
Text Label 6300 4250 0    60   ~ 0
X5
Text Label 6300 4150 0    60   ~ 0
X4
Text Label 6300 4050 0    60   ~ 0
X3
Text Label 6300 3950 0    60   ~ 0
X2
Text Label 6300 3850 0    60   ~ 0
X1
Text Label 6300 3750 0    60   ~ 0
X0
Text Label 6300 3650 0    60   ~ 0
VCC
Wire Wire Line
	5000 4050 4350 4050
Wire Wire Line
	4350 4050 4350 3350
Wire Wire Line
	4350 3350 9000 3350
Wire Wire Line
	9000 3350 9000 2000
Wire Wire Line
	9000 2000 8700 2000
Wire Wire Line
	8700 2300 8900 2300
Wire Wire Line
	8900 2300 8900 3200
Wire Wire Line
	8900 3200 4200 3200
Wire Wire Line
	4200 3200 4200 4450
Wire Wire Line
	4200 4450 5000 4450
Wire Wire Line
	5000 4550 2150 4550
Wire Wire Line
	2150 4550 2150 2100
Wire Wire Line
	2150 2100 2600 2100
Wire Wire Line
	5000 4650 2300 4650
Wire Wire Line
	2300 4650 2300 2200
Wire Wire Line
	2300 2200 2600 2200
Wire Wire Line
	3550 2000 7000 2000
Wire Wire Line
	7000 2000 7000 1700
Wire Wire Line
	7000 1700 8800 1700
Wire Wire Line
	8800 1700 8800 1900
Wire Wire Line
	8800 1900 8700 1900
Wire Wire Line
	5000 5550 3900 5550
Wire Wire Line
	3900 5550 3900 2000
Connection ~ 3900 2000
$EndSCHEMATC
