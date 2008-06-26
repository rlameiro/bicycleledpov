EESchema Schematic File Version 1
LIBS:power,../KiCAD_library/at90usb162,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,../KiCAD_library/usb-mb-h,./bicycleledpov_base.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 3
Title "Bicycle LED POV"
Date "26 jun 2008"
Rev "0.1.0"
Comp "http://code.google.com/p/bicycleledpov"
Comment1 "(c) Jorge Pinto"
Comment2 "(c) Donald Ziems"
Comment3 ""
Comment4 ""
$EndDescr
Kmarq B 1860 3855 "Warning Pin passive Unconnected" F=1
Kmarq B 1301 3654 "Warning Pin BiDi Unconnected" F=1
Kmarq B 1301 3554 "Warning Pin BiDi Unconnected" F=1
Kmarq B 997  6468 "Warning Pin passive Unconnected" F=1
Kmarq B 997  5968 "Warning Pin passive Unconnected" F=1
Kmarq B 1386 7169 "Warning Pin passive Unconnected" F=1
Kmarq B 1386 6769 "Warning Pin passive Unconnected" F=1
Kmarq B 998  6669 "Warning Pin passive Unconnected" F=1
Kmarq B 998  7269 "Warning Pin passive Unconnected" F=1
Kmarq B 1608 6565 "Warning Pin passive Unconnected" F=1
Kmarq B 2108 6565 "Warning Pin passive Unconnected" F=1
Kmarq B 8350 2400 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 2400 "Warning GLabel SENSOR_DATA not connected to SheetLabel" F=1
Kmarq B 5800 2550 "Warning: Pin unspc connected to Pin passive (net 27)" F=1
Kmarq B 5800 2450 "Warning: Pin unspc connected to Pin passive (net 26)" F=1
Kmarq B 1305 2435 "Warning GLabel PC4 not connected to SheetLabel" F=1
Kmarq B 8600 4300 "Warning GLabel PC4 not connected to SheetLabel" F=1
Kmarq B 8600 3700 "Warning GLabel SPI_SS1 not connected to SheetLabel" F=1
Kmarq B 8350 3700 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 3500 "Warning GLabel SPI_MOSI not connected to SheetLabel" F=1
Kmarq B 8350 3500 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 3300 "Warning GLabel SPI_SS0 not connected to SheetLabel" F=1
Kmarq B 8350 3300 "Warning Pin BiDi Unconnected" F=1
Kmarq B 1075 3030 "Warning Pin passive Unconnected" F=1
Kmarq B 1301 3854 "Warning Pin BiDi Unconnected" F=1
Kmarq B 5550 4000 "Warning GLabel D+ not connected to SheetLabel" F=1
Kmarq B 2525 3855 "Warning GLabel D+ not connected to SheetLabel" F=1
Kmarq B 5550 3900 "Warning GLabel D- not connected to SheetLabel" F=1
Kmarq B 2530 3755 "Warning GLabel D- not connected to SheetLabel" F=1
Kmarq B 1075 1840 "Warning Pin passive Unconnected" F=1
Kmarq B 1075 1730 "Warning GLabel VBUS not connected to SheetLabel" F=1
Kmarq B 1540 3655 "Warning GLabel VBUS not connected to SheetLabel" F=1
Kmarq B 5800 3800 "Warning Pin power_in not driven (Net 11)" F=1
Kmarq B 2293 6565 "Warning GLabel PD7 not connected to SheetLabel" F=1
Kmarq B 8600 3100 "Warning GLabel PD7 not connected to SheetLabel" F=1
Kmarq B 8350 3100 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 3400 "Warning GLabel SPI_SCKL not connected to SheetLabel" F=1
Kmarq B 8350 3400 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 3600 "Warning GLabel SPI_MISO not connected to SheetLabel" F=1
Kmarq B 8350 3600 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 3800 "Warning GLabel SPI_SS2 not connected to SheetLabel" F=1
Kmarq B 8350 3800 "Warning Pin 3state Unconnected" F=1
Kmarq B 5800 2950 "Error: Pin power_out connected to Pin power_out (net 3)" F=2
Kmarq B 8350 2500 "Warning Pin 3state Unconnected" F=1
Kmarq B 8600 2500 "Warning GLabel SENSOR_VCC not connected to SheetLabel" F=1
Wire Wire Line
	8600 2500 8350 2500
Connection ~ 5600 3050
Wire Wire Line
	5800 3900 5550 3900
Wire Wire Line
	5300 3750 5300 3650
Wire Wire Line
	4950 3250 4950 3050
Wire Wire Line
	4950 3050 5800 3050
Connection ~ 5600 3350
Wire Wire Line
	5800 3800 5600 3800
Wire Wire Line
	5600 3800 5600 2850
Wire Wire Line
	4650 3150 4650 2950
Wire Wire Line
	4650 2950 5800 2950
Wire Wire Line
	4600 2300 4600 2400
Wire Wire Line
	4600 1900 4600 1750
Wire Wire Line
	4600 1750 4750 1750
Wire Wire Line
	5500 2300 5500 2400
Wire Wire Line
	8600 3800 8350 3800
Wire Wire Line
	8600 3600 8350 3600
Wire Wire Line
	8600 3400 8350 3400
Wire Wire Line
	8600 3100 8350 3100
Wire Notes Line
	770  5675 770  7525
Wire Notes Line
	2620 5625 770  5625
Wire Wire Line
	2294 6565 2110 6565
Connection ~ 1390 6569
Wire Wire Line
	1390 6563 1390 6569
Wire Wire Line
	1390 7349 1387 7349
Wire Wire Line
	1387 7349 1387 7170
Wire Wire Line
	998  6563 998  6673
Wire Wire Line
	997  5827 997  5969
Wire Wire Line
	1305 2435 1075 2435
Connection ~ 1075 2435
Wire Wire Line
	1305 3555 1425 3555
Wire Wire Line
	1425 3555 1425 3425
Wire Wire Line
	1425 3425 1580 3425
Wire Wire Line
	1580 3425 1580 3495
Wire Wire Line
	1300 3655 1540 3655
Wire Wire Line
	1860 3755 1301 3754
Wire Wire Line
	2530 3755 2360 3755
Wire Wire Line
	2525 3855 2360 3855
Wire Wire Line
	1860 3860 1301 3859
Wire Wire Line
	1301 3859 1301 3854
Wire Wire Line
	1075 2340 1075 2530
Wire Wire Line
	1075 3030 1075 3155
Wire Wire Line
	1075 1840 1075 1730
Connection ~ 997  6563
Wire Wire Line
	1000 6563 1000 6467
Wire Wire Line
	1390 6769 1390 6565
Wire Wire Line
	1390 6565 1394 6565
Wire Wire Line
	1394 6565 1394 6569
Wire Wire Line
	998  7268 998  7370
Wire Wire Line
	1610 6563 1004 6563
Wire Notes Line
	2620 5625 2620 7525
Wire Notes Line
	2620 7525 770  7525
Wire Notes Line
	770  5625 770  6425
Wire Wire Line
	8600 3300 8350 3300
Wire Wire Line
	8350 3500 8600 3500
Wire Wire Line
	8350 3700 8600 3700
Wire Wire Line
	8600 4300 8350 4300
Wire Wire Line
	5800 2450 5700 2450
Wire Wire Line
	5700 2450 5700 1750
Wire Wire Line
	5700 1750 5350 1750
Wire Wire Line
	5500 1750 5500 1900
Connection ~ 5500 1750
Wire Wire Line
	5800 2550 4750 2550
Wire Wire Line
	4750 2550 4750 1800
Wire Wire Line
	4750 1800 4600 1800
Connection ~ 4600 1800
Wire Wire Line
	5600 3350 5800 3350
Connection ~ 5600 3050
Wire Wire Line
	5800 3500 5500 3500
Wire Wire Line
	5500 3500 5500 3200
Wire Wire Line
	5500 3200 5300 3200
Wire Wire Line
	5300 3200 5300 3250
Wire Wire Line
	4950 3750 4950 3650
Wire Wire Line
	5800 4000 5550 4000
Wire Wire Line
	8600 2400 8350 2400
Text GLabel 8600 2500 2    60   Output
SENSOR_VCC
Text GLabel 8600 2400 2    60   Input
SENSOR_DATA
NoConn ~ 5800 4100
NoConn ~ 5800 4450
$Comp
L GND #PWR01
U 1 1 4862F407
P 5300 3750
F 0 "#PWR01" H 5300 3750 30  0001 C C
F 1 "GND" H 5300 3680 30  0001 C C
	1    5300 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 4862F403
P 4950 3750
F 0 "#PWR02" H 4950 3750 30  0001 C C
F 1 "GND" H 4950 3680 30  0001 C C
	1    4950 3750
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 485D5327
P 5300 3450
F 0 "C3" H 5350 3550 50  0000 L C
F 1 "1uF" H 5350 3350 50  0000 L C
	1    5300 3450
	-1   0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 485D42BD
P 4950 3450
F 0 "C1" H 5000 3550 50  0000 L C
F 1 "100nF" H 5000 3350 50  0000 L C
	1    4950 3450
	-1   0    0    -1  
$EndComp
$Comp
L AT90USB162 U10
U 1 1 485CC196
P 6750 2900
F 0 "U10" H 6950 950 60  0000 C C
F 1 "AT90USB162" H 6800 3550 60  0000 C C
	1    6750 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 4862F2EC
P 4650 3150
F 0 "#PWR03" H 4650 3150 30  0001 C C
F 1 "GND" H 4650 3080 30  0001 C C
	1    4650 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 4862F09A
P 4600 2400
F 0 "#PWR04" H 4600 2400 30  0001 C C
F 1 "GND" H 4600 2330 30  0001 C C
	1    4600 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 4862F018
P 5500 2400
F 0 "#PWR05" H 5500 2400 30  0001 C C
F 1 "GND" H 5500 2330 30  0001 C C
	1    5500 2400
	1    0    0    -1  
$EndComp
Text GLabel 8600 4300 2    60   Output
PC4
Text GLabel 8600 3800 2    60   Output
SPI_SS2
Text GLabel 8600 3700 2    60   Output
SPI_SS1
Text GLabel 8600 3600 2    60   Input
SPI_MISO
Text GLabel 8600 3500 2    60   Output
SPI_MOSI
Text GLabel 8600 3400 2    60   Output
SPI_SCKL
Text GLabel 8600 3300 2    60   Output
SPI_SS0
NoConn ~ 8350 2600
NoConn ~ 8350 2700
NoConn ~ 8350 2800
NoConn ~ 8350 2900
NoConn ~ 8350 3000
NoConn ~ 8350 3900
NoConn ~ 8350 4000
NoConn ~ 8350 4200
NoConn ~ 8350 4400
NoConn ~ 8350 4500
NoConn ~ 8350 4600
Text GLabel 8600 3100 2    60   Input
PD7
$Sheet
S 7050 6600 1650 300 
F0 "EEPROM and Sensor" 60
F1 "EEPROM_and_Sensor/bicycleledpov-sheet_03.sch" 60
F2 "SPI_SS2" I R 8700 6650 60 
F3 "SPI_MISO" O L 7050 6750 60 
F4 "SPI_MOSI" I L 7050 6650 60 
F5 "SPI_SCKL" I L 7050 6850 60 
F6 "SENSOR_VCC" I R 8700 6750 60 
F7 "SENSOR_DATA" O R 8700 6850 60 
$EndSheet
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
Text GLabel 2525 3855 2    60   Input
D+
Text GLabel 2530 3755 2    60   Input
D-
Text GLabel 1540 3655 2    60   Input
VBUS
Text GLabel 1075 1730 3    60   Input
VBUS
Text GLabel 1305 2435 2    60   Input
PC4
Text GLabel 2293 6565 2    60   Input
PD7
Text GLabel 5550 4000 0    60   Input
D+
Text GLabel 5550 3900 0    60   Input
D-
$Comp
L R R4
U 1 1 485EAAC2
P 1858 6565
F 0 "R4" V 1783 6575 50  0000 C C
F 1 "330R" V 1858 6565 50  0000 C C
	1    1858 6565
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 485EAA84
P 998 7371
F 0 "#PWR06" H 998 7371 30  0001 C C
F 1 "GND" H 998 7301 30  0001 C C
	1    998  7371
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 485EAA77
P 1386 7350
F 0 "#PWR07" H 1386 7350 30  0001 C C
F 1 "GND" H 1386 7280 30  0001 C C
	1    1386 7350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 485EA9C8
P 998 6969
F 0 "SW1" H 1148 7079 50  0000 C C
F 1 "SW_PUSH" H 998 6889 50  0000 C C
	1    998  6969
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 485EA8FE
P 1386 6969
F 0 "C2" H 1436 7069 50  0000 L C
F 1 "100nF" H 1098 6861 50  0000 L C
	1    1386 6969
	-1   0    0    -1  
$EndComp
$Comp
L VCC #PWR08
U 1 1 485EA53E
P 997 5827
F 0 "#PWR08" H 997 5927 30  0001 C C
F 1 "VCC" H 997 5927 30  0000 C C
	1    997  5827
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 485EA532
P 997 6218
F 0 "R1" V 1077 6218 50  0000 C C
F 1 "10K" V 997 6218 50  0000 C C
	1    997  6218
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 485E9C78
P 4600 2100
F 0 "C5" H 4650 2200 50  0000 L C
F 1 "20pF" H 4650 2000 50  0000 L C
	1    4600 2100
	-1   0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 485E9B91
P 5500 2100
F 0 "C4" H 5550 2200 50  0000 L C
F 1 "20pF" H 5550 2000 50  0000 L C
	1    5500 2100
	-1   0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 485E9B2A
P 5050 1750
F 0 "X1" H 5040 1935 60  0000 C C
F 1 "8MHz" H 5050 1600 60  0000 C C
	1    5050 1750
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR09
U 1 1 485E7E9B
P 1580 3495
F 0 "#PWR09" H 1580 3495 30  0001 C C
F 1 "GND" H 1580 3425 30  0001 C C
	1    1580 3495
	1    0    0    -1  
$EndComp
$Comp
L USB-MB-H X2
U 1 1 485E7E7D
P 1201 3554
F 0 "X2" H 1201 3354 50  0001 L B
F 1 "USB-MB-H" V 1431 3484 50  0000 L B
F 2 "con-usb-3-USB-MB-H" H 1351 4004 50  0001 C C
	1    1201 3554
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 485E7E7C
P 2110 3755
F 0 "R3" V 2035 3765 50  0000 C C
F 1 "22R" V 2110 3755 50  0000 C C
	1    2110 3755
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 485E7E7B
P 2110 3855
F 0 "R2" V 2190 3855 50  0000 C C
F 1 "22R" V 2110 3855 50  0000 C C
	1    2110 3855
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 485D5056
P 1075 2090
F 0 "R6" V 1155 2090 50  0000 C C
F 1 "47K" V 1075 2090 50  0000 C C
	1    1075 2090
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 485D4F92
P 1070 3155
F 0 "#PWR010" H 1070 3155 30  0001 C C
F 1 "GND" H 1070 3085 30  0001 C C
	1    1070 3155
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 485D4F44
P 1075 2780
F 0 "R5" V 1155 2780 50  0000 C C
F 1 "47K" V 1075 2780 50  0000 C C
	1    1075 2780
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR011
U 1 1 485D4262
P 5600 2850
F 0 "#PWR011" H 5600 2950 30  0001 C C
F 1 "VCC" H 5600 2950 30  0000 C C
	1    5600 2850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
