#!/usr/bin/env python
# rhn_checker.py
# For testing communication to Red Hat Network and Red Hat Subscription Manager services
# when netcat and telnet are unavailable.
# Authored by Robb Manes <rmanes@redhat.com>

import sys
import socket

# The check of a TCP handshake should be enough to determine if we have connectivity.
# No need to exchange data.

# Check port 80
try:
	error = 0
	httpSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	httpSock.connect(('xmlrpc.rhn.redhat.com', 80))
	httpSock.close()
	print '\tSuccessful connection on port 80 to xmlrpc.rhn.redhat.com.'
except socket.error, (value, message):
	if httpSock:
		httpSock.close()
		print '\tConnection on server port 80 to xmlrpc.rhn.redhat.com failed!'
		error += 1

# Check port 443
try:
	httpsSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	httpsSock.connect(('xmlrpc.rhn.redhat.com', 443))
	httpsSock.close()
	print '\tSuccessful connection on port 443 to xmlrpc.rhn.redhat.com.'
except socket.error, (value, message):
        if httpsSock:
                httpsSock.close()
                print '\tConnection on server port 80 to xmlrpc.rhn.redhat.com failed!'
		error += 1
if(error):
	print '\tPlease check your firewall as well as any proxies you may have.'
