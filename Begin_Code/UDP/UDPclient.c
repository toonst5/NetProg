#define _WIN32_WINNT 0x0501
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#define MSG_WAITALL 0xfff
#include <winsock2.h>
#include <ws2tcpip.h> 

#define PORT 24000 

#define MAXDATASIZE 1000 

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) 
	{
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
const char* inet_ntop(int af, const void* src, char* dst, int cnt)
{
    struct sockaddr_in srcaddr;
    memset(&srcaddr, 0, sizeof(struct sockaddr_in));
    memcpy(&(srcaddr.sin_addr), src, sizeof(srcaddr.sin_addr));
    srcaddr.sin_family = af;
    if (WSAAddressToString((struct sockaddr*) &srcaddr, sizeof(struct sockaddr_in), 0, dst, (LPDWORD) &cnt) != 0) 
	{
        DWORD rv = WSAGetLastError();
        printf("WSAAddressToString() : %d\n",rv);
        return NULL;
		
    }
    return dst;
}			
int main(int argc, char *argv[] )
{  char buffer[1000];
    int fd;		
	WSADATA wsaData;
	
		if (WSAStartup(MAKEWORD(2,0), &wsaData) != 0) 
		{
			fprintf(stderr, "WSAStartup failed.\n");
			exit(1);
		}
    if ( (fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
	{
        perror("socket failed");
        return 1;
    }

    struct sockaddr_in serveraddr;
	int len = sizeof (serveraddr);
    memset( &serveraddr, 0, sizeof(serveraddr) );
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons( PORT );              
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);

        if (sendto( fd, argv[2],strlen(argv[2]), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ) 
		{
            perror( "sendto failed" );
           
        }
		else{
        printf( "message sent\n" );
		}
		int counter = 0;
   for(int i = 0; i< atoi(argv[2]);i++)
   {
	   int length = 0;
	   length = recvfrom( fd, buffer, sizeof(buffer) - 1, 0 , (struct sockaddr *)&serveraddr, &len );
	    if ( length == 8 ) 
		{
		
            counter ++;   
        } 
			
   }
   printf("%i bytes recieved of %i bytes " ,counter ,(int)atoi(argv[2]) );
	WSACleanup();
    close( fd );
}