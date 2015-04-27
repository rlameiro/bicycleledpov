Se also the [BicycleLEDPOVAPI](BicycleLEDPOVAPI.md) related page.

# Extended API #
**Hardware Version 1.0.0**
This extended part of API is implemente on hadware version 1.0.0.

## Sensor hall effect ##
**Command 100: Get sensor state**. Hardware returns one byte with value 1 if sensor detects a magnectic field, otherwise returns 0.

Example:
  * values sent to hardware: `[`100`]`
  * values received from hardware: `[`0`]` `[`1`]` - in this case sensor detects a magnetic field.

**Command xxx: Get state of sensor hall effect Vcc line**.

**Command xxx: Enable sensor hall effect Vcc line**.

**Command xxx: Disable sensor hall effect Vcc line**.

## LEDs ##
**Command 101: Write LEDs states**. A sequence of bytes are sent to hardware, where which bit indicates the state of each LED, being value 1 LED ON state and 0 LED off state. First bit of the first byte respresents the value of LED number 1.

The number of bytes to be sent indicating the state of LEDs depends on each hardware version.

Example:
  * values sent to hardware: `[`101`]` `[`byte\_1`]` `[`byte\_2`]` `[`...`]`
  * values received from hardware: `[`0`]`

**Command xxx: Get state of SS0 line**.

**Command xxx: Set SS0 line**.

**Command xxx: Clear SS0 line**.

**Command xxx: Get state of SS1 line**.

**Command xxx: Set SS1 line**.

**Command xxx: Clear SS1 line**.

## DataFlash memory ##
**Command xxx: Get state of DataFlash Vcc line**.

**Command xxx: Enable DataFlash Vcc line**.

**Command xxx: Disable DataFlash Vcc line**.

**Command xxx: Get state of hold line**.


**Command xxx: Set hold line**.

**Command xxx: Clear hold line**.

**Command xxx: Get state of SS2 line**.

**Command xxx: Set SS2 line**.

**Command xxx: Clear SS2 line**.

## SPI BUS ##
**Command xxx: Get state of MOSI line**.

**Command xxx: Set MOSI line**.

**Command xxx: Clear MOSI line**.

**Command xxx: Get state of MISO line**.

**Command xxx: Set MISO line**.

**Command xxx: Clear MISO line**.

**Command xxx: Get state of SCLK line**.

**Command xxx: Set SCLK line**.

**Command xxx: Clear SCLK line**.