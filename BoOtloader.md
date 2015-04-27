The AT90USB162 MCU comes with preloaded USB bootloader from factory. If for some reason the bootloader is erased, It can be programmed again by ISP programing or other parallel programing.

Here is the HEX file of the bootloader: [BootloaderDFU.hex](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Firmware/Bootloaders/DFUClass/BootloaderDFU.hex)

Just to remember:
The bootloader start address can be set in the makefile on:
```
# Starting byte address of the bootloader
BOOT_START = 0xFE00
```