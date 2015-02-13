#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

int main(int argc, char *argv[])
{
    int listener = 0, connection = 0;
    struct sockaddr_in serv_addr; 

    char sbuff[1025];
    time_t ticks; 

    listener = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sbuff, '0', sizeof(sbuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5001); 

    bind(listener, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listener, 10); 

    while(1)
    {
        connection = accept(listener, (struct sockaddr*)NULL, NULL);

        ticks = time(NULL);
        snprintf(sbuff, sizeof(sbuff), "%.24s\r\n", ctime(&ticks));
        write(connection, sbuff, strlen(sbuff)); 

       /* close(connection); */
        sleep(1);
     }
}
