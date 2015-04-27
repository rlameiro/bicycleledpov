# Description #
![http://bicycleledpov.googlecode.com/svn-history/r232/trunk/Pictures/firmware_diagram/firmware-diagram.png](http://bicycleledpov.googlecode.com/svn-history/r232/trunk/Pictures/firmware_diagram/firmware-diagram.png)

The firmware have two main distinct tasks - making the POV and communicating with PC SoFtware, implementing the FirmwareApi. They never happen at same time.

MCU stop/start running each one of this two tasks when USB cable is connected. MCU detects USB cable connection/disconnection by monitoring the +5 volts USB voltage present on cable - when USB cable is disconnected that voltage is 0 volts while connected is +5 volts.

## Communications with PC Software ##
When hardware is connected to PC by USB, a new serial port will appear on PC, because we are using [Dean Camera's MyUSB library](http://www.fourwalledcubicle.com/MyUSB.php) to implement a kind of "USB-RS232 Device".

Inside the MCU we get the data that should be outputted to RS232 BUS, but instead of that, we use it directly. When we need to send data to PC we send it as if it did come from RS232 BUS. We used as working base the "USB-RS232 Device demo" of [MyUSB library](http://www.fourwalledcubicle.com/MyUSB.php) - thanks Dean!!

The data received/sent from/to PC is always putted on two ring buffers called "`Rx_Buffer`" and "`Tx_Buffer`".

As soon as `Rx_Buffer` have some data, MCU will read it and implement the FirmwareApi.

## Making POV ##
Making POV task are not yet implemented however it should be not much difficult.

This task should measure the time between impulses of sensor hall effect and divide that time in 256 equal parts. On each that part time, MCU should read 64 bits from DataFlash memory and send them to LEDs drivers.

# Download the latest firmware version #
The latest firmware version is always [available on SVN server](http://code.google.com/p/bicycleledpov/source/browse/trunk/Firmware) - [read here how to download it](http://code.google.com/p/bicycleledpov/source/checkout).

# Build the firmware #
## On GNU/Linux Ubuntu ##
  1. [Download the latest version from SVN](http://code.google.com/p/bicycleledpov/source/checkout);
  1. Use Synaptic Package Manager to install the following packages: avr-libc; binutils-avr; gcc-avr.
  1. Go to Firmware directory using shell and issue the following commands:
```
make clean
make
```
A new file with name "BicycleLEDPOV.hex" should appear on actual directory.

## On MS Windows ##
You should install [WinAVR](http://winavr.sourceforge.net/) and you may use AVRStudio.

# Download firmware to hardware #
## On GNU/Linux Ubuntu ##
### Using dfu-programmer (recommended) ###
The AT90USB162 MCU comes from factory with an USB bootloader which permits to download firmware to internal flash memory on MCU.

To enter in the bootloader mode, there must be hold the bootloader button and then press the reset button.

  1. Use Synaptic Package Manager to install the following package: dfu-programmer;
  1. Go to Firmware directory using shell and issue the following commands:
```
sudo make usbprogram
```

Example:

![http://bicycleledpov.googlecode.com/svn-history/r244/trunk/Pictures/20080722-using_dfu_programmer.png](http://bicycleledpov.googlecode.com/svn-history/r244/trunk/Pictures/20080722-using_dfu_programmer.png)

The firmware should be downloaded without errors - finally just hit reset button to leave bootloader mode and firmware will start running.

### Using FLIP ###
[FLIP](http://www.atmel.com/dyn/products/tools_card.asp?tool_id=3886) is a GUI tool from Atmel, it needs Java Runtime Environment.

## On MS Windows ##
### Using FLIP ###
[FLIP](http://www.atmel.com/dyn/products/tools_card.asp?tool_id=3886) is a GUI tool from Atmel, it needs Java Runtime Environment.