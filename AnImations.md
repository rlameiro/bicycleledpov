The Bicycle LED Pov should be able to show images during a certain time and jump through a sequence of them. Example:
  * show first image during 1000ms and jump to the second one;
  * show second image during 200ms and jump to the third one;
  * show third image during 100ms and jump to the fourth one;
  * show fourth image during 200ms and jump to the first one;

The minimum time between frames should be at least 1/25 of second - 40ms.

# Simple image #
To show a continuously an image, the system should be programed to jump from 1st image to 1st - the same image. The time between images are not important but could be for example, 1000ms.

# Animations with frames #
Any animation can be draw using the time between images and the sequence between them.

# Video #
Since a video is a sequence of images and the system can show 25 images per second, a video can be show but a VERY large EEPROM memory would be needed. There are a few hypotheses as reduce frame rate or use a SPI DataFlash Memory.
Actually there are EEPROMs with 1Mb and DataFlash of 64Mb.