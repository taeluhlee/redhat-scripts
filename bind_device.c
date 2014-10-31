#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <memory.h>

#define C_PORT 80
#define C_ADDR "192.168.2.2"
#define BIND_DEVICE "eth1"

int main(int argc, char **argv){
        int sock;
        struct sockaddr_in serv;

        sock = socket(PF_INET, SOCK_STREAM, 0);

        memset(&serv, '0', sizeof(serv));
        serv.sin_family = AF_INET;
        serv.sin_addr.s_addr = inet_addr(C_ADDR);
        serv.sin_port = htons(C_PORT);

        bind(sock, (struct sockaddr *)&serv, sizeof(struct sockaddr_in));
        if(!setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, BIND_DEVICE, sizeof(serv))){
                printf("socket option application successful with device %s.\n", BIND_DEVICE);
        }
        else{
                printf("socket option application failure with device %s.\n", BIND_DEVICE);
        }

        close(sock);
        return 0;
}
