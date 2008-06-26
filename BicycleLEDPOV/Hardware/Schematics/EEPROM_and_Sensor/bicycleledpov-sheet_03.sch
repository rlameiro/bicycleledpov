EESchema Schematic File Version 1
LIBS:power,../KiCAD_library/at90usb162,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,../KiCAD_library/usb-mb-h,./bicycleledpov_base.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 2 3
Title ""
Date "26 jun 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3300 3550 0    60   ~
Placeholder for Hall sensor
Kmarq B 4250 4000 "Warning Pin input Unconnected" F=1
Kmarq B 3450 3700 "Warning Pin passive Unconnected" F=1
Kmarq B 4900 2550 "Warning Pin input Unconnected" F=1
Kmarq B 4900 2650 "Warning Pin input Unconnected" F=1
Kmarq B 3650 2450 "Warning Pin output Unconnected" F=1
Kmarq B 3650 2350 "Warning Pin input Unconnected" F=1
Wire Wire Line
	3450 3700 3350 3700
Wire Wire Line
	4550 3850 4550 3700
Wire Wire Line
	4550 3700 4450 3700
Wire Wire Line
	3550 2750 3550 2650
Wire Wire Line
	3550 2650 3650 2650
Wire Wire Line
	3650 2350 3400 2350
Wire Wire Line
	5150 2550 4900 2550
Wire Wire Line
	5000 2350 4900 2350
Wire Wire Line
	4900 2450 5000 2450
Wire Wire Line
	5000 2450 5000 2250
Connection ~ 5000 2350
Wire Wire Line
	5150 2650 4900 2650
Wire Wire Line
	3650 2450 3400 2450
Wire Wire Line
	3650 2550 3450 2550
Wire Wire Line
	3450 2550 3450 2750
Wire Wire Line
	4250 4250 4250 4000
Wire Wire Line
	4050 3700 3950 3700
$Comp
L R R15
U 1 1 48639B68
P 3700 3700
F 0 "R15" V 3780 3700 50  0000 C C
F 1 "57K" V 3700 3700 50  0000 C C
	1    3700 3700
	0    -1   -1   0   
$EndComp
Text GLabel 3350 3700 0    60   Input
SENSOR_VCC
Text GLabel 4250 4250 1    60   Output
SENSOR_DATA
$Comp
L GND #PWR012
U 1 1 48639B0F
P 4550 3850
F 0 "#PWR012" H 4550 3850 30  0001 C C
F 1 "GND" H 4550 3780 30  0001 C C
	1    4550 3850
	1    0    0    -1  
$EndComp
$Comp
L NPN Q1
U 1 1 48639AFB
P 4250 3800
F 0 "Q1" H 4400 3800 50  0000 C C
F 1 "NPN" H 4152 3950 50  0000 C C
	1    4250 3800
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR013
U 1 1 4863060F
P 3450 2750
F 0 "#PWR013" H 3450 2850 30  0001 C C
F 1 "VCC" H 3450 2850 30  0000 C C
	1    3450 2750
	-1   0    0    1   
$EndComp
Text GLabel 3400 2350 0    60   Input
SPI_SS2
Text GLabel 3400 2450 0    60   Output
SPI_MISO
Text GLabel 5150 2650 2    60   Input
SPI_MOSI
Text GLabel 5150 2550 2    60   Input
SPI_SCKL
$Comp
L GND #PWR014
U 1 1 4863050B
P 3550 2750
F 0 "#PWR014" H 3550 2750 30  0001 C C
F 1 "GND" H 3550 2680 30  0001 C C
	1    3550 2750
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR015
U 1 1 48630504
P 5000 2250
F 0 "#PWR015" H 5000 2350 30  0001 C C
F 1 "VCC" H 5000 2350 30  0000 C C
	1    5000 2250
	1    0    0    -1  
$EndComp
$Comp
L AT25128A U9
U 1 1 486304E1
P 4250 2500
F 0 "U9" H 4500 2200 60  0000 C C
F 1 "AT25128A" H 4200 2800 60  0000 C C
	1    4250 2500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
