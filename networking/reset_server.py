#!/usr/bin/env python

import socket
import sys
import time
import struct

HOST = ''
PORT = 1119
 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
l_onoff = 1 
l_linger = 0 
s.setsockopt(socket.SOL_SOCKET, socket.SO_LINGER, struct.pack('ii', l_onoff, l_linger))

try:
	s.bind((HOST, PORT))
except socket.error , msg:
	print("Bind failed\n")
	sys.exit()
 
s.listen(10)
print("Server is now listening on port " + str(PORT) + "...")
 
conn, addr = s.accept()
print 'Connected with ' + addr[0] + ':' + str(addr[1]) + " at " + time.strftime("%H:%M:%S")
	
conn.close()
s.close()
