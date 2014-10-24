redhat-scripts
==============

Scripts/Code I've written concerning Red Hat systems.

###### rhn_checker.py:
For testing communication to Red Hat Network and Red Hat Subscription Manager services when netcat and telnet are unavailable.
```
# ./rhn_checker.py 
	Successful connection on port 80 to xmlrpc.rhn.redhat.com.
	Successful connection on port 443 to xmlrpc.rhn.redhat.com.
```

###### sctp_namespace
Creates an SCTP socket on a namespace for testing purposes.  To compile, simply run:
```
# gcc -o sctp_namespace sctp_namespace.c
# sudo ./sctp_namespace
```
