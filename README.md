# jping
Personal implementation of 'ping' for Linux

Take a hostname as input
Do a DNS lookup
DNS lookup can be done using gethostbyname(). The gethostbyname() function converts a normal human readable website and returns a structure of type hostent which contains IP address in form of binary dot notation and also address type.

Some ping programs like the one given with ubuntu support reverse DNS lookup.
Reverse DNS lookup is performed using getnameinfo(), and it converts dot notation IP address to hostname.
for example, the pinging of google.com frequently gives a strange address:
bom07s18-in-f14.1e100.net

This is as a result of a reverse DNS lookup.

Open a Raw socket using SOCK_RAW with protocol as IPPROTO_ICMP.
Note: raw socket requires superuser rights so you have to run this code using sudo
When crtl + C is pressed, ping gives a report. This interrupt is caught by an interrupt handler
which just sets our pinging looping condition to false.
Here comes the main ping sending loop.
We have to:
Set the ttl option to a value in the socket
TTL value is set to limit the number of hops a packet can make.
Set the timeout of the recv function
If timeout is not set, recv will wait forever, halting the loop.
Fill up the icmp packet
As follows:
Set packet header type to ICMP_ECHO.
Set id to pid of process
Fill msg part randomly.
Calculate checksum and fill it in checksum field.
Send the packet
Wait for it to be received.
The main problem here is that the packet received does not mean that that the destination is working.
Echo reply means destination is OK. Echo reply is sent from destination OS kernel.
This is the list of all types and codes.
A issue here is that the program shows type 69 and code 0 if all goes correct instead of 0 which stands for echo_reply.
