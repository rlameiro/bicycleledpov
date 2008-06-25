#		Copyright (C) Ricardo Lameiro 2008
#		Bicicleledpov.py v 0.01 - transfer and control of the hardware via Serial port
#       
#       This program uses the pyserial module tha can be used in Windows and 
#       *nixes OSes. You can download this module at 
#       http://pyserial.sourceforge.net/
#
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 2 of the License, or
#       (at your option) any later version.
#       
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#       
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#       MA 02110-1301, USA.



import serial



print """ BicicleLedPOV 
          Choose one off the following commands
          1 - Command 1 - test
          2 - Command 2 - Version number"""


ser = serial.Serial(0, timeout = 5)


def comm(number):
	ser.open
	ser.write(number)
	rsp = ser.read()
	ser.close
	if rsp == number:
		print "command successful"
	else:
		print "Didn't receive a response"
		
command = int(raw_input("insert the desired command ->"))

if command == 1:
	number = "\x01"
	comm(number)
elif command == 2:
	number = "\x02"
	comm(number)
else:
	print "unrecognized command"
