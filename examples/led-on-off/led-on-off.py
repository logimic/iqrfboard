#!/opt/bin/python

import serial, string

ser = serial.Serial(
    port='COM11',
    baudrate=57600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

#ser.write(bytes.fromhex('0001 06 01 FFFF'))
# 1 on
ser.write(serial.to_bytes([0x00, 0x00, 0x06, 0x81, 0x00,0x00,0x00])) 

#ser.write(serial.to_bytes([0x01, 0x00, 0x06, 0x80, 0x00,0x00,0x00, 0x76])) 

ser.close()