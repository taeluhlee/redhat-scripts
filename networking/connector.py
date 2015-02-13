#!/usr/bin/env python

# Robb Manes <rmanes@redhat.com>

import socket
import sys
import time

delay = 2		# seconds before connection terminaton or retrying connection
smsg = "Data sent!"	# data to be sent

##DEF##

def loop_client(host, port):

	while True:
		try:
			s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		except socket.error:
			print 'Socket creation failed! - ' \
			+ time.strftime("%Y-%m-%d %H:%M:%S")
			sys.exit();
		s.setblocking(0)
 
		try:
			remote_ip = socket.gethostbyname( host )
	 	except socket.gaierror:
			print 'Name resolution failure! - ' \
			+ time.strftime("%Y-%m-%d %H:%M:%S")
			sys.exit()

		try:
			s.connect((remote_ip , port))
			print 'Connection completed to ' + str(host) + ":" + str(port) \
			+ " - " +time.strftime("%Y-%m-%d %H:%M:%S") + '!'
		except socket.error:
			print 'ERROR: Connection failure! ' \
			+ time.strftime("%Y-%m-%d %H:%M:%S")
			sys.exit()
		
		try:
			s.sendall(smsg)
		except socket.error:
    			print 'Sending data failed! - ' \
			+ time.strftime("%Y-%m-%d %H:%M:%S")
			sys.exit()
		time.sleep(delay)
		s.close
		
		
def op_server(host, port):

	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 
	try:
		s.bind((host, port))
	except socket.error , msg:
		print 'Socket creation failed!' \
		+ " - " +time.strftime("%Y-%m-%d %H:%M:%S") + '!'
		sys.exit()
 
	s.listen(10)
 
	while 1:
		conn, addr = s.accept()
		print 'Connected from ' + addr[0] + ':' + str(addr[1]) + " - " \
		+ time.strftime("%Y-%m-%d %H:%M:%S")
     		data = conn.recv(1024)
		reply = 'RECEIVED!'
		if not data:
			break
     		conn.sendall(reply)
		time.sleep(delay + 1) 
		conn.close()
	s.close()

def help():
	print '\nconntest_rhos.py:\n\tTo start in Server mode:\n' + \
	'\t\t./conntest_rhos.py server <LOCAL IP> <PORT>\n\n' + \
	'\tTo start in Client mode:\n' + \
	'\t\t./conntest_rhos.py client <FOREIGN IP> <PORT>'

##START##

# handle arguments
if len(sys.argv) == 1:
	help()
	sys.exit()

host = sys.argv[2]
port = sys.argv[3]

if sys.argv[1] == 'server':
	op_server(host, int(port))
elif sys.argv[1] == 'client':
	loop_client(host, int(port))
else:
	help()
