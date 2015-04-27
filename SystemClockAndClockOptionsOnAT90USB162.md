# Default Clock Source #
The device is shipped with internal RC oscillator at 8.0 MHz and with the fuse CKDIV8 programmed, resulting in 1.0 MHz system clock. The startup time is set to maximum and time-out period enabled. (CKSEL = "0010", SUT = "10", CKDIV8 = "0"). The default setting ensures that all users can make their desired clock source setting using any available programming interface.

# Clock Switch #
In the AT90USB82/162 product, the Clock Multiplexer and the System Clock Prescaler can be
modified by software.

**Example of use**

The modification can occur when the device enters in USB Suspend mode. It then switches from External Clock to Calibrated RC Oscillator in order to reduce consumption. In such a configuration, the External Clock is disabled.
The firmware can use the watchdog timer to be woken-up from power-down in order to check if there is an event on the application.
If an event occurs on the application or if the USB controller signals a non-idle state on the USB line (Resume for example), the firmware switches the Clock Multiplexer from the Calibrated RC Oscillator to the External Clock.

# System Clock Prescaler #
The AT90USB82/162 has a system clock prescaler, and the system clock can be divided by setting the “Clock Prescale Register – CLKPR”. This feature can be used to decrease the system clock frequency and the power consumption when the requirement for processing power is low. This can be used with all clock source options, and it will affect the clock frequency of the CPU and all synchronous peripherals. clkI/O, clkCPU, and clkFLASH are divided by a factor: 1; 2; 4; 8; 16; 32; 64; 128 and 256.

# USB Clock – clkUSB #
The USB is provided with a dedicated clock domain. This clock is generated with an on-chip PLL running at 48MHz. The PLL always multiply its input frequency by 6. Thus the PLL clock register should be programmed by software to generate a 8MHz clock on the PLL input.

# Internal PLL for USB interface #
The internal PLL in AT90USB82/162 generates a clock frequency that is 6x multiplied from nominally 8 MHz input. The source of the 8 MHz PLL input clock is the output of the internal PLL clock prescaler that generates the 8 MHz.

For more information, see the datasheet.