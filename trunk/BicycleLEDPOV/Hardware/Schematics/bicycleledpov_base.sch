EESchema Schematic File Version 1
LIBS:power,../KiCAD_library/at90usb162,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,../KiCAD_library/usb-mb-h,../KiCAD_library/a3213elhlt,./bicycleledpov_base.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 2
Title "Bicycle LED POV"
Date "27 jun 2008"
Rev "0.1.0"
Comp "http://code.google.com/p/bicycleledpov"
Comment1 "(c) Jorge Pinto"
Comment2 "(c) Donald Ziems"
Comment3 ""
Comment4 ""
$EndDescr
Wire Notes Line
	2650 7450 2650 5600
Wire Notes Line
	2650 7450 4400 7450
Wire Notes Line
	4400 7450 4400 5600
Wire Notes Line
	4400 5600 2650 5600
Wire Wire Line
	8600 4500 8050 4500
Wire Wire Line
	8500 4900 8500 4800
Wire Wire Line
	8500 4800 8600 4800
Wire Wire Line
	9850 4700 10400 4700
Wire Wire Line
	9850 4800 10400 4800
Wire Wire Line
	9850 4500 10550 4500
Wire Wire Line
	1400 7050 1400 7150
Wire Wire Line
	1000 7250 1000 7350
Wire Wire Line
	2100 6550 2300 6550
Wire Wire Line
	1050 3050 1050 3150
Wire Wire Line
	1050 2350 1050 2550
Wire Wire Line
	1550 3650 1900 3650
Wire Wire Line
	2400 3850 2500 3850
Wire Wire Line
	1550 3750 1900 3750
Wire Wire Line
	7050 6250 6525 6250
Wire Wire Line
	9100 6250 8700 6250
Wire Wire Line
	6770 2995 6770 3000
Wire Wire Line
	6770 3000 6300 3000
Wire Wire Line
	6300 2700 6830 2700
Wire Wire Line
	6300 2400 6480 2400
Connection ~ 9200 2555
Wire Wire Line
	9200 2555 8410 2555
Wire Wire Line
	9065 3010 9065 2285
Wire Wire Line
	7010 1700 6300 1700
Wire Wire Line
	9200 2285 9200 3010
Wire Wire Line
	8410 2555 8410 2345
Wire Notes Line
	2620 5625 2620 7525
Wire Notes Line
	2620 5625 770  5625
Connection ~ 3550 2350
Wire Wire Line
	3750 3200 3500 3200
Wire Wire Line
	3250 3050 3250 2950
Wire Wire Line
	2900 2550 2900 2350
Wire Wire Line
	2900 2350 3750 2350
Connection ~ 3550 2650
Wire Wire Line
	3750 3100 3550 3100
Wire Wire Line
	3550 3100 3550 2150
Wire Wire Line
	2600 2450 2600 2250
Wire Wire Line
	2600 2250 3750 2250
Wire Wire Line
	2550 1600 2550 1700
Wire Wire Line
	2550 1200 2550 1050
Wire Wire Line
	2550 1050 2700 1050
Wire Wire Line
	3450 1600 3450 1700
Wire Notes Line
	770  5675 770  7525
Wire Notes Line
	770  7525 2620 7525
Wire Notes Line
	770  5625 770  6425
Wire Wire Line
	6550 3600 6300 3600
Wire Wire Line
	3750 1750 3650 1750
Wire Wire Line
	3650 1750 3650 1050
Wire Wire Line
	3650 1050 3300 1050
Wire Wire Line
	3450 1200 3450 1050
Connection ~ 3450 1050
Wire Wire Line
	3750 1850 2700 1850
Wire Wire Line
	2700 1850 2700 1100
Wire Wire Line
	2700 1100 2550 1100
Connection ~ 2550 1100
Wire Wire Line
	3550 2650 3750 2650
Connection ~ 3550 2350
Wire Wire Line
	3750 2800 3450 2800
Wire Wire Line
	3450 2800 3450 2500
Wire Wire Line
	3450 2500 3250 2500
Wire Wire Line
	3250 2500 3250 2550
Wire Wire Line
	2900 3050 2900 2950
Wire Wire Line
	3750 3300 3500 3300
Wire Wire Line
	9315 2285 9315 2800
Wire Wire Line
	6950 1800 6300 1800
Wire Wire Line
	8910 2345 9065 2345
Connection ~ 9065 2345
Wire Wire Line
	6750 2600 6300 2600
Wire Wire Line
	6830 2800 6300 2800
Wire Wire Line
	6830 2900 6300 2900
Wire Wire Line
	6765 3100 6300 3100
Wire Wire Line
	8700 6350 9150 6350
Wire Wire Line
	7050 6350 6525 6350
Wire Wire Line
	1900 3850 1550 3850
Wire Wire Line
	2400 3750 2500 3750
Wire Wire Line
	1550 3550 1600 3550
Wire Wire Line
	1600 3550 1600 3400
Wire Wire Line
	1600 3400 1700 3400
Wire Wire Line
	1700 3400 1700 3450
Wire Wire Line
	1050 2450 1300 2450
Connection ~ 1050 2450
Wire Wire Line
	1050 1850 1050 1550
Wire Wire Line
	1000 6550 1600 6550
Wire Wire Line
	1000 5950 1000 5850
Wire Wire Line
	1400 6650 1400 6550
Connection ~ 1400 6550
Wire Wire Line
	1000 6650 1000 6450
Connection ~ 1000 6550
Wire Wire Line
	6300 1900 6950 1900
Wire Wire Line
	8050 4600 8600 4600
Wire Wire Line
	8600 4700 8400 4700
Wire Wire Line
	8400 4700 8400 4900
Wire Wire Line
	9850 4600 10550 4600
$Comp
L SW_PUSH SW?
U 1 1 4865832A
P 3650 4150
F 0 "SW?" H 3800 4260 50  0000 C C
F 1 "SW_PUSH" H 3650 4070 50  0000 C C
	1    3650 4150
	0    1    1    0   
$EndComp
Kmarq B 8600 4800 "Error: Pin power_out connected to Pin power_out (net 22)" F=2
Kmarq B 1550 3550 "Warning: Pin BiDi connected to Pin power_out (net 22)" F=1
Kmarq B 3750 1850 "Warning: Pin unspc connected to Pin passive (net 14)" F=1
Kmarq B 3750 1750 "Warning: Pin unspc connected to Pin passive (net 12)" F=1
Kmarq B 8600 4600 "Warning: Pin output connected to Pin 3state (net 4)" F=1
Kmarq B 8400 4900 "Warning Pin power_in not driven (Net 3)" F=1
Kmarq B 9850 4500 "Warning Pin power_in not driven (Net 2)" F=1
Kmarq B 9850 4500 "Warning: Pin power_in connected to Pin 3state (net 2)" F=1
Text Label 9850 4600 0    60   ~
EEPROM_VCC
Text Label 8050 4500 0    60   ~
SPI_SS2
$Comp
L VCC #PWR01
U 1 1 4865775C
P 8400 4900
F 0 "#PWR01" H 8400 5000 30  0001 C C
F 1 "VCC" H 8400 5000 30  0000 C C
	1    8400 4900
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 48657747
P 8500 4900
F 0 "#PWR02" H 8500 4900 30  0001 C C
F 1 "GND" H 8500 4830 30  0001 C C
	1    8500 4900
	1    0    0    -1  
$EndComp
Text Label 8050 4600 0    60   ~
SPI_MISO
Text Label 9850 4800 0    60   ~
SPI_MOSI
Text Label 9850 4700 0    60   ~
SPI_SCKL
Text Label 9850 4500 0    60   ~
EEPROM_VCC
Text Label 6300 1900 0    60   ~
EEPROM_VCC
$Comp
L GND #PWR03
U 1 1 486512C8
P 1400 7150
F 0 "#PWR03" H 1400 7150 30  0001 C C
F 1 "GND" H 1400 7080 30  0001 C C
	1    1400 7150
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 48651272
P 1400 6850
F 0 "C2" H 1450 6950 50  0000 L C
F 1 "100nF" H 1112 6742 50  0000 L C
	1    1400 6850
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 48651230
P 1000 6200
F 0 "R1" V 1080 6200 50  0000 C C
F 1 "10K" V 1000 6200 50  0000 C C
	1    1000 6200
	1    0    0    -1  
$EndComp
Text Label 2100 6550 0    60   ~
PD7
$Comp
L R R4
U 1 1 486511DD
P 1850 6550
F 0 "R4" V 1930 6550 50  0000 C C
F 1 "330R" V 1850 6550 50  0000 C C
	1    1850 6550
	0    -1   -1   0   
$EndComp
$Comp
L VCC #PWR04
U 1 1 486511AE
P 1000 5850
F 0 "#PWR04" H 1000 5950 30  0001 C C
F 1 "VCC" H 1000 5950 30  0000 C C
	1    1000 5850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 48650F13
P 1050 3150
F 0 "#PWR05" H 1050 3150 30  0001 C C
F 1 "GND" H 1050 3080 30  0001 C C
	1    1050 3150
	1    0    0    -1  
$EndComp
Text Label 1050 1850 1    60   ~
VBUS
Text Label 6300 3600 0    60   ~
PC4
Text Label 1100 2450 0    60   ~
PC4
$Comp
L R R6
U 1 1 485D5056
P 1050 2100
F 0 "R6" V 1130 2100 50  0000 C C
F 1 "47K" V 1050 2100 50  0000 C C
	1    1050 2100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 48650E1A
P 1700 3450
F 0 "#PWR06" H 1700 3450 30  0001 C C
F 1 "GND" H 1700 3380 30  0001 C C
	1    1700 3450
	1    0    0    -1  
$EndComp
Text Label 1650 3650 0    60   ~
VBUS
Text Label 2400 3850 0    60   ~
D+
Text Label 2400 3750 0    60   ~
D-
$Comp
L USB-MB-H X2
U 1 1 48650DBD
P 1450 3550
F 0 "X2" H 1450 3350 50  0001 L B
F 1 "USB-MB-H" H 1450 3550 50  0000 L B
F 2 "con-usb-3-USB-MB-H" H 1600 4000 50  0001 C C
	1    1450 3550
	-1   0    0    1   
$EndComp
Text Label 3500 3300 0    60   ~
D+
Text Label 3500 3200 0    60   ~
D-
Text Label 6525 6350 0    60   ~
SPI_SCKL
Text Label 6525 6250 0    60   ~
SPI_MOSI
Text Label 8700 6350 0    60   ~
SPI_SS0
Text Label 8700 6250 0    60   ~
SPI_SS1
Text Label 6300 3100 0    60   ~
SPI_SS2
Text Label 6300 3000 0    60   ~
SPI_SS1
Text Label 6300 2900 0    60   ~
SPI_MISO
Text Label 6300 2800 0    60   ~
SPI_MOSI
Text Label 6300 2700 0    60   ~
SPI_SCKL
Text Label 6300 2600 0    60   ~
SPI_SS0
Text Label 6300 2400 0    60   ~
PD7
Text Label 9065 3010 1    60   ~
SENSOR_VCC
Text Label 6300 1800 0    60   ~
SENSOR_VCC
Text Label 6300 1700 0    60   ~
SENSOR_DATA
Text Label 9200 3010 1    60   ~
SENSOR_DATA
$Comp
L R R71
U 1 1 4864FDF1
P 8660 2345
F 0 "R71" V 8740 2345 50  0000 C C
F 1 "R" V 8660 2345 50  0000 C C
	1    8660 2345
	0    1    1    0   
$EndComp
$Comp
L A3213ELHLT U9
U 1 1 4864FC23
P 9200 1850
F 0 "U9" H 9205 2225 60  0000 C C
F 1 "A3213ELHLT" H 9210 2130 60  0000 C C
	1    9200 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 4864FB94
P 9315 2800
F 0 "#PWR07" H 9315 2800 30  0001 C C
F 1 "GND" H 9315 2730 30  0001 C C
	1    9315 2800
	1    0    0    -1  
$EndComp
Text Notes 9000 4250 0    60   ~
EEPROM
Text Notes 8600 1400 0    60   ~
Hall Effect Sensor
$Comp
L AT25128A U10
U 1 1 4864FB37
P 9200 4650
F 0 "U10" H 9450 4350 60  0000 C C
F 1 "AT25128A" H 9150 4950 60  0000 C C
	1    9200 4650
	1    0    0    -1  
$EndComp
NoConn ~ 3750 3400
NoConn ~ 3750 3750
$Comp
L GND #PWR08
U 1 1 4862F407
P 3250 3050
F 0 "#PWR08" H 3250 3050 30  0001 C C
F 1 "GND" H 3250 2980 30  0001 C C
	1    3250 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 4862F403
P 2900 3050
F 0 "#PWR09" H 2900 3050 30  0001 C C
F 1 "GND" H 2900 2980 30  0001 C C
	1    2900 3050
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 485D5327
P 3250 2750
F 0 "C3" H 3300 2850 50  0000 L C
F 1 "1uF" H 3300 2650 50  0000 L C
	1    3250 2750
	-1   0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 485D42BD
P 2900 2750
F 0 "C1" H 2950 2850 50  0000 L C
F 1 "100nF" H 2950 2650 50  0000 L C
	1    2900 2750
	-1   0    0    -1  
$EndComp
$Comp
L AT90USB162 U11
U 1 1 485CC196
P 4700 2200
F 0 "U11" H 4900 250 60  0000 C C
F 1 "AT90USB162" H 4750 2850 60  0000 C C
	1    4700 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 4862F2EC
P 2600 2450
F 0 "#PWR010" H 2600 2450 30  0001 C C
F 1 "GND" H 2600 2380 30  0001 C C
	1    2600 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 4862F09A
P 2550 1700
F 0 "#PWR011" H 2550 1700 30  0001 C C
F 1 "GND" H 2550 1630 30  0001 C C
	1    2550 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 4862F018
P 3450 1700
F 0 "#PWR012" H 3450 1700 30  0001 C C
F 1 "GND" H 3450 1630 30  0001 C C
	1    3450 1700
	1    0    0    -1  
$EndComp
NoConn ~ 6300 2000
NoConn ~ 6300 2100
NoConn ~ 6300 2200
NoConn ~ 6300 2300
NoConn ~ 6300 3200
NoConn ~ 6300 3300
NoConn ~ 6300 3500
NoConn ~ 6300 3700
NoConn ~ 6300 3800
NoConn ~ 6300 3900
$Sheet
S 7050 6200 1650 200 
F0 "Registers and LEDs" 60
F1 "Registers_and_LEDs/bicycleledpov-sheet_02.sch" 60
F2 "SPI_SS1" I R 8700 6250 60 
F3 "SPI_SS0" I R 8700 6350 60 
F4 "SPI_MOSI" I L 7050 6250 60 
F5 "SPI_SCKL" I L 7050 6350 60 
$EndSheet
Text Notes 1305 6020 0    118  ~
button
Text Notes 1305 5820 0    118  ~
Bootloader
$Comp
L GND #PWR013
U 1 1 485EAA84
P 1000 7350
F 0 "#PWR013" H 1000 7350 30  0001 C C
F 1 "GND" H 1000 7280 30  0001 C C
	1    1000 7350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 485EA9C8
P 1000 6950
F 0 "SW1" H 1150 7060 50  0000 C C
F 1 "SW_PUSH" H 1000 6870 50  0000 C C
	1    1000 6950
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 485E9C78
P 2550 1400
F 0 "C5" H 2600 1500 50  0000 L C
F 1 "20pF" H 2600 1300 50  0000 L C
	1    2550 1400
	-1   0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 485E9B91
P 3450 1400
F 0 "C4" H 3500 1500 50  0000 L C
F 1 "20pF" H 3500 1300 50  0000 L C
	1    3450 1400
	-1   0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 485E9B2A
P 3000 1050
F 0 "X1" H 2990 1235 60  0000 C C
F 1 "8MHz" H 3000 900 60  0000 C C
	1    3000 1050
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 485E7E7C
P 2150 3750
F 0 "R3" V 2075 3760 50  0000 C C
F 1 "22R" V 2150 3750 50  0000 C C
	1    2150 3750
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 485E7E7B
P 2150 3850
F 0 "R2" V 2230 3850 50  0000 C C
F 1 "22R" V 2150 3850 50  0000 C C
	1    2150 3850
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 485D4F44
P 1050 2800
F 0 "R5" V 1130 2800 50  0000 C C
F 1 "47K" V 1050 2800 50  0000 C C
	1    1050 2800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR014
U 1 1 485D4262
P 3550 2150
F 0 "#PWR014" H 3550 2250 30  0001 C C
F 1 "VCC" H 3550 2250 30  0000 C C
	1    3550 2150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
