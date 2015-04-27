## 2008.10.18 ##
### News from JpCasainho: ###
I had found one error on actual schematic. Also I found that sensor hall effect have "noise" at his output, as if it is detecting any magnet without any near - I resolved this using a simple low pass RC filter.

I decided to make a simple MiniPOV with actual hardware. It is using just MyUSB scheduler to do delays of 3ms. Firmware is very simple, you can get it [here](http://code.google.com/p/bicycleledpov/source/browse/trunk/hardware/firmware/minipov?spec=svn331&r=331).

On that image, just 8 LEDs are used to write that message. The message are stored in RAM of MCU, sensor hall effect and external memory are not used.

Me rotating the hardware and taking a picture on a dark room:

![http://bicycleledpov.googlecode.com/svn-history/r331/trunk/docs/pictures/20081018-bicycleledpov-minipov.jpg](http://bicycleledpov.googlecode.com/svn-history/r331/trunk/docs/pictures/20081018-bicycleledpov-minipov.jpg)

## 2008.09.23 ##
### News from JpCasainho: ###
I started re-writing the API - [BicycleLEDPOVAPI](BicycleLEDPOVAPI.md). The API will permit that different hardwares works with the same software, which is great because people will be able to build hardwares with different memories, sizes, with different number of LEDs, RGB, etc, and software will continue to work on that hardwares.

## 2008.08.20 ##
### News from JpCasainho: ###
**New member**

HerbertoSmith is the new member!, he lives at my city, Águeda. He likes Arduino and Python. Welcome Herberto, let's start hacking on Python!! :-)

The first PCB of HaRdware V1.0 were assembled, a few weeks ago:
![http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-02-700x.jpg](http://bicycleledpov.googlecode.com/svn/tags/Hardware-V1.0/20080802-bicycleledpov-hardware-v1.0-02-700x.jpg)

The FirmwareAPI were changed to give more control to SoFtware on HaRdware.

I were talking with RicardoLameiro and HerbertoSmith, maybe we will start using wxPython instead of Tkinter.

## 2008.07.26 ##
### News from JpCasainho: ###
PCB is finished. Next Monday I should be able to drill one on a CNC machine. I will assembly just a few components and see if i can program the MCU, then i will send it to DonaldZiems. My PCB and the one for RicardoLameiro will follow as soon as possible - I will be on holidays since day 2 until day 12 of August.

Image of front side superimposed on back side, with components, tracks and ground signals zones on each side:

![http://bicycleledpov.googlecode.com/svn-history/r255/trunk/docs/pictures/20080726-BicycleLEDPOV-pcb-01.png](http://bicycleledpov.googlecode.com/svn-history/r255/trunk/docs/pictures/20080726-BicycleLEDPOV-pcb-01.png)

The board have about 14,9cm x 4,7cm. See more information o HaRdware page.

## 2008.07.22 ##
### News from RicardoLameiro: ###

Well I updated the SoFtware page with recent screenshots to people have an insight. Please look at the usability and say what you do think. also I am saying goodbye for 2 weeks, I am going on vacations, will be contactable, but i think I will not programm or update things.
Happy summer to everyone!!!!

## 2008.07.17 ##
### News from JpCasainho: ###
I bought and received components from Farnell - I will assembly 3 units of Bicycle LED POV, one for each actual developers: JpCasainho, DonaldZiems and RicardoLameiro.

DonaldZiems and me, we are working on PCB, I hope to have it ready until the end of next weekend so on next Monday I can drill one testing PCB.

Here is one image of actual PCB on early stage:

![http://bicycleledpov.googlecode.com/svn-history/r219/trunk/docs/pictures/20080717-BicycleLEDPOV-pcb.jpg](http://bicycleledpov.googlecode.com/svn-history/r219/trunk/docs/pictures/20080717-BicycleLEDPOV-pcb.jpg)

## 2008.07.11 ##
### News from JpCasainho: ###
**Changes on hardware**

There is some relevant changes on hardware - we have changed from using an EEPROM memory to a DataFlash memory. For almost the same cost we can have a memory that holds 32 times more data.

We will be using an 8Mb, the cheapest DataFlash memory available - the [AT26DF081A-SU for 1,42€](http://pt.farnell.com/1455015/semiconductors-integrated-circuits/product.us0?sku=atmel-at26df081a-su). With this 8Mb we should be able to hold about 1000 images!!

This DataFlash have the same physical size of EEPROM memory and also the same connections. Energy used is also almost the same, ~15mA when writing data. Also working with it on FiRmware is almost the same, it have some new good features.

Only one question, this memory works between 2,7 to 3,6 volts Vcc - we decided to change DC-DC to work for 3,3 volts instead of 5 volts. I didn't test it yet on protype, but it should work.

MCU now runs with Vcc 3,3 volts which means that will not be able to run at 16MHz, just at 8MHz.

**PCB and Part list**

Since schematic is stable now, we started working on Part list and PCB. We hope to have a working V1.0 hardware in next 3 weeks.

## 2008.07.06 ##
### News from JpCasainho: ###
In the last days I tested 3 different ICs for DC-DC circuits. See the tests results with oscilloscope images on page TestsToDcDcCircuitsAndIcs.

Schematic is done :-) To get the full schematic, visit the HaRdware page. Here is a preview:

![http://bicycleledpov.googlecode.com/svn-history/r169/trunk/docs/pictures/20080706-schematic-sheet_01-preview.png](http://bicycleledpov.googlecode.com/svn-history/r169/trunk/docs/pictures/20080706-schematic-sheet_01-preview.png)

Now is time to do the part list and going shopping :-) - also work on PCB has started.

## 2008.07.02 ##
### News from JpCasainho: ###
Today I finish my prototype - it uses now just 2 AAA `NiMh` cells. Well, prototype just have 8 LEDs soldered instead of the 64 it should have - I am not motivated to solder all 64 LEDs.

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080703-prototype-600x-02.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080703-prototype-600x-02.jpg)

In the next 2 days we should release version 1.0 of the schematic. See more info on HaRdware page.

## 2008.07.02 ##
### News from DonaldZiems: ###
Well, I goofed.  I needed to upload something, but not thinking, I used my Windows machine, which apparently uses Subversion 1.5, and automatically upgraded the subversion data to 1.5, which is incompatible with 1.4 (which is what Ubuntu uses in their repositories)  I'm working on downgrading it currently, so hopefully all will be well shortly.

Update:
Turns out, I can read using subversion 1.4.6 on my Hardy Heron computer, but not using subversion 1.4.4 on my Gutsy Gibbon computer.  Still working on a fix.

Update:
Should be all fixed now.


### News from JpCasainho: ###
Today I did work on the DC-DC, here is a picture of the assembled circuit  - high quality version [here](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080702-hardware-dc_dc.jpg):

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080702-hardware-dc_dc-x600.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080702-hardware-dc_dc-x600.jpg)

Here are the results on oscilloscope, with 100mA output current - channel 1 on Vout and channel 2 on positive side of schottky diode:

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-02.png](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-02.png)

This DC-DC works very good. DonaldZiems will draw this DC-DC circuit on schematic and I will test it on my working prototype of Bicycle LED POV. See more information on PowerStage page.

## 2008.06.29 ##
### News from RicardoLameiro: ###
Today I added Some info about software development to the ToOls page and also for the SVN management.

Added also one more function to the Firmware API - the Auto Scan feature.

I made also some improvements to the script/software aimed to improve the cross platform ability, not yet fully tested. Also implemented the dummy command and the firmware version command but they are untested in real hardware :) so maybe it is not working.

The GUI suffered a major redesign since the last screenshot :). The animation/picture design is stopped, and it will be the most difficult part for me... still thinking how to do it, if anyone with python knowledge and GUI toolkits master knowledge is welcome to help. At this moment the GUI toolkit used is Tk, but I think that wxPython will be better for this purpose. Will see...

I added some comments to the code to improve the readability of the code, it is still ugly but readable (python rocks!!).

Over and out.

RicardoLameiro


## 2008.06.25 ##
### News from DonaldZiems: ###

Alright, finally started making some updates to the schematic.

First and foremost, I split it into 3 sheets, one for the microcontroller, one for the EEPROM and sensor, and one for the LEDs.

Second, I linked all three sheets into a single hierarchy so that data paths from one sheet to another will function when we go to design the PCB.

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080625-BicycleLEDPOV-schematic.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080625-BicycleLEDPOV-schematic.jpg)

Third, the schematic sheet with the LEDs and shift registers should be complete.




### News from RicardoLameiro: ###

Well, the software to send commands and control the serial port is in development, for now I have a screenshot of a GUI (Graphic User Interface) to the software. I am doing the GUI in Tkinter toolkit, that is built in in python.

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080625-BicycleLEDPOV-software.png](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080625-BicycleLEDPOV-software.png)

Explanation:
to the left will be two listbox. the upper right will contain the available serial ports
in the bottom left a list of possible commands. to the upper right a scan button to search for serial ports, and to the bottom right a send command button. Prety straight forward I think. Please leave comments in the mailing list.

## 2008.06.21 ##
News from JpCasainho:

I and DonaldZiems, we have being working on schematic. I was working on some ideas to get the lowest possible power used while system is halt, I hope to test them on my prototype on the next days. Here goes some images from the schematic (schematic files can be found [here](http://code.google.com/p/bicycleledpov/source/browse/trunk/Schematics)):

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080622-BicycleLEDPOV-schematic-01.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080622-BicycleLEDPOV-schematic-01.jpg)

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080622-BicycleLEDPOV-schematic-02.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080622-BicycleLEDPOV-schematic-02.jpg)

## 2008.06.19 ##
News from JpCasainho:

**New member**

RicardoLameiro is the new member!!, an old friend mine from school. RicardoLameiro is working on SoFtware, using Python. Welcome :-)

**LED's + serial data latches working**

I wrote 2 new pages: SystemClockAndClockOptionsOnAT90USB162 and LeDs.

I had done a lot of code on FiRmware and I have now the LED's + the serial data latches working, here is 2 images showing that:

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080619-BicycleLEDPOV-prototype-02.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080619-BicycleLEDPOV-prototype-02.jpg)


This image show my Asus EEE PC with GNU/Linux Ubuntu running Cutecom, a program to send information by serial port. Development board is connected to PC by USB cable, I did used the _Test LEDs: command 3_ from FirmwareApi to turn on that LED's -- I did control the LED's using the PC. There are 2 AAA NiMh batteries under the board of the LED's, which give energy to LED's.

![http://code.google.com/p/bicycleledpov/source/browse/trunk/docs/pictures/20080619-BicycleLEDPOV-prototype-01.jpg](http://code.google.com/p/bicycleledpov/source/browse/trunk/docs/pictures/20080619-BicycleLEDPOV-prototype-01.jpg)

## 2008.06.10 ##
News from JpCasainho:

Today I tried to program the bootloader but I couldn't because I had problems on programing cable, I will try again later. While doing this I discovered that the bootloder is working, I didn't erase It.
I also did read on datasheet that MCU comes configured on fuses to run at Clock/8, so It's running at 1MHz and not at 8 MHz as I was expecting.

While investigating why the cable used to program didn't work, I took some pictures of USB data lines using the oscilosce, here is one from D- data line:

![http://bicycleledpov.googlecode.com/svn-history/r41/trunk/docs/pictures/20080609-USB_D_minus_line-02.jpg](http://bicycleledpov.googlecode.com/svn-history/r41/trunk/docs/pictures/20080609-USB_D_minus_line-02.jpg)

This was my first time that I say wave forms from USB data lines.

I did wired the sensor hall effect and made code to test it :-) - the FirmwareApi _Dummy command: command 1_ and _Test sensor hall effect: command 4_ is working correctly now. The code is on SVN.

I divided the code in parts: the task "PCLink\_Task" and
the "MakePOV\_Task".

PCLink\_task starts automatically running when USB is connected while
MakePOV\_Task stop running -- on this time we can communicate with the
hardware to download images on SPI EEPROM and test hardware.

When we disconnect USB, PCLink\_Task automatically stop and MakePOV\_Task starts
running, where it should take data from EEPROM and send to LED's, making the
POV :-)

Here is one picture of the development board + sensor hall effect:

![http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080610-BicycleLEDPOV-prototype-600x.jpg](http://bicycleledpov.googlecode.com/svn/trunk/docs/pictures/20080610-BicycleLEDPOV-prototype-600x.jpg)

I took some pictures and add them [here](http://code.google.com/p/bicycleledpov/source/browse/trunk/docs/pictures/) on SVN.

## 2008.06.08 ##
News from JpCasainho:

I was trying to build DFU bootloader code from Dean Camera without success, luckily I did used the [AVRFreaks forum and asked for help](http://www.avrfreaks.net/index.php?name=PNphpBB2&file=viewtopic&t=64923&start=0&postdays=0&postorder=asc&highlight=), the problem is now resolved and I did commit the changes. I am not really sure the bootloader is working since I have some questions yet and I didn't flash it - just tomorrow.

I started thinking on MemoryOrganization and on FirmwareApi. I also asked help to [Donald Ziems](http://code.google.com/u/dziems/) for selling me a SPI EEPROM memory, I don't have any as is much expensive for me to buy only that IC from Farnell - I should buy at least 40€ + VAT from Farnell.


## 2008.06.07 ##
News from JpCasainho:

I uploaded the first firmware version to SVN server, it can be accessed [here](http://code.google.com/p/bicycleledpov/source/browse/trunk/BicycleLEDPOV).

I can't program now the MCU using the dfu-programmer, maybe I erased the bootloader... next Monday I will try to program the bootloader using USBProg. I will try to use the bootloader written by Dean Camera.

In next days I would like to start writing and reading data to SPI EEPROM.

## 2008.06.05 ##
News from JpCasainho:


I received today my [AVR-USB-162 development board from Olimex](http://www.olimex.com/dev/avr-usb-162.html) and I did a few hacks in USBtoSerial program from [MyUSB library](http://www.fourwalledcubicle.com/MyUSB.php) and I got it working, but turning on the LED when I send value "1" to serial port and off the LED when I send "0" - It also send back to serial port the same vale sent before. Here some images (from GNU/Linux Ubuntu on my Asus eee pc 701):

![http://farm4.static.flickr.com/3002/2554924956_3a752a78e9_o.png](http://farm4.static.flickr.com/3002/2554924956_3a752a78e9_o.png)

![http://farm4.static.flickr.com/3065/2554113355_2e8756dc93_o.png](http://farm4.static.flickr.com/3065/2554113355_2e8756dc93_o.png)

It were very quick to install and use the [dfu-programmer](http://dfu-programmer.sourceforge.net/) and [avr-gcc](http://www.nongnu.org/avr-libc/) on GNU/Linux Ubuntu!!

## 2008.05.29 ##
News from JpCasainho:

I tested today two different sensor hall effects, the SS411A and the A3213ELHLT-T. The SS411A turns on with one pole and turns off with other pole from the magnet. The A3213ELHLT-T turns on and off with any pole from the magnet.

With the same magnet, I did measure the distance needed to turn on/off of each sensor: SS411A -> 1,8 cm and A3213ELHLT-T -> 1,5 cm.

I also tried the DC-DC IC NCP1450ASN30T1G which have 3 volts fixed output voltage. It worked well, I don't know why the NCP1450ASN50T1G (5 volts version) didn't worked to me last time.
Now I would like to find a DC-DC IC with embedded switches (the transistor + diode), to have a simpler circuit - probably I will use the [Minty Boost](http://www.ladyada.net/make/mintyboost/).

## 2008.05.28 ##
News from JpCasainho:


Today I received the DC-DC IC NCP1450ASN50T1G and I couldn't put It working :-( - I had low voltage output and with a lot of noise... I saw on oscilloscope the PWM output and the inductor signal going to ground... I saw that the DC-DC was in noncontinuous mode and I did put a larger load and saw It going to active region, with duty-cycle of PWM near to 50%.

I also received the sensor hall effect, I will test it in the next days.
My [AVR-USB-162 development board from Olimex](http://www.olimex.com/dev/avr-usb-162.html) is on the road, I hope to receive it in a week or so.

## 2008.05.25 ##
News from JpCasainho:

Since yesterday I did read the [MyUSB library for USB-enabled AVR microcontrollers](http://www.fourwalledcubicle.com/MyUSB.php) which I will prefer over _Atmel USB Software Library for AT90USBxxx Microcontrollers_.

I did build the Demo of the _USBtoSerial_ of _MyUSB_ library. Will be very easy to receive and send data to the serial port on the PC - _MyUSB_ library code is easy to understand, thanks [Dean Camera](http://www.fourwalledcubicle.com/)!!

I decided to buy the ~25€[AVR-USB-162 development board from Olimex](http://www.olimex.com/dev/avr-usb-162.html), since I bought recently a development board from Olimex for about 200€ and I am happy with the service.

## 2008.05.24 ##
News from JpCasainho:

I started yesterday reading about the Atmel MCU AT90USB162, It's cheap and can be bought on one unit on Farnell. I also find a cheap [development board from Olimex](http://www.olimex.com/dev/avr-usb-162.html) - ~25€:

![http://www.olimex.com/dev/images/AVR/AVR-USB-162-2.jpg](http://www.olimex.com/dev/images/AVR/AVR-USB-162-2.jpg)

Atmel gives a free code and explains how to make a USB

&lt;-&gt;

RS232 with that MCU. I think that is possible to use AT90USB162 for USB communication between PC + read data from SPI EEPROM and drive LEDs with image frames :-) -- so this project will be just that ;-) :-)

Also the AT90USB162 comes from Atmel with an USB bootloader that permits program the device by simple connecting It to PC by USB cable!! Nice, easy for development and hacking and all with development tools availabe for GNU/Linux, with full source code :-)