import os
import serial
import string



lista = []
lista = os.listdir('/dev/')

serial_ls =[]

for item in lista:
    a = item[0:3]
    if a == "tty":
        serial_ls.append(item)
    else:
        pass

#print lista



#print serial_ls

def scan():
    """scan for available ports. return a list of tuples (num, name)"""
    available = []
    for item in serial_ls:
        try:
            s = serial.Serial("/dev/"+item)
            available.append(s.portstr)
            s.close()   
        except serial.SerialException:
            pass
    return available
    
print scan()

a = len(scan())

print "\n O tamanho da lista e'="+ str(a) + "\n"
