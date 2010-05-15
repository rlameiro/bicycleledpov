The tab "'Run' commands" for the debug should have this:

monitor halt
monitor mww 0xfffffd44 0x00008000
monitor mww 0xfffffd08 0xa5000001
monitor mww 0xfffffc20 0x00000601
monitor sleep 10
monitor mww 0xfffffc2c 0x00481c0e
monitor sleep 10
monitor mww 0xfffffc30 0x00000007
monitor sleep 10
monitor mww 0xffffff60 0x003c0100
monitor sleep 10
monitor flash write_image erase unlock main.bin 0x00100000
monitor gdb_breakpoint_override hard
monitor soft_reset_halt
continue
