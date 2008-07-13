EESchema Schematic File Version 1
LIBS:power,./KiCAD_library/at90usb162,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,./KiCAD_library/usb-mb-h,./KiCAD_library/a3213elhlt,./KiCAD_library/DC-DC,./bicycleledpov_base.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 2
Title "Bicycle LED POV"
Date "13 jul 2008"
Rev "1.0.0"
Comp "http://code.google.com/p/bicycleledpov"
Comment1 "(c) Jorge Pinto"
Comment2 "(c) Donald Ziems"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 4750 6550 0    80   ~
AAA batteries
$Comp
L +BATT #PWR01
U 1 1 48767F42
P 4600 6850
F 0 "#PWR01" H 4600 6800 20  0001 C C
F 1 "+BATT" H 4600 6950 30  0000 C C
	1    4600 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 48767F3A
P 6100 7050
F 0 "#PWR02" H 6100 7050 30  0001 C C
F 1 "GND" H 6100 6980 30  0001 C C
	1    6100 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 7050 6100 6950
Wire Wire Line
	6100 6950 6000 6950
Wire Wire Line
	5400 6950 5300 6950
Wire Wire Line
	1025 6245 1025 6145
Wire Wire Line
	1025 6145 1230 6145
Connection ~ 1180 6145
Wire Wire Line
	1180 6245 1180 6145
Wire Wire Line
	1800 6145 1630 6145
Wire Wire Line
	3550 2500 3550 2950
Wire Wire Line
	3170 2700 3170 2500
Connection ~ 3550 2500
Wire Wire Line
	3550 2950 3750 2950
Wire Wire Line
	3050 6710 3050 6445
Wire Wire Line
	8960 2940 9495 2940
Wire Wire Line
	1400 3900 1930 3900
Wire Wire Line
	6950 2050 6300 2050
Connection ~ 1700 6145
Wire Wire Line
	6500 3350 7050 3350
Wire Wire Line
	9085 2840 9495 2840
Wire Wire Line
	8965 2340 9495 2340
Wire Wire Line
	9495 2440 8965 2440
Wire Wire Line
	9495 2540 8965 2540
Wire Wire Line
	3750 2000 2570 2000
Wire Wire Line
	9240 3690 9495 3690
Wire Wire Line
	9240 3490 9495 3490
Wire Wire Line
	9495 3390 9240 3390
Wire Wire Line
	9495 3590 9240 3590
Wire Wire Line
	9240 3990 9495 3990
Wire Wire Line
	9495 4090 9240 4090
Wire Wire Line
	9495 3890 9240 3890
Wire Wire Line
	9495 2740 9240 2740
Wire Wire Line
	10775 1830 10245 1830
Wire Wire Line
	10395 2175 10395 2030
Wire Wire Line
	10395 2030 10245 2030
Wire Wire Line
	3600 1260 3600 1135
Wire Wire Line
	3600 1135 3300 1135
Wire Wire Line
	2570 2000 2570 1135
Wire Wire Line
	1180 6685 1700 6685
Wire Wire Line
	3450 6745 3450 6835
Connection ~ 1700 5865
Wire Wire Line
	1700 5865 2045 5865
Connection ~ 2565 3900
Wire Wire Line
	2565 3995 2565 3900
Wire Wire Line
	2680 3350 3750 3350
Wire Wire Line
	6300 2550 6685 2550
Connection ~ 7330 2550
Wire Wire Line
	7330 2695 7330 2550
Wire Wire Line
	7185 2550 7610 2550
Connection ~ 3450 6345
Wire Wire Line
	3200 6595 3200 6245
Wire Wire Line
	3200 6245 2900 6245
Wire Wire Line
	2705 3900 2430 3900
Wire Wire Line
	1180 6685 1180 6645
Wire Wire Line
	1700 6685 1700 6345
Wire Wire Line
	1700 6345 1800 6345
Wire Wire Line
	5385 5330 4835 5330
Wire Wire Line
	5285 5730 5285 5630
Wire Wire Line
	5285 5630 5385 5630
Wire Wire Line
	6635 5530 7185 5530
Wire Wire Line
	6635 5630 7185 5630
Wire Wire Line
	6635 5330 7335 5330
Wire Wire Line
	7330 3095 7330 3195
Wire Wire Line
	7610 3250 7610 3350
Wire Wire Line
	6815 4345 6815 4445
Wire Wire Line
	1830 3250 2180 3250
Wire Wire Line
	1830 3350 2180 3350
Wire Wire Line
	7650 6750 7125 6750
Wire Wire Line
	9700 6750 9300 6750
Wire Wire Line
	6770 3145 6770 3150
Wire Wire Line
	6770 3150 6300 3150
Wire Wire Line
	6300 2850 6830 2850
Connection ~ 9605 5660
Wire Wire Line
	9605 5660 8815 5660
Wire Wire Line
	9470 5390 9470 6115
Wire Wire Line
	7010 1850 6300 1850
Wire Wire Line
	9605 6115 9605 5390
Wire Wire Line
	8815 5660 8815 5450
Wire Wire Line
	3170 3200 3170 3100
Wire Wire Line
	2875 2600 2875 2400
Wire Wire Line
	2875 2400 3750 2400
Wire Wire Line
	2396 1685 2396 1785
Wire Wire Line
	2396 1285 2396 1135
Wire Wire Line
	2396 1135 2700 1135
Wire Wire Line
	9720 5390 9720 5905
Wire Wire Line
	6950 1950 6300 1950
Wire Wire Line
	9315 5450 9470 5450
Connection ~ 9470 5450
Wire Wire Line
	6750 2750 6300 2750
Wire Wire Line
	6830 2950 6300 2950
Wire Wire Line
	6830 3050 6300 3050
Wire Wire Line
	6765 3250 6300 3250
Wire Wire Line
	9300 6850 9750 6850
Wire Wire Line
	7650 6850 7125 6850
Wire Wire Line
	2180 3450 1830 3450
Wire Wire Line
	1830 3150 1880 3150
Wire Wire Line
	1880 3150 1880 3000
Wire Wire Line
	1880 3000 1980 3000
Wire Wire Line
	1980 3000 1980 3050
Wire Wire Line
	7610 2450 7610 2650
Connection ~ 7610 2550
Wire Wire Line
	4835 5430 5385 5430
Wire Wire Line
	6635 5430 7335 5430
Wire Wire Line
	3205 3900 3750 3900
Wire Wire Line
	2565 4595 2565 4795
Connection ~ 2565 4695
Wire Wire Line
	3050 6445 2900 6445
Wire Wire Line
	3400 6145 3450 6145
Wire Wire Line
	3450 6145 3450 6345
Wire Wire Line
	3000 6145 2900 6145
Wire Wire Line
	2900 6345 4130 6345
Wire Wire Line
	7440 3750 7850 3750
Wire Wire Line
	7850 3750 7850 3755
Wire Wire Line
	6815 3845 6815 3750
Connection ~ 6815 3750
Wire Wire Line
	6940 3750 6300 3750
Wire Wire Line
	2680 3450 3750 3450
Wire Wire Line
	7610 1555 7610 1950
Connection ~ 2570 1135
Wire Wire Line
	3750 1900 3415 1900
Wire Wire Line
	3415 1900 3415 1135
Connection ~ 3415 1135
Wire Wire Line
	3600 1660 3600 1785
Wire Wire Line
	3750 3550 3550 3550
Wire Wire Line
	3550 3550 3550 3685
Wire Wire Line
	8915 1930 9445 1930
Wire Wire Line
	10775 1930 10245 1930
Wire Wire Line
	9445 1830 8915 1830
Wire Wire Line
	9445 2030 8915 2030
Wire Wire Line
	6300 2450 6505 2450
Wire Wire Line
	6300 2250 6505 2250
Wire Wire Line
	6505 2150 6300 2150
Wire Wire Line
	6505 2350 6300 2350
Wire Wire Line
	6300 3350 6495 3350
Wire Wire Line
	6495 3450 6300 3450
Wire Wire Line
	6495 3650 6300 3650
Wire Wire Line
	6495 3850 6300 3850
Wire Wire Line
	6495 3950 6300 3950
Wire Wire Line
	6495 4050 6300 4050
Wire Wire Line
	9495 3040 9390 3040
Wire Wire Line
	9390 3040 9390 3130
Wire Wire Line
	4725 5530 5385 5530
Wire Wire Line
	1800 6245 1700 6245
Wire Wire Line
	8765 2640 9495 2640
Wire Wire Line
	9495 3790 9245 3790
Wire Wire Line
	1700 6245 1700 5735
Wire Wire Line
	3750 2800 3550 2800
Connection ~ 3550 2800
Wire Wire Line
	3170 2500 3750 2500
Connection ~ 3170 2500
Wire Wire Line
	2645 5865 2955 5865
Wire Wire Line
	2955 5865 2955 6145
Connection ~ 2955 6145
Wire Wire Line
	4700 6950 4600 6950
Wire Wire Line
	4600 6950 4600 6850
$Comp
L BATTERY BT2
U 1 1 48767F26
P 5700 6950
F 0 "BT2" H 5700 7150 50  0000 C C
F 1 "BATTERY" H 5700 6760 50  0001 C C
	1    5700 6950
	1    0    0    -1  
$EndComp
$Comp
L BATTERY BT1
U 1 1 48767F24
P 5000 6950
F 0 "BT1" H 5000 7150 50  0000 C C
F 1 "BATTERY" H 5000 6760 50  0001 C C
	1    5000 6950
	1    0    0    -1  
$EndComp
Kmarq B 2900 6345 "Erro: Pino power_out conectado ao Pino output (ligação 31)" F=2
Kmarq B 3050 6710 "Atenção Pino power_in não controlado (Net 29)" F=1
Kmarq B 5385 5430 "Atenção: Pino output conectado ao Pino 3state (ligação 26)" F=1
Kmarq B 6635 5330 "Atenção Pino power_in não controlado (Net 20)" F=1
Kmarq B 6635 5330 "Atenção: Pino power_in conectado ao Pino 3state (ligação 20)" F=1
Kmarq B 3750 2000 "Atenção: Pino unspc conectado ao Pino passive (ligação 11)" F=1
Kmarq B 3750 1900 "Atenção: Pino unspc conectado ao Pino passive (ligação 10)" F=1
Kmarq B 3750 3550 "Erro: Pino power_out conectado ao Pino power_out (ligação 3)" F=2
Kmarq B 2900 6245 "Erro: Pino output conectado ao Pino power_out (ligação 3)" F=2
Kmarq B 2900 6145 "Atenção Pino power_in não controlado (Net 1)" F=1
NoConn ~ 3750 3250
Text Label 8765 2640 0    60   ~
MEMORY_HOLD
Text Notes 5820 5050 0    60   ~
MEMORY
Text Label 6635 5330 0    60   ~
MEMORY_VCC
Text Label 6300 2050 0    60   ~
MEMORY_VCC
Text Label 6635 5430 0    60   ~
MEMORY_HOLD
Text Label 6300 3350 0    60   ~
MEMORY_HOLD
Text Label 4725 5530 0    60   ~
MEMORY_VCC
$Comp
L GND #PWR03
U 1 1 48711A02
P 9390 3130
F 0 "#PWR03" H 9390 3130 30  0001 C C
F 1 "GND" H 9390 3060 30  0001 C C
	1    9390 3130
	1    0    0    -1  
$EndComp
Text Label 8960 2940 0    60   ~
VCC_3.3V
Text Label 9085 2840 0    60   ~
+BATT
Text Label 8965 2540 0    60   ~
SPI_MISO
Text Label 8965 2440 0    60   ~
SPI_MOSI
Text Label 8965 2340 0    60   ~
SPI_SCKL
Text Label 6300 4050 0    60   ~
PC7
Text Label 6300 3950 0    60   ~
PC6
Text Label 6300 3850 0    60   ~
PC5
Text Label 6300 3650 0    60   ~
PC2
Text Label 6300 3450 0    60   ~
PB7
$Comp
L CONN_8 P2
U 1 1 48711307
P 9845 2690
F 0 "P2" V 9845 2670 60  0000 C C
F 1 "CONN_8" V 9895 2690 60  0001 C C
	1    9845 2690
	1    0    0    -1  
$EndComp
Text Label 6310 2550 0    60   ~
PD7
Text Label 6310 2450 0    60   ~
PD6
Text Label 6310 2350 0    60   ~
PD5
Text Label 6310 2150 0    60   ~
PD3
Text Label 6310 2250 0    60   ~
PD4
Text Label 9240 3690 0    60   ~
PD6
Text Label 9240 3590 0    60   ~
PD5
Text Label 9240 3390 0    60   ~
PD3
Text Label 9240 3490 0    60   ~
PD4
Text Label 9240 4090 0    60   ~
PC7
Text Label 9240 3990 0    60   ~
PC6
Text Label 9240 3890 0    60   ~
PC5
Text Label 9245 3790 0    60   ~
PC2
$Comp
L CONN_8 P3
U 1 1 4871137A
P 9845 3740
F 0 "P3" V 9845 3745 60  0000 C C
F 1 "CONN_8" V 9895 3740 60  0001 C C
	1    9845 3740
	1    0    0    -1  
$EndComp
Text Label 9240 2740 0    60   ~
PB7
Text Notes 9705 1635 0    60   ~
ICSP
$Comp
L GND #PWR04
U 1 1 48711264
P 10395 2175
F 0 "#PWR04" H 10395 2175 30  0001 C C
F 1 "GND" H 10395 2105 30  0001 C C
	1    10395 2175
	1    0    0    -1  
$EndComp
Text Label 10370 1830 0    60   ~
VCC_3.3V
Text Label 8915 2030 0    60   ~
RESET
Text Label 8915 1830 0    60   ~
SPI_MISO
Text Label 10245 1930 0    60   ~
SPI_MOSI
Text Label 8915 1930 0    60   ~
SPI_SCKL
Text Label 3330 3900 0    60   ~
RESET
$Comp
L CONN_3X2 P1
U 1 1 4871098E
P 9845 1980
F 0 "P1" V 9845 2045 50  0000 C C
F 1 "CONN_3X2" V 9845 2030 40  0001 C C
	1    9845 1980
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 486F9B70
P 3550 3685
F 0 "#PWR05" H 3550 3685 30  0001 C C
F 1 "GND" H 3550 3615 30  0001 C C
	1    3550 3685
	1    0    0    -1  
$EndComp
Text Notes 1455 3570 1    80   ~
USB connector
Text Notes 2150 5500 0    80   ~
DC-DC
Text Label 3170 2500 0    60   ~
VCC_3.3V
Text Label 7610 1950 1    60   ~
VCC_3.3V
Text Label 1400 3900 0    60   ~
VCC_3.3V
$Comp
L GND #PWR06
U 1 1 486D47F9
P 1025 6245
F 0 "#PWR06" H 1025 6245 30  0001 C C
F 1 "GND" H 1025 6175 30  0001 C C
	1    1025 6245
	1    0    0    -1  
$EndComp
$Comp
L R R70
U 1 1 486C773C
P 2180 3900
F 0 "R70" V 2180 3900 50  0000 C C
F 1 "R" V 2180 3900 50  0001 C C
	1    2180 3900
	0    1    1    0   
$EndComp
Text Notes 1440 4330 0    80   ~
Reset button
$Comp
L R R67
U 1 1 486D41DE
P 6935 2550
F 0 "R67" V 6935 2545 50  0000 C C
F 1 "R" V 6935 2550 50  0001 C C
	1    6935 2550
	0    1    1    0   
$EndComp
$Comp
L INDUCTOR L1
U 1 1 486CF54F
P 2345 5865
F 0 "L1" V 2445 5870 40  0000 C C
F 1 "L" V 2445 5865 40  0001 C C
	1    2345 5865
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR07
U 1 1 486CF4E4
P 3450 6835
F 0 "#PWR07" H 3450 6835 30  0001 C C
F 1 "GND" H 3450 6765 30  0001 C C
	1    3450 6835
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR08
U 1 1 486CF3FB
P 3050 6710
F 0 "#PWR08" H 3050 6660 20  0001 C C
F 1 "+BATT" H 3050 6810 30  0000 C C
	1    3050 6710
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR09
U 1 1 486CF3F6
P 3200 6595
F 0 "#PWR09" H 3200 6595 30  0001 C C
F 1 "GND" H 3200 6525 30  0001 C C
	1    3200 6595
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C7
U 1 1 486CF14F
P 3450 6545
F 0 "C7" H 3500 6645 50  0000 L C
F 1 "C" H 3500 6445 50  0001 L C
	1    3450 6545
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C6
U 1 1 486CF147
P 1430 6145
F 0 "C6" V 1565 6145 50  0000 L C
F 1 "C" H 1480 6045 50  0001 L C
	1    1430 6145
	0    1    -1   0   
$EndComp
$Comp
L DIODESCH D65
U 1 1 486CF077
P 3200 6145
F 0 "D65" H 3200 6245 40  0000 C C
F 1 "Schottky" H 3455 6210 40  0001 C C
	1    3200 6145
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR010
U 1 1 486CEEF7
P 1700 5735
F 0 "#PWR010" H 1700 5685 20  0001 C C
F 1 "+BATT" H 1700 5835 30  0000 C C
	1    1700 5735
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 486C7724
P 2565 4795
F 0 "#PWR011" H 2565 4795 30  0001 C C
F 1 "GND" H 2565 4725 30  0001 C C
	1    2565 4795
	1    0    0    -1  
$EndComp
$Comp
L R R68
U 1 1 486C7698
P 2955 3900
F 0 "R68" V 2955 3905 50  0000 C C
F 1 "R" V 2955 3900 50  0001 C C
	1    2955 3900
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 486C73C2
P 1180 6445
F 0 "C2" H 1230 6545 50  0000 L C
F 1 "C" H 1230 6345 50  0001 L C
	1    1180 6445
	1    0    0    1   
$EndComp
Text Label 3610 6345 0    60   ~
VCC_3.3V
NoConn ~ 1800 6445
$Comp
L MAX756 U11
U 1 1 486C71BA
P 2350 6295
F 0 "U11" H 2350 6610 60  0000 C C
F 1 "MAX756" H 2300 6595 60  0001 C C
	1    2350 6295
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 4865832A
P 2565 4295
F 0 "SW2" H 2565 4455 50  0000 C C
F 1 "SW_PUSH" H 2565 4215 50  0001 C C
	1    2565 4295
	0    1    1    0   
$EndComp
Text Label 4835 5330 0    60   ~
SPI_SS2
$Comp
L GND #PWR012
U 1 1 48657747
P 5285 5730
F 0 "#PWR012" H 5285 5730 30  0001 C C
F 1 "GND" H 5285 5660 30  0001 C C
	1    5285 5730
	1    0    0    -1  
$EndComp
Text Label 4835 5430 0    60   ~
SPI_MISO
Text Label 6635 5630 0    60   ~
SPI_MOSI
Text Label 6635 5530 0    60   ~
SPI_SCKL
$Comp
L GND #PWR013
U 1 1 486512C8
P 7330 3195
F 0 "#PWR013" H 7330 3195 30  0001 C C
F 1 "GND" H 7330 3125 30  0001 C C
	1    7330 3195
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 48651272
P 7330 2895
F 0 "C1" H 7380 2995 50  0000 L C
F 1 "C" H 7410 2785 50  0001 L C
	1    7330 2895
	-1   0    0    -1  
$EndComp
$Comp
L R R69
U 1 1 48651230
P 7610 2200
F 0 "R69" V 7610 2210 50  0000 C C
F 1 "R" V 7610 2200 50  0001 C C
	1    7610 2200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 48650F13
P 6815 4445
F 0 "#PWR014" H 6815 4445 30  0001 C C
F 1 "GND" H 6815 4375 30  0001 C C
	1    6815 4445
	1    0    0    -1  
$EndComp
Text Label 7575 3750 0    60   ~
VBUS
$Comp
L R R72
U 1 1 485D5056
P 7190 3750
F 0 "R72" V 7190 3750 50  0000 C C
F 1 "R" V 7190 3750 50  0001 C C
	1    7190 3750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR015
U 1 1 48650E1A
P 1980 3050
F 0 "#PWR015" H 1980 3050 30  0001 C C
F 1 "GND" H 1980 2980 30  0001 C C
	1    1980 3050
	1    0    0    -1  
$EndComp
Text Label 1930 3250 0    60   ~
VBUS
$Comp
L USB-MB-H P4
U 1 1 48650DBD
P 1730 3150
F 0 "P4" V 1840 3230 50  0000 L B
F 1 "USB-MB-H" V 1965 3080 50  0001 L B
F 2 "usb-mb-h" H 1880 3600 50  0001 C C
	1    1730 3150
	-1   0    0    1   
$EndComp
Text Label 7125 6850 0    60   ~
SPI_SCKL
Text Label 7125 6750 0    60   ~
SPI_MOSI
Text Label 9300 6850 0    60   ~
SPI_SS0
Text Label 9300 6750 0    60   ~
SPI_SS1
Text Label 6300 3250 0    60   ~
SPI_SS2
Text Label 6300 3150 0    60   ~
SPI_SS1
Text Label 6300 3050 0    60   ~
SPI_MISO
Text Label 6300 2950 0    60   ~
SPI_MOSI
Text Label 6300 2850 0    60   ~
SPI_SCKL
Text Label 6300 2750 0    60   ~
SPI_SS0
Text Label 9470 6115 1    60   ~
SENSOR_VCC
Text Label 6300 1950 0    60   ~
SENSOR_VCC
Text Label 6300 1850 0    60   ~
SENSOR_DATA
Text Label 9605 6115 1    60   ~
SENSOR_DATA
$Comp
L R R73
U 1 1 4864FDF1
P 9065 5450
F 0 "R73" V 9060 5445 50  0000 C C
F 1 "R" V 9065 5450 50  0001 C C
	1    9065 5450
	0    1    1    0   
$EndComp
$Comp
L A3213ELHLT U9
U 1 1 4864FC23
P 9605 4955
F 0 "U9" H 9590 5230 60  0000 C C
F 1 "A3213ELHLT-T" H 9615 5235 60  0001 C C
	1    9605 4955
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 4864FB94
P 9720 5905
F 0 "#PWR016" H 9720 5905 30  0001 C C
F 1 "GND" H 9720 5835 30  0001 C C
	1    9720 5905
	1    0    0    -1  
$EndComp
Text Notes 8740 4550 0    80   ~
Hall Effect Sensor
$Comp
L AT25128A U12
U 1 1 4864FB37
P 5985 5480
F 0 "U12" H 6015 5795 60  0000 C C
F 1 "AT26DF081A-SU" H 6010 5790 60  0001 C C
	1    5985 5480
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 4862F407
P 3170 3200
F 0 "#PWR017" H 3170 3200 30  0001 C C
F 1 "GND" H 3170 3130 30  0001 C C
	1    3170 3200
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 485D5327
P 3170 2900
F 0 "C3" H 3220 3000 50  0000 L C
F 1 "C" H 3220 2800 50  0001 L C
	1    3170 2900
	-1   0    0    -1  
$EndComp
$Comp
L AT90USB162 U10
U 1 1 485CC196
P 4700 2350
F 0 "U10" H 5010 3015 60  0000 C C
F 1 "AT90USB162-16AU" H 4750 3000 60  0001 C C
	1    4700 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 4862F2EC
P 2875 2600
F 0 "#PWR018" H 2875 2600 30  0001 C C
F 1 "GND" H 2875 2530 30  0001 C C
	1    2875 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 4862F09A
P 2396 1785
F 0 "#PWR019" H 2396 1785 30  0001 C C
F 1 "GND" H 2396 1715 30  0001 C C
	1    2396 1785
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 4862F018
P 3600 1785
F 0 "#PWR020" H 3600 1785 30  0001 C C
F 1 "GND" H 3600 1715 30  0001 C C
	1    3600 1785
	1    0    0    -1  
$EndComp
$Sheet
S 7650 6700 1650 200 
F0 "Registers and LEDs" 60
F1 "./bicycleledpov-sheet_02.sch" 60
F2 "SPI_SS1" I R 9300 6750 60 
F3 "SPI_SS0" I R 9300 6850 60 
F4 "SPI_MOSI" I L 7650 6750 60 
F5 "SPI_SCKL" I L 7650 6850 60 
$EndSheet
Text Notes 7915 3285 1    80   ~
Bootloader button
$Comp
L GND #PWR021
U 1 1 485EAA84
P 7610 3350
F 0 "#PWR021" H 7610 3350 30  0001 C C
F 1 "GND" H 7610 3280 30  0001 C C
	1    7610 3350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 485EA9C8
P 7610 2950
F 0 "SW1" H 7615 3090 50  0000 C C
F 1 "SW_PUSH" H 7610 2870 50  0001 C C
	1    7610 2950
	0    1    1    0   
$EndComp
$Comp
L C C5
U 1 1 485E9C78
P 2396 1485
F 0 "C5" H 2446 1585 50  0000 L C
F 1 "C" H 2446 1385 50  0001 L C
	1    2396 1485
	-1   0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 485E9B91
P 3600 1460
F 0 "C4" H 3650 1560 50  0000 L C
F 1 "C" H 3650 1360 50  0001 L C
	1    3600 1460
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 485E9B2A
P 3000 1135
F 0 "X1" H 2990 1320 60  0000 C C
F 1 "CRYSTAL" H 3000 985 60  0001 C C
	1    3000 1135
	-1   0    0    1   
$EndComp
$Comp
L R R65
U 1 1 485E7E7C
P 2430 3350
F 0 "R65" V 2430 3355 50  0000 C C
F 1 "R" V 2430 3350 50  0001 C C
	1    2430 3350
	0    1    1    0   
$EndComp
$Comp
L R R66
U 1 1 485E7E7B
P 2430 3450
F 0 "R66" V 2430 3445 50  0000 C C
F 1 "R" V 2430 3450 50  0001 C C
	1    2430 3450
	0    1    1    0   
$EndComp
$Comp
L R R71
U 1 1 485D4F44
P 6815 4095
F 0 "R71" V 6820 4085 50  0000 C C
F 1 "R" V 6815 4095 50  0001 C C
	1    6815 4095
	-1   0    0    1   
$EndComp
$EndSCHEMATC
