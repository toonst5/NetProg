
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include "windows.h"

#define PORT "24000" 

#define MAXDATASIZE 100  
#define MAXNAMESIZE 25

DWORD WINAPI receive_handler(void *);


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

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) 
	{
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
    char message[MAXDATASIZE];
    char nickName[MAXNAMESIZE];
    int sockfd;
    char sBuf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    if (argc != 2) 
	{
        fprintf(stderr,"usage: client hostname\n");
        exit(1);
    }
WSADATA wsaData;

if (WSAStartup(MAKEWORD(2,0), &wsaData) != 0) 
{
    fprintf(stderr, "WSAStartup failed.\n");
    exit(1);
}

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) 
	{
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for(p = servinfo; p != NULL; p = p->ai_next) 
	{
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) 
		{
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) 
		{
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    if (p == NULL) 
	{
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);

    freeaddrinfo(servinfo);
       
    puts("Nickname:");
    memset(&nickName, sizeof(nickName), 0);
    memset(&message, sizeof(message), 0);
    fgets(nickName, MAXNAMESIZE, stdin);
    
    
    HANDLE thread = CreateThread(NULL, 0, receive_handler, NULL, 0, NULL);
    puts("Synchronous receive handler assigned");
    
    puts("Connected\n");
    puts("[Type '/quit' to quit]");

    for(;;)
	{
		char temp[6];
		memset(&temp, sizeof(temp), 0);

        memset(&sBuf, sizeof(sBuf), 0);
        fgets(sBuf, 100, stdin);

		if(sBuf[0] == '/' &&
		   sBuf[1] == 'q' &&
		   sBuf[2] == 'u' &&
		   sBuf[3] == 'i' &&
		   sBuf[4] == 't')
			return 1;
		
			
		int count = 0;
        while(count < strlen(nickName))
        {
            message[count] = nickName[count];
            count++;
        }
        count--;
        message[count] = ':';
        count++;
        for(int i = 0; i < strlen(sBuf); i++)
        {
            message[count] = sBuf[i];
            count++;
        }
        message[count] = '\0';
        if(send(sockfd, message, strlen(message), 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        memset(&sBuf, sizeof(sBuf), 0);
        
    }
    
    WSACleanup();
    close(sockfd);

    return 0;
}

DWORD WINAPI receive_handler(void *sock_fd)
{
	int sFd = (intptr_t) sock_fd;
    char buffer[MAXDATASIZE];
    int nBytes;
    
    for(;;)
    {
        if ((nBytes = recv(sFd, buffer, MAXDATASIZE-1, 0)) == -1)
        {
            perror("recv");
            return 0 ;
        }
        else
            buffer[nBytes] = '\0';
        printf("%s", buffer);
    }
}