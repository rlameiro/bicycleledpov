EESchema Schematic File Version 1
LIBS:power,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,./bicycleledpov-sheet_01.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 1
Title "Bicycle LED POV"
Date "21 jun 2008"
Rev "0.1.0"
Comp "http://code.google.com/p/bicycleledpov"
Comment1 "(c) Jorge Pinto"
Comment2 "(c) Donald Ziems"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 1305 6020 0    118  ~
button
Text Notes 1305 5820 0    118  ~
Bootloader
Wire Notes Line
	770  6425 770  5625
Wire Notes Line
	2620 7525 770  7525
Wire Notes Line
	2620 7525 2620 5625
Wire Wire Line
	5784 2970 4684 2970
Wire Wire Line
	1610 6563 1004 6563
Wire Wire Line
	998  7268 998  7370
Wire Wire Line
	1394 6569 1394 6565
Wire Wire Line
	1394 6565 1390 6565
Wire Wire Line
	1390 6565 1390 6569
Wire Wire Line
	1390 6569 1390 6769
Wire Wire Line
	1000 6563 1000 6467
Connection ~ 997  6563
Wire Wire Line
	5495 1736 5739 1736
Wire Wire Line
	5739 1736 5739 2470
Wire Wire Line
	5739 2470 5781 2470
Wire Wire Line
	5780 2570 4812 2570
Wire Wire Line
	4812 2570 4812 1834
Wire Wire Line
	4812 1834 4636 1834
Connection ~ 4635 1835
Wire Wire Line
	4635 1940 4635 1835
Wire Wire Line
	4635 1835 4635 1735
Connection ~ 5495 1735
Wire Wire Line
	5495 1880 5495 1735
Wire Wire Line
	8575 4320 8330 4320
Wire Wire Line
	1075 1840 1075 1730
Wire Wire Line
	5780 3520 5490 3520
Wire Wire Line
	5490 3520 5490 3200
Wire Wire Line
	5490 3200 5270 3200
Wire Wire Line
	5270 3200 5270 3285
Wire Wire Line
	1075 3030 1075 3155
Wire Wire Line
	4935 3120 4935 3070
Wire Wire Line
	4935 3070 5635 3070
Wire Wire Line
	5635 3070 5780 3070
Wire Wire Line
	4935 3520 4935 3625
Connection ~ 5635 3070
Wire Wire Line
	5780 3370 5635 3370
Wire Wire Line
	5780 4020 5555 4020
Wire Wire Line
	8330 3420 8570 3420
Wire Wire Line
	8330 3520 8570 3520
Wire Wire Line
	8330 3620 8570 3620
Wire Wire Line
	8330 3720 8570 3720
Wire Wire Line
	8330 3320 8570 3320
Wire Wire Line
	5780 3920 5555 3920
Wire Wire Line
	5780 3820 5635 3820
Wire Wire Line
	5635 3820 5635 3370
Wire Wire Line
	5635 3370 5635 3070
Wire Wire Line
	5635 3070 5635 2870
Connection ~ 5635 3370
Wire Wire Line
	1075 2340 1075 2435
Wire Wire Line
	1075 2435 1075 2530
Wire Wire Line
	5270 3685 5270 3790
Wire Wire Line
	1301 3854 1301 3859
Wire Wire Line
	1301 3859 1860 3860
Wire Wire Line
	2525 3855 2360 3855
Wire Wire Line
	2530 3755 2360 3755
Wire Wire Line
	1860 3755 1301 3754
Wire Wire Line
	1300 3655 1540 3655
Wire Wire Line
	1580 3495 1580 3425
Wire Wire Line
	1580 3425 1425 3425
Wire Wire Line
	1425 3425 1425 3555
Wire Wire Line
	1425 3555 1305 3555
Connection ~ 1075 2435
Wire Wire Line
	1305 2435 1075 2435
Wire Wire Line
	5495 1735 5350 1735
Wire Wire Line
	5495 2280 5495 2385
Wire Wire Line
	4635 1735 4750 1735
Wire Wire Line
	4635 2340 4635 2445
Wire Wire Line
	5496 1738 5496 1736
Wire Wire Line
	997  5827 997  5969
Wire Wire Line
	998  6563 998  6673
Wire Wire Line
	1387 7170 1387 7349
Wire Wire Line
	1387 7349 1390 7349
Wire Wire Line
	1390 6563 1390 6569
Connection ~ 1390 6569
Wire Wire Line
	2294 6565 2110 6565
Wire Wire Line
	8330 3120 8570 3120
Wire Wire Line
	4684 2970 4684 3108
Wire Wire Line
	4684 3108 4683 3108
Wire Wire Line
	4683 3108 4683 3109
Wire Wire Line
	8330 3820 8570 3820
Wire Notes Line
	2620 5625 770  5625
Wire Notes Line
	770  7525 770  5675
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
Text GLabel 5555 4020 0    60   Input
D+
Text GLabel 5555 3920 0    60   Input
D-
Text GLabel 8575 4320 2    60   Input
PC4
Text GLabel 8570 3120 2    60   Input
PD7
Text GLabel 8570 3820 2    60   Input
SPI_SS2
Text GLabel 8570 3720 2    60   Input
SPI_SS1
Text GLabel 8570 3620 2    60   Input
SPI_MISO
Text GLabel 8570 3520 2    60   Input
SPI_MOSI
Text GLabel 8570 3420 2    60   Input
SPI_SCKL
Text GLabel 8570 3320 2    60   Input
SPI_SS0
$Comp
L GND #PWR?
U 1 1 485EAC7D
P 4683 3109
F 0 "#PWR?" H 4683 3109 30  0001 C C
F 1 "GND" H 4683 3039 30  0001 C C
	1    4683 3109
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 485EAAC2
P 1858 6565
F 0 "R?" V 1783 6575 50  0000 C C
F 1 "330R" V 1858 6565 50  0000 C C
	1    1858 6565
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 485EAA84
P 998 7371
F 0 "#PWR?" H 998 7371 30  0001 C C
F 1 "GND" H 998 7301 30  0001 C C
	1    998  7371
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 485EAA77
P 1386 7350
F 0 "#PWR?" H 1386 7350 30  0001 C C
F 1 "GND" H 1386 7280 30  0001 C C
	1    1386 7350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 485EA9C8
P 998 6969
F 0 "SW?" H 1148 7079 50  0000 C C
F 1 "SW_PUSH" H 998 6889 50  0000 C C
	1    998  6969
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 485EA8FE
P 1386 6969
F 0 "C?" H 1436 7069 50  0000 L C
F 1 "100nF" H 1098 6861 50  0000 L C
	1    1386 6969
	-1   0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 485EA53E
P 997 5827
F 0 "#PWR?" H 997 5927 30  0001 C C
F 1 "VCC" H 997 5927 30  0000 C C
	1    997  5827
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 485EA532
P 997 6218
F 0 "R?" V 1077 6218 50  0000 C C
F 1 "10K" V 997 6218 50  0000 C C
	1    997  6218
	1    0    0    -1  
$EndComp
$Comp
L AT90USB162 U?
U 1 1 485CC196
P 6730 2920
F 0 "U?" H 6930 970 60  0000 C C
F 1 "AT90USB162" H 6780 3570 60  0000 C C
	1    6730 2920
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 485E9C79
P 4635 2445
F 0 "#PWR?" H 4635 2445 30  0001 C C
F 1 "GND" H 4635 2375 30  0001 C C
	1    4635 2445
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 485E9C78
P 4635 2140
F 0 "C?" H 4685 2240 50  0000 L C
F 1 "20pF" H 4685 2040 50  0000 L C
	1    4635 2140
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 485E9B92
P 5495 2385
F 0 "#PWR?" H 5495 2385 30  0001 C C
F 1 "GND" H 5495 2315 30  0001 C C
	1    5495 2385
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 485E9B91
P 5495 2080
F 0 "C?" H 5545 2180 50  0000 L C
F 1 "20pF" H 5545 1980 50  0000 L C
	1    5495 2080
	-1   0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 485E9B2A
P 5050 1735
F 0 "X?" H 5040 1920 60  0000 C C
F 1 "8MHz" H 5050 1585 60  0000 C C
	1    5050 1735
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 485E7E9B
P 1580 3495
F 0 "#PWR?" H 1580 3495 30  0001 C C
F 1 "GND" H 1580 3425 30  0001 C C
	1    1580 3495
	1    0    0    -1  
$EndComp
$Comp
L USB-MB-H X?
U 1 1 485E7E7D
P 1201 3554
F 0 "X?" H 1201 3354 50  0001 L B
F 1 "USB-MB-H" V 1431 3484 50  0000 L B
F 2 "con-usb-3-USB-MB-H" H 1351 4004 50  0001 C C
	1    1201 3554
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 485E7E7C
P 2110 3755
F 0 "R?" V 2035 3765 50  0000 C C
F 1 "22R" V 2110 3755 50  0000 C C
	1    2110 3755
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 485E7E7B
P 2110 3855
F 0 "R?" V 2190 3855 50  0000 C C
F 1 "22R" V 2110 3855 50  0000 C C
	1    2110 3855
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 485D5328
P 5270 3790
F 0 "#PWR?" H 5270 3790 30  0001 C C
F 1 "GND" H 5270 3720 30  0001 C C
	1    5270 3790
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 485D5327
P 5270 3485
F 0 "C?" H 5320 3585 50  0000 L C
F 1 "1uF" H 5320 3385 50  0000 L C
	1    5270 3485
	-1   0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 485D5056
P 1075 2090
F 0 "R?" V 1155 2090 50  0000 C C
F 1 "47K" V 1075 2090 50  0000 C C
	1    1075 2090
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 485D4F92
P 1070 3155
F 0 "#PWR?" H 1070 3155 30  0001 C C
F 1 "GND" H 1070 3085 30  0001 C C
	1    1070 3155
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 485D4F44
P 1075 2780
F 0 "R?" V 1155 2780 50  0000 C C
F 1 "47K" V 1075 2780 50  0000 C C
	1    1075 2780
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 485D49D0
P 4935 3625
F 0 "#PWR?" H 4935 3625 30  0001 C C
F 1 "GND" H 4935 3555 30  0001 C C
	1    4935 3625
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 485D42BD
P 4935 3320
F 0 "C?" H 4985 3420 50  0000 L C
F 1 "100nF" H 4985 3220 50  0000 L C
	1    4935 3320
	-1   0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 485D4262
P 5635 2870
F 0 "#PWR?" H 5635 2970 30  0001 C C
F 1 "VCC" H 5635 2970 30  0000 C C
	1    5635 2870
	1    0    0    -1  
$EndComp
$EndSCHEMATC
