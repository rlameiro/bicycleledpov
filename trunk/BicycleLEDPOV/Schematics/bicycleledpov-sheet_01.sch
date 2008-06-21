EESchema Schematic File Version 1
LIBS:power,/media/disk/BicycleLEDPOV/trunk/BicycleLEDPOV/Schematics/Library/usb,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,./AT90USB162.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 1
Title "noname.sch"
Date "21 jun 2008"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3430 3995 3430 3955
Wire Wire Line
	3430 3955 3255 3955
Wire Wire Line
	3250 4255 3250 4260
Wire Wire Line
	3250 4260 3560 4260
Wire Wire Line
	4060 4255 4060 4250
Wire Wire Line
	4060 4250 4400 4250
Wire Wire Line
	6950 3650 7800 3650
Wire Wire Line
	6950 3750 7800 3750
Wire Wire Line
	6950 3850 7800 3850
Wire Wire Line
	6950 3950 7800 3950
Wire Wire Line
	6950 3550 7800 3550
Wire Wire Line
	4060 4155 4060 4150
Wire Wire Line
	4060 4150 4400 4150
Wire Wire Line
	3560 4155 3250 4155
$Comp
L GND #PWR?
U 1 1 485CD065
P 3430 3995
F 0 "#PWR?" H 3430 3995 30  0001 C C
F 1 "GND" H 3430 3925 30  0001 C C
	1    3430 3995
	1    0    0    -1  
$EndComp
$Comp
L USB-MB-H X?
U 1 1 485CD00E
P 3150 3955
F 0 "X?" H 3150 3755 50  0001 L B
F 1 "USB-MB-H" V 3380 3885 50  0000 L B
F 2 "con-usb-3-USB-MB-H" H 3300 4405 50  0001 C C
	1    3150 3955
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 485CCFFD
P 3810 4155
F 0 "R?" V 3735 4165 50  0000 C C
F 1 "22R" V 3810 4155 50  0000 C C
	1    3810 4155
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 485CCF44
P 3810 4255
F 0 "R?" V 3890 4255 50  0000 C C
F 1 "22R" V 3810 4255 50  0000 C C
	1    3810 4255
	0    1    1    0   
$EndComp
Text Notes 7300 3550 0    60   ~
SPI_SS0
Text Notes 7300 3950 0    60   ~
SPI_SS1
Text Notes 7300 3850 0    60   ~
SPI_MISO
Text Notes 7300 3750 0    60   ~
SPI_MOSI
Text Notes 7300 3650 0    60   ~
SPI_SCLK
$Comp
L AT90USB162 U?
U 1 1 485CC196
P 5350 3150
F 0 "U?" H 5550 1200 60  0000 C C
F 1 "AT90USB162" H 5400 3800 60  0000 C C
	1    5350 3150
	1    0    0    -1  
$EndComp
$EndSCHEMATC
