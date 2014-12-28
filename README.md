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

And you should see output similar to the below if SCTP namespace support is enabled on your kernel:
```
SCTP socket was created successfully.
```

or this, if it is not:

```
Socket allocation failed!
```

###### bind_device
Creates a socket on an interface, built for testing sockets on aliased interfaces.  To compile, simply run:

```
# gcc -o sctp_namespace sctp_namespace.c
# sudo ./bind_device
```

Depending on whether or not the socket could be successfully bound to the device is evident by the one of these two outputs:

```
socket option application successful with device <DEVICE>.
socket option application failure with device <DEVICE>.
```
###### memget
Allocates memory, then sleeps.

```
# gcc -o memget memget.c
# ./memget
```
###### reset_server.py
Configured a simple server that can only respond with a RST packet due to SO_LINGER options.

###### connector.py

###### conn.py

###### dumbsock

###### segfault
