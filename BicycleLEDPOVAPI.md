Connecting Bicycle LED POV hardware to PC using an USB cable, a new virtual serial port will appear on PC. Commands are sent to the virtual serial port to interact with Bicycle LED POV HaRdware.

The API have two parts, the “base” one should always be implemented on each hardware and provides minimum functionality while the BiCycleLEDPOVExtendedAPI part may differs on each hardware and is not necessary to be implement.



# Base API #
### Command not implemented ###

Input value(s):
| **byte number** | **value** |
|:----------------|:----------|
| 01 | xx |

Output value(s):
| **byte number** | **value** | **description** |
|:----------------|:----------|:----------------|
| 01 | 24 | Length of the next string in bytes. |
| 02 and following bytes | String: "command not implemented". | The string must be terminated with a null char. |

## Hardware ##
### Command 1: Get identification string ###

Input value:
| **byte number** | **value** |
|:----------------|:----------|
| 01 | 01 |

Output values:
| **byte number** | **value** | **description** |
|:----------------|:----------|:----------------|
| 01 | 35 | Length of the next string in bytes. 35 is the value of the next example string. |
| 02 and following bytes | Example string: "Bicycle LED POV [r1](https://code.google.com/p/bicycleledpov/source/detail?r=1).1 fw1.0 20081022". | This is an example string, and it must be terminated with a null char. |

### Command 2: Get hardware properties ###

Input value:
| **byte number** | **value** |
|:----------------|:----------|
| 01 | 02 |

Output values:
| **byte number** | **value** | **description** |
|:----------------|:----------|:----------------|
| 01 |  14 | Number of the next bytes. |
| 02 | Example: 16  | Byte for API version. |
| 03 | Example: 16 | Byte for extended API version. |
| 04 | Example: 16 | Byte for firmware version. |
| 05 | Example: 0 | Byte 01 for memory size in kb. |
| 06 | Example: 32 | Byte 02 for memory size in kb. In this example, memory have 32 kbytes. |
| 07 | Example: 1 | byte 01 for number of radial lines. |
| 08 | Example: 0 |byte 02 for number of radial lines. In this example, 256 radial lines. |
| 09 | Example: 0 | byte 01 for number of LEDs per radial line. |
| 10 | Example: 32 | byte 02 for number of LEDs per radial line. In this example, 32 LED per radial line. |
| 11 | Example: 1 | byte 01 for color depth properties (CDP).' (see below) |
| 12 | Example: 0 | byte 02 for color depth properties (CDP).' (see below) |
| 13 | Example: 0 | byte 03 for color depth properties (CDP).' (see below) |
| 14 | Example: 0 | byte 04 for color depth properties (CDP).' (see below) |
| 15 | Example: 2 | byte 01 for number of independent LED-strips. |

CDP bytes description:
| byte number | content |
|:------------|:--------|
| 11 | byte 01 for depth of supported monochrome shades (grayscale design) in bits. |
| 12 | byte 02 for depth of supported red shades (tricolor design) in bits. |
| 13 | byte 03 for depth of supported green shades (tricolor design) in bits. |
| 14 | byte 04 for depth of supported blue shades (tricolor design) in bits. |

## Memory ##
### Command 10: Clear all memory ###

Input value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | 10 |

Output value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | number of the next bytes. |
| 02 | byte 01 for length of cleared bytes. |
| 03 and following bytes | byte 02 and following bytes for length of cleared bytes. |

### Command 11: Read a stream of bytes from memory ###

Input value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | 11 |
| 02 | byte 01 for number of bytes of the stream to read. |
| 03 | byte 02 for number of bytes of the stream to read. |
| 04 | byte 01 for address of memory for the beginning of the stream to read. |
| 05 | byte 02 for address of memory for the beginning of the stream to read. |
| 06 | byte 03 for address of memory for the beginning of the stream to read. |
| 07 | byte 04 for address of memory for the beginning of the stream to read. |

Output value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | number of the next bytes. |
| 02 | byte 01 for length of stream to read. |
| 03 | byte 02 for length of stream to read. |
| 04 and following bytes | delivered byte of stream. |

### Command 12: Write a stream of bytes to memory ###

Input value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | 12 |
| 02 | byte 01 for length of stream to write. |
| 03 | byte 02 for length of stream to write. |
| 04 | byte 01 for address of memory for the beginning of the stream to write. |
| 05 | byte 02 for address of memory for the beginning of the stream to write. |
| 06 | byte 03 for address of memory for the beginning of the stream to write. |
| 07 | byte 04 for address of memory for the beginning of the stream to write. |
| 08 and following bytes | byte of stream to write. |

Output value(s):
| **byte number** | **content** |
|:----------------|:------------|
| 01 | number of the next bytes. |
| 02 | byte 01 for number of written bytes. |
| 03 | byte 02 for number of written bytes. |