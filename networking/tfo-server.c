#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv){
	int lfd = 0, cfd = 0, qlen = 10;
	struct sockaddr_in serv_addr; 

	/* Set up Listening File Descriptor */
	lfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));

	/* Set up IPv6 connection listening on port 54321 */
	serv_addr.sin_family = AF_INET6;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(54321); 

	/* Bind and configure TFO */
	bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
	setsockopt(lfd, SOL_TCP, TCP_FASTOPEN, &qlen, sizeof(qlen));

	/* Actually listen */
	listen(lfd, 10); 

	/* Accept connections, and then discard them */
	while(1){
		cfd = accept(lfd, (struct sockaddr*)NULL, NULL);
		write(cfd, "Socket opened!  Closing...\n", 256);
		close(cfd);
		sleep(1);
	}
	return 0;
}
