# Tests to find a good, simple and cheap DC-DC IC and circuit #
## Using MAX756 ##
On date 2 of July of 2008, JpCasainho assembled a DC-DC converter that boots his +2,4 volts at input to +5 volts at his output, with at least 100mA of current at output. JpCasainho had as reference the [Minty Boost](http://www.ladyada.net/make/mintyboost/) circuit.

Here is the DC-DC circuit at testing - high quality version [here](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/20080702-hardware-dc_dc.jpg):

![http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/20080702-hardware-dc_dc-x600.jpg](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/20080702-hardware-dc_dc-x600.jpg)

And the schematic:

![http://bicycleledpov.googlecode.com/svn-history/r148/trunk/BicycleLEDPOV/Pictures/20080703-hardware-dc_dc_schematic.png](http://bicycleledpov.googlecode.com/svn-history/r148/trunk/BicycleLEDPOV/Pictures/20080703-hardware-dc_dc_schematic.png)

Three tests were made, using a RL of 100K, 100R and 47R  and without RL.

### Without RL ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r161/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-01.png](http://bicycleledpov.googlecode.com/svn-history/r161/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-01.png)

### With RL 100K ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_100K-20080702-01.png](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_100K-20080702-01.png)

![http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_100K-20080702-02.png](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_100K-20080702-02.png)

### With RL 110R ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r162/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-03.png](http://bicycleledpov.googlecode.com/svn-history/r162/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-03.png)

![http://bicycleledpov.googlecode.com/svn-history/r161/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-02.png](http://bicycleledpov.googlecode.com/svn-history/r161/trunk/BicycleLEDPOV/Pictures/20080706-MAX756_RL110R_Cin_and_Cout_47uF-02.png)

### With RL 47R ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-01.png](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-01.png)

![http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-02.png](http://bicycleledpov.googlecode.com/svn/trunk/BicycleLEDPOV/Pictures/hardware-dc_dc-osciloscope-RL_47R-20080702-02.png)

## Using MAX1764 ##
This tests were made with some capacitors and inductor used on MAX756 tests.
### Without RL ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-01.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-01.png)

### With RL 110R ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-02.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-02.png)

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-03.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_47uF-03.png)

### With RL 110R ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

On this test, capacitors were changed to 100uF.

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_100uF-01.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-MAX1764_RL110R_Cin_and_Cout_100uF-01.png)

## Using TPS61070 ##
### Without RL ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-03.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-03.png)

### With RL 110R ###
Oscilloscope channel 1 on Vout and channel 2 on positive side of schottky diode.

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-02.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-02.png)

![http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-01.png](http://bicycleledpov.googlecode.com/svn-history/r160/trunk/BicycleLEDPOV/Pictures/20080706-TPS61070_RL110R_Cin_and_Cout_47uF-01.png)

