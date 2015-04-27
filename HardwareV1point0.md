# Description #
![http://bicycleledpov.googlecode.com/svn/trunk/Pictures/hardware_diagram/diagram-700x.png](http://bicycleledpov.googlecode.com/svn/trunk/Pictures/hardware_diagram/diagram-700x.png)

## Microcontroller ##
The microcontroller unit (MCU) is the [Atmel AT90USB162](http://www.atmel.com/dyn/products/product_card.asp?part_id=4097), 8 bits microcontroller with USB functionality.

## Sensor hall effect ##
MCU will be able to determine the velocity of the bicycle wheel by reading impulses of the [hall effect sensor](http://www.allegromicro.com/en/Products/Part_Numbers/3213/3213.pdf).

## Memory ##
Knowing the velocity, MCU will read the images from the DataFlash memory using SPI bus, and in the correct timing will send them to the LED drivers using SPI bus, turning on and off the LEDs.

## LEDs and drivers ##
The LED drivers will be composed of [74HC595](http://www.fairchildsemi.com/ds/MM%2FMM74HC595.pdf) IC (Serial to Parallel latch using SPI bus) and a resister in series with LEDs.

## Power source ##
The energy for HaRdware will be source from 2 AAA `NiMh` rechargeable cells or alkaline cells.

The voltage of 2 cells will drive directly the LEDs drivers. +3.3 volts are available for to use by MCU, DataFlash memory and the hall effect sensor, thanks to DC-DC circuit.

Read more on PowerStage page.

# Schematic #
Schematic was drawn using [KiCAD](ToOls.md). The source files for schematic can be found [here](http://code.google.com/p/bicycleledpov/source/browse/tags/Hardware-V1.0).

Preview of [bicycleledpov-schematic-v1.0-sheet\_1.png](http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/bicycleledpov-schematic-v1.0-sheet_1.png):

![http://bicycleledpov.googlecode.com/svn-history/r276/tags/Hardware-V1.0/20080802-bicycleledpov-schematic-v1.0-sheet_1-preview.png](http://bicycleledpov.googlecode.com/svn-history/r276/tags/Hardware-V1.0/20080802-bicycleledpov-schematic-v1.0-sheet_1-preview.png)

Preview of [bicycleledpov-schematic-v1.0-sheet\_2.png](http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/bicycleledpov-schematic-v1.0-sheet_2.png):

![http://bicycleledpov.googlecode.com/svn-history/r276/tags/Hardware-V1.0/20080802-bicycleledpov-schematic-v1.0-sheet_2-preview.png](http://bicycleledpov.googlecode.com/svn-history/r276/tags/Hardware-V1.0/20080802-bicycleledpov-schematic-v1.0-sheet_2-preview.png)

# Part list #

TODO: update the list.

| **Reference** | **Value** | **Quantity** | **Unity price** |
|:--------------|:----------|:-------------|:----------------|
| `R1 - R64` | 56R 1/8W 5% | 64 | [~0.035€](http://pt.farnell.com/fixed) |
| `R65, R66` | 22R 1/8W 1% | 2 | [~0.035€](http://pt.farnell.com/fixed) |
| `R67, R68`  | 330R 1/8W 5% | 2 | [~0.035€](http://pt.farnell.com/fixed) |
| `R69 - R73`  | 51K 1/8W 5% | 5 | [~0.035€](http://pt.farnell.com/fixed) |
| `C1 - C3` | 100nF 50V | 3 | [0.075€](http://uk.farnell.com/9406387/passives/product.us0?sku=multicomp-u0805r104kct) |
| C4, C5 | 22pF 50V | 2 | [0.031€](http://pt.farnell.com/1362555/passives/product.us0?sku=phycomp-223886115229) |
| C7, C6 | 47uF 16V | 2 | [0.35€](http://pt.farnell.com/9695664/passives/product.us0?sku=panasonic-eeefk1c470ur) |
| D1 - D64 | Avago Ref: HSMJ-A100-Q00J1 | 64 | [0.116€](http://pt.farnell.com/jsp/search/productdetail.jsp?SKU=4134369) |
| D65 | BAS85 | 1 | [0.24€](http://uk.farnell.com/1097282/semiconductors-discretes/product.us0?sku=nxp-bas85) |
| L1 | Bourns Ref: SDR0805-100ML | 1 | [0.24€](http://uk.farnell.com/1463486/passives/product.us0?sku=bourns-sdr0805-100ml) |
| U1 - U8 | 74VHC595 | 8 | [0.29€](http://pt.farnell.com/1607849/semiconductors-integrated-circuits/product.us0?sku=texas-instruments-sn74hc595dr) |
| U9 | A3213ELHLT-T | 1 | [0.83€](http://pt.farnell.com/1457117/semiconductors-integrated-circuits/product.us0?sku=allegro-microsystems-a3213elhlt-t) |
| U10 | AT90USB162-16AU | 1 | [3.56€](http://pt.farnell.com/1455073/semiconductors-integrated-circuits/product.us0?sku=atmel-at90usb162-16au) |
| U11 | MAX756CSA+ | 1 | [$3.38](http://www.maxim-ic.com/quick_view2.cfm/qv_pk/1167/t/or) |
| U12 | AT26DF081A-SU | 1 | [1.42€](http://pt.farnell.com/1455015/semiconductors-integrated-circuits/product.us0?sku=atmel-at26df081a-su) |
| SW1, SW2  | FSM4JSMA | 2 | [0.18€](http://pt.farnell.com/jsp/search/productdetail.jsp?SKU=3801305) |
| USB-MB-H | Molex Ref: 675031020 | 1 | [0.76€](http://uk.farnell.com/1125348/connectors/product.us0?sku=molex-675031020) |
| X1 | AVX Ref: CX49GFWB08000H0PESZZ | 1 | [0.91€](http://uk.farnell.com/1368799/passives/product.us0?sku=avx-cx49gfwb08000h0peszz) |
| BT1, BT2 | AAA battery clip | 4 | [2,14€ for 5 units](http://uk.farnell.com/908721/electrical-circuit-protection/product.us0?sku=keystone-82) |
| P1 | Not Assembled | 1 | 0 |
| P2, P3 | Not Assembled | 2 | 0 |
|  |  |  | Total price: 26,41€ |

# Printed circuit board #
Schematic was drawn using [KiCAD](ToOls.md). The source files for PCB can be found [here](http://code.google.com/p/bicycleledpov/source/browse/tags/Hardware-V1.0).

Image of layer components and components:

![http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/20080802-bicycleledpov-pcb-v1.0-02.png](http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/20080802-bicycleledpov-pcb-v1.0-02.png)

Image of layer cooper and components:

![http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/20080802-bicycleledpov-pcb-v1.0-03.png](http://bicycleledpov.googlecode.com/svn-history/r275/tags/Hardware-V1.0/20080802-bicycleledpov-pcb-v1.0-03.png)

# Pictures of assembled PCB #

![http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-02-700x.jpg](http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-02-700x.jpg)

Higher resolution: [bicycleledpov-hardware-v1.0-01.jpg](http://code.google.com/p/bicycleledpov/source/browse/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-01.jpg)

![http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-01-700x.jpg](http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-01-700x.jpg)

Higher resolution: [bicycleledpov-hardware-v1.0-02.jpg](http://code.google.com/p/bicycleledpov/source/browse/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-02.jpg)

## Things that can be improved on PCB ##
TODO