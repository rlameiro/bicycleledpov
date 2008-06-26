EESchema Schematic File Version 1
LIBS:power,../KiCAD_library/at90usb162,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,../KiCAD_library/usb-mb-h,../KiCAD_library/a3213elhlt,./bicycleledpov_base.cache
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
Connection ~ 3725 3985
Wire Wire Line
	3725 3985 2925 3985
Wire Wire Line
	2925 3985 2925 3845
Wire Wire Line
	2925 3845 2985 3845
Wire Wire Line
	8880 3875 8630 3875
Wire Wire Line
	3590 4065 3590 3845
Wire Wire Line
	3590 3845 3590 3770
Wire Wire Line
	7180 4075 7180 3875
Wire Wire Line
	7180 3875 7380 3875
Wire Wire Line
	7380 3775 7130 3775
Wire Wire Line
	8880 3975 8630 3975
Connection ~ 8730 3675
Wire Wire Line
	8730 3575 8730 3675
Wire Wire Line
	8730 3675 8730 3775
Wire Wire Line
	8730 3775 8630 3775
Wire Wire Line
	8730 3675 8630 3675
Wire Wire Line
	7380 3675 7130 3675
Wire Wire Line
	7380 3975 7280 3975
Wire Wire Line
	7280 3975 7280 4075
Wire Wire Line
	3840 3890 3840 3770
Wire Wire Line
	3725 4055 3725 3985
Wire Wire Line
	3725 3985 3725 3770
Wire Wire Line
	3485 3845 3590 3845
Connection ~ 3590 3845
Kmarq B 8630 3875 "Warning Pin input Unconnected" F=1
Kmarq B 3725 3770 "Atenção Pino input não controlado (Net 48)" F=1
Kmarq B 3590 3770 "Atenção Pino input Não conectado" F=1
Kmarq B 8630 3875 "Atenção Pino input Não conectado" F=1
Kmarq B 8630 3975 "Atenção Pino input Não conectado" F=1
Kmarq B 7380 3775 "Atenção Pino output Não conectado" F=1
Kmarq B 7380 3675 "Atenção Pino input Não conectado" F=1
$Comp
L AT25128A U9
U 1 1 486304E1
P 7980 3825
F 0 "U9" H 8230 3525 60  0000 C C
F 1 "AT25128A" H 8010 4125 60  0000 C C
	1    7980 3825
	1    0    0    -1  
$EndComp
Text GLabel 3590 4065 1    60   Input
SENSOR_VCC
Text GLabel 3725 4055 1    60   Output
SENSOR_DATA
$Comp
L GND #PWR012
U 1 1 48640C4F
P 3840 3890
F 0 "#PWR012" H 3840 3890 30  0001 C C
F 1 "GND" H 3840 3820 30  0001 C C
	1    3840 3890
	1    0    0    -1  
$EndComp
$Comp
L A3213ELHLT U11
U 1 1 48640C31
P 3725 3335
F 0 "U11" H 3730 3710 60  0000 C C
F 1 "A3213ELHLT" H 3735 3615 60  0000 C C
	1    3725 3335
	1    0    0    -1  
$EndComp
Text Notes 3185 2870 0    60   ~
Sensor Hall sensor
$Comp
L R R15
U 1 1 48639B68
P 3235 3845
F 0 "R15" V 3315 3845 50  0000 C C
F 1 "51K" V 3235 3845 50  0000 C C
	1    3235 3845
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR014
U 1 1 4863060F
P 7180 4075
F 0 "#PWR014" H 7180 4175 30  0001 C C
F 1 "VCC" H 7180 4175 30  0000 C C
	1    7180 4075
	-1   0    0    1   
$EndComp
Text GLabel 7130 3675 0    60   Input
SPI_SS2
Text GLabel 7130 3775 0    60   Output
SPI_MISO
Text GLabel 8880 3975 2    60   Input
SPI_MOSI
Text GLabel 8880 3875 2    60   Input
SPI_SCKL
$Comp
L GND #PWR015
U 1 1 4863050B
P 7280 4075
F 0 "#PWR015" H 7280 4075 30  0001 C C
F 1 "GND" H 7280 4005 30  0001 C C
	1    7280 4075
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR016
U 1 1 48630504
P 8730 3575
F 0 "#PWR016" H 8730 3675 30  0001 C C
F 1 "VCC" H 8730 3675 30  0000 C C
	1    8730 3575
	1    0    0    -1  
$EndComp
$EndSCHEMATC
