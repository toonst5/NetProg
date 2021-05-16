#include "connect.h"

Shogi::connect::connect()
{

}

void Shogi::connect::make()
{
    this->context = zmq_ctx_new();
    char buffer [500];

    this->sub = zmq_socket (context, ZMQ_SUB);
    this->pusher = zmq_socket( context, ZMQ_PUSH );
    zmq_connect( pusher, "tcp://benternet.backup.pxl-ea-ict.be:24041" );
    zmq_connect( sub, "tcp://benternet.backup.pxl-ea-ict.be:24042" );

    this->reset();
}

/*
    0:NOONE NON
    1: PLAYER PION
    2: PLAYER KNIGHT
 */
void Shogi::connect::send()
{
    zmq_send( pusher, buffer,300 , 0 );
}

void Shogi::connect::get()
{
    int i = 0;
    int t = 0;
    int v = 0;
    zmq_setsockopt(this->sub, ZMQ_SUBSCRIBE,"shogi>CL>", 9);
    printf("waiting");
    zmq_recv (sub, buffer, 500, 0);

    printf("%s",buffer);
    printf("done");

    while(buffer[i] != '[')
    {
        i++;
    }
    i++;
    while(buffer[i] != ']')
    {
        v= (int)buffer[i]-(int)'0';
        bufferi[t]=v;
        t++;
        i++;
    }
    printf("done");
}

void Shogi::connect::reset()
{
    for(int i; i<500;i++)
    {
        buffer[i]=' ';
    }
}

void Shogi::connect::breake()
{
    zmq_close( sub);
    zmq_close( pusher );
    zmq_ctx_shutdown( context ); //optional for cleaning lady order (get ready you l*zy f*ck)
    zmq_ctx_term( context ); //cleaning lady goes to work
}
