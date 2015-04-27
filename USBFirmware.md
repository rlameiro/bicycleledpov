# Thoughts #
Have USB

&lt;-&gt;

RS232 on MCU is nice because is very easy to work with it on PC side and on MCU side. There is also software made for POV from Ladyada POV project, which can use a serial port.

An API should be defined to send data from the PC to the Bicycle LED POV. On PC, one should send commands to write and read from the EEPROM, to turn on and off any LED, to test the sensor hall effect (for example: turn on and off the 1st LED as soon as sensor turns on/off) and to read the firmware version.
Bicycle LED Pov should answer to every command with acknowledge messages or error codes.

# Which USB Software Library to use? #

## Atmel USB Software Library for AT90USBxxx Microcontrollers ##
Atmel gives the _AVR272: USB CDC Demonstration UART to USB Bridge_ application note with code which documents a USB

&lt;-&gt;

RS232 on AT90USB MCUs - here the [code](http://www.atmel.com/dyn/resources/prod_documents/AVR_USB_Software.htm) and the [documentation](http://www.atmel.com/dyn/resources/prod_documents/doc7619.pdf).

## Dean Camera's MyUSB library ##
[MyUSB library for USB-enabled AVR microcontrollers](http://www.fourwalledcubicle.com/wiki/Wikka/MyUSB)

_Dean Camera's MyUSB library_ is easier to understand for me than the _Atmel USB Software Library for AT90USBxxx Microcontrollers_, also have a lot of Demos and I did build with success the Demo of the _USBtoSerial_ on "my" GNU/Linux Ubuntu. I also saw that MyUSB library includes two different USB bootloaders, which can be useful for future development. I will use MyUSB library :-)