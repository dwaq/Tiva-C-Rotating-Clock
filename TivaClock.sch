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
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 2800 2300 50  0001 C CNN
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
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 3350 2300 50  0001 C CNN
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
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 7800 2300 50  0001 C CNN
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
F 2 "Pin_Headers:Pin_Header_Straight_1x10_Pitch2.54mm" H 8500 2300 50  0001 C CNN
F 3 "" H 8500 2300 50  0001 C CNN
	1    8500 2300
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x20 J5
U 1 1 5A5BED71
P 5200 4550
F 0 "J5" H 5200 5550 50  0000 C CNN
F 1 "Conn_01x20" H 5200 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 5200 4550 50  0001 C CNN
F 3 "" H 5200 4550 50  0001 C CNN
	1    5200 4550
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x20 J6
U 1 1 5A5BEDA4
P 5950 4650
F 0 "J6" H 5950 5650 50  0000 C CNN
F 1 "Conn_01x20" H 5950 3550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 5950 4650 50  0001 C CNN
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
Wire Wire Line
	2600 2000 1900 2000
Wire Wire Line
	1900 2000 1900 5850
Wire Wire Line
	1900 5850 7450 5850
Wire Wire Line
	7450 5850 7450 4250
Wire Wire Line
	7450 4250 6150 4250
Wire Wire Line
	2600 2100 2000 2100
Wire Wire Line
	2000 2100 2000 6000
Wire Wire Line
	2000 6000 7650 6000
Wire Wire Line
	7650 6000 7650 3750
Wire Wire Line
	7650 3750 6150 3750
Wire Wire Line
	2600 2200 2100 2200
Wire Wire Line
	2100 2200 2100 6100
Wire Wire Line
	2100 6100 8000 6100
Wire Wire Line
	8000 6100 8000 3850
Wire Wire Line
	8000 3850 6150 3850
Wire Wire Line
	2600 2500 2200 2500
Wire Wire Line
	2200 2500 2200 6200
Wire Wire Line
	2200 6200 8100 6200
Wire Wire Line
	8100 6200 8100 4150
Wire Wire Line
	8100 4150 6150 4150
Wire Wire Line
	2600 2600 2300 2600
Wire Wire Line
	2300 2600 2300 5050
Wire Wire Line
	2300 5050 5000 5050
Wire Wire Line
	2600 2700 2400 2700
Wire Wire Line
	2400 2700 2400 5150
Wire Wire Line
	2400 5150 5000 5150
Wire Wire Line
	2600 2800 2500 2800
Wire Wire Line
	2500 2800 2500 5250
Wire Wire Line
	2500 5250 5000 5250
Wire Wire Line
	8700 2000 9000 2000
Wire Wire Line
	9000 2000 9000 3950
Wire Wire Line
	9000 3950 6150 3950
Wire Wire Line
	8700 2100 9150 2100
Wire Wire Line
	9150 2100 9150 5550
Wire Wire Line
	9150 5550 6150 5550
Wire Wire Line
	8700 2400 9250 2400
Wire Wire Line
	9250 2400 9250 4450
Wire Wire Line
	9250 4450 6150 4450
Wire Wire Line
	8700 2500 9400 2500
Wire Wire Line
	9400 2500 9400 4350
Wire Wire Line
	9400 4350 6150 4350
Wire Wire Line
	8700 2600 9550 2600
Wire Wire Line
	9550 2600 9550 6350
Wire Wire Line
	9550 6350 4100 6350
Wire Wire Line
	4100 6350 4100 4950
Wire Wire Line
	4100 4950 5000 4950
Wire Wire Line
	8700 2700 9700 2700
Wire Wire Line
	9700 2700 9700 4850
Wire Wire Line
	9700 4850 6150 4850
Wire Wire Line
	8700 2800 9800 2800
Wire Wire Line
	9800 2800 9800 4950
Wire Wire Line
	9800 4950 6150 4950
Wire Wire Line
	3550 2500 7000 2500
Wire Wire Line
	7000 2500 7000 5450
Wire Wire Line
	7000 5450 6150 5450
Wire Wire Line
	3550 2600 6900 2600
Wire Wire Line
	6900 2600 6900 5350
Wire Wire Line
	6900 5350 6150 5350
Wire Wire Line
	3550 2700 6800 2700
Wire Wire Line
	6800 2700 6800 5250
Wire Wire Line
	6800 5250 6150 5250
Wire Wire Line
	7600 2100 7100 2100
Wire Wire Line
	7100 2100 7100 4050
Wire Wire Line
	7100 4050 6150 4050
Wire Wire Line
	2600 2300 1450 2300
Wire Wire Line
	1450 2300 1450 6450
Wire Wire Line
	1450 6450 7800 6450
Wire Wire Line
	7800 6450 7800 5150
Wire Wire Line
	7800 5150 6150 5150
Wire Wire Line
	2600 2400 1600 2400
Wire Wire Line
	1600 2400 1600 6550
Wire Wire Line
	1600 6550 7900 6550
Wire Wire Line
	7900 6550 7900 5050
Wire Wire Line
	7900 5050 6150 5050
Wire Wire Line
	7600 2200 4050 2200
Wire Wire Line
	4050 2200 4050 4050
Wire Wire Line
	4050 4050 5000 4050
Wire Wire Line
	7600 2800 3800 2800
Wire Wire Line
	3800 2800 3800 4750
Wire Wire Line
	3800 4750 5000 4750
Wire Wire Line
	8700 2200 8800 2200
Wire Wire Line
	8800 2200 8800 3400
Wire Wire Line
	8800 3400 3500 3400
Wire Wire Line
	3500 3400 3500 4850
Wire Wire Line
	3500 4850 5000 4850
Wire Wire Line
	7600 2300 4300 2300
Wire Wire Line
	4300 2300 4300 3950
Wire Wire Line
	4300 3950 5000 3950
Wire Wire Line
	4400 3850 5000 3850
Wire Wire Line
	4400 3850 4400 2400
Wire Wire Line
	4400 2400 7600 2400
Wire Wire Line
	7600 2500 7200 2500
Wire Wire Line
	7200 2500 7200 2950
Wire Wire Line
	7200 2950 4500 2950
Wire Wire Line
	4500 2950 4500 3750
Wire Wire Line
	4500 3750 5000 3750
Wire Wire Line
	3550 2300 3700 2300
Wire Wire Line
	3700 2300 3700 3650
Wire Wire Line
	3700 3650 5000 3650
Wire Wire Line
	7600 2600 7300 2600
Wire Wire Line
	7300 2600 7300 3050
Wire Wire Line
	7300 3050 3250 3050
Wire Wire Line
	3250 3050 3250 4550
Wire Wire Line
	3250 4550 5000 4550
Wire Wire Line
	7600 2700 7400 2700
Wire Wire Line
	7400 2700 7400 3100
Wire Wire Line
	7400 3100 3100 3100
Wire Wire Line
	3100 3100 3100 4650
Wire Wire Line
	3100 4650 5000 4650
$Comp
L GS3 J7
U 1 1 5A6B36DA
P 5450 1350
F 0 "J7" H 5500 1550 50  0000 C CNN
F 1 "GS3" H 5500 1151 50  0000 C CNN
F 2 "Connectors:GS3" V 5538 1276 50  0001 C CNN
F 3 "" H 5450 1350 50  0001 C CNN
	1    5450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 1350 6650 1350
Wire Wire Line
	6650 1350 6650 4550
Wire Wire Line
	6650 3650 6150 3650
Wire Wire Line
	6650 4550 6150 4550
Connection ~ 6650 3650
Wire Wire Line
	5300 1250 2450 1250
Wire Wire Line
	2450 1250 2450 1900
Wire Wire Line
	2450 1900 2600 1900
Wire Wire Line
	3550 1900 4800 1900
Wire Wire Line
	4800 1900 4800 1450
Wire Wire Line
	4800 1450 5300 1450
NoConn ~ 3550 2100
NoConn ~ 3550 2200
NoConn ~ 3550 2400
NoConn ~ 3550 2800
NoConn ~ 7600 1900
NoConn ~ 7600 2000
NoConn ~ 6150 4750
NoConn ~ 6150 4650
NoConn ~ 5000 4150
NoConn ~ 5000 4250
NoConn ~ 5000 4350
NoConn ~ 5000 5350
NoConn ~ 5000 5450
$EndSCHEMATC
