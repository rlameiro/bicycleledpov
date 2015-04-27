# Power sources #
## +BATT ##
HaRdware uses 2 AAA `NiMh` cells or alkaline cells.

Assuming the use of `NiMh` cells, +2,4 volts are available for drive LEDs.

Current used by LEDs can be from about 0,5 A to about 1,3 A.

## Vcc +5V ##
MCU needs at least +3,3 volts to have USB peripheral working. Was decided to use an DC-DC circuit to elevate the +BATT voltage to +5 volts. With +5 volts, MCU can run at his maximum speed of 16MHz.

EEPROM memory and sensor hall effect are also sourced with +5 volts.

Current used by MCU, EEPROM memory and sensor hall effect, should be less than 35 mA.

# Using a DC-DC #
Tests were made to find a good, simple and cheap DC-DC circuit and IC. Read more about tests made on TestsToDcDcCircuitsAndIcs page.

The final schematic is this one:

![http://bicycleledpov.googlecode.com/svn-history/r148/trunk/BicycleLEDPOV/Pictures/20080703-hardware-dc_dc_schematic.png](http://bicycleledpov.googlecode.com/svn-history/r148/trunk/BicycleLEDPOV/Pictures/20080703-hardware-dc_dc_schematic.png)