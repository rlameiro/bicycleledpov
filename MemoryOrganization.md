Each frame is composed of three different informations: **time of the frame**, **number of the next frame** and **frame data**:
  * **time of the frame** -> size: 2 bytes; time in 10 ms multiples. Minimum of 0 ms and maximum of ~10 minutes;

  * **number of the next frame** -> size: 3 bytes; time in 10 ms multiples. Minimum of 0 frames and maximum of 16777216 frames;

  * **frame data** -> size: 1024 bytes; one LED = 1 bit; 32 LEDs `*` 256 radial lines = 8192 bits.

So in total, each frame is composed of 1029 bytes.

First frame will occupy the first 1029 bytes in memory, the second the next 1029 bytes and so on, like this:

`Address 0000 -> 1028 -- [frame 1] `

`Address 1029 -> 2057 -- [frame 2] `

`Address 2057 -> 3086 -- [frame 3] `

`.............. `