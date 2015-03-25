#!/usr/bin/env python

import socket
import sys
from time import sleep

def startClient(server, port):
    msg = "ClIENT CONNECTED."
    try:
        sock = socket.create_connection((server, port))
    except:
        print "Unable to connect to socket on " + str(server) + \
              " " + str(port)

def startServer(address, port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except:
        print "Unable to create socket"
        sys.exit(1)
    server = (address, port)
    sock.bind(server)
    sock.listen(1)

    while True:
        try:
            conn, addr = sock.accept()
            print "Connection from " + str(addr)
	    print "Closing connection from server."
	    conn.close()
        except:
            print "Terminating program"
	    sys.exit(0)

def main():
    try:
         mode = sys.argv[1]
    except IndexError:
         print "Not enough arguments."
         sys.exit(1)
    if mode == "server":
        port = sys.argv[2]
        print "Starting server, listening on port " + str(port) + "."
        startServer('', int(port))
    elif mode == "client":
        addr = sys.argv[2]
        port = sys.argv[3]
        attempts = int(sys.argv[4])
	tries = 1
        print "Starting client, connecting to " + str(addr) + " port " + str(port) + \
              " attempting " + str(attempts) + " times."
        while tries != (attempts + 1):
            startClient(addr, port)
	    print "Connected to server, attempt " + str(tries) + "."
            tries += 1
        print "Run complete; holding sockets in TIME_WAIT state until client exits with Cntrl-C."
        while True:
            try:
                sleep(10)
            except KeyboardInterrupt:
                print "lient terminating on Cntrl-C."
                sys.exit(0)
    else:
        print "Invalid mode - please pass either 'server' or 'client' as first argument."
        return 1

if __name__ == "__main__":
    sys.exit(main())
