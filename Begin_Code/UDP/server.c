#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT 3490 // the port users will be connecting to

#define BACKLOG 10 // how many pending connections queue will hold
#define MAXDATASIZE 1000
int main( void )
{
    
   
    int fd;
    if ( (fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror( "socket failed" );
        return 1;
    }

    struct sockaddr_in serveraddr, si_other;
    int slen = sizeof(si_other);
    memset( &serveraddr, 0, sizeof(serveraddr) );
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons( PORT );
    serveraddr.sin_addr.s_addr = htonl( INADDR_ANY );

    if ( bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ) {
        perror( "bind failed" );
        return 1;
    }
    else
    {
    printf("connected to client");
    }
    struct sockaddr_in client_address;
	int client_address_len = 0;

    char buffer[1000];
    
        int length = recvfrom( fd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&si_other,&slen  );
        if ( length < 0 ) {
            perror( "recvfrom failed" );
            
        }
        else
        {
        printf("received: '%s' from client %s\n", buffer,
		       inet_ntoa(client_address.sin_addr));

        }
        
        buffer[length] = '\0';
        printf( "%d bytes: '%s'\n", length, buffer );
    	for ( int i = 0; i < atoi(buffer) ; i++ ) {
    	if (sendto( fd, "hello123", 8, 0, (struct sockaddr *)&si_other, sizeof(si_other)) < 0 ) {
            printf( "sendto failed" );
        }
        else{
        printf( "message sent\n" );
        printf("%i",atoi(buffer));
        }
      	}

    close( fd );
    }


