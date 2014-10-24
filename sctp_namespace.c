/*
 *  sctp_namespace - Creates an SCTP socket on a namespace for testing purposes,
 *  Author: Robb Manes <rmanes@redhat.com>
 *  
 */

#include <stdio.h> 
#include <stdlib.h>
#include <linux/sched.h>
#include <sys/mount.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/sctp.h>

#define SERVER 1

void create_ns(const char *name)
{
        char path[100];

        snprintf(path, sizeof(path), "%s/%s", "/var/run/netns", name);
        close(open(path, O_RDONLY|O_CREAT|O_EXCL, 0));
        unshare(CLONE_NEWNET);
        mount("/proc/self/ns/net", path, "none", MS_BIND , NULL);
}

int create_sctp_sock(){
        int lfd, connfd;
        struct sockaddr_in saddr;

        lfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(9999);
        saddr.sin_addr.s_addr = INADDR_ANY;
        if(!bind(lfd, (struct sockaddr*)&saddr, sizeof (saddr))){
                printf("SCTP socket was created successfully.\n");
        }
        else{
                printf("Socket allocation failed!\n");
        }
}

int  main() {
        if(SERVER){
                create_ns("namespace001");
                printf("Namespace created, configuring interfaces:\n");
                system("ip link add veth0 type veth peer name veth1");
                system("ip a s");
                create_sctp_sock();
    
                while(1){
                        sleep(20);
                }
        }
}
