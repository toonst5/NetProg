#include "connect.h"

Shogi::connect::connect()
{

}
/*
 * verbind met het bandernet
 * */
void Shogi::connect::make()
{
    this->context = zmq_ctx_new();

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
    printf("%s\n",buffer);
    zmq_send( pusher, buffer,500 , 0 );
    printf("%s\n",buffer);
}

/*
 * wacht op een reaksie van 1 van de spelers
 * */
void Shogi::connect::get()
{
    zmq_setsockopt(this->sub, ZMQ_SUBSCRIBE,"shogi>CL>", 9);
    //printf("waiting\n");
    zmq_recv (sub, buffer, 500, 0);

    printf("%s\n",buffer);
}

/*
 * reset de buffer
 * */
void Shogi::connect::reset()
{
    for(int i=0; i<500;i++)
    {
        buffer[i]=' ';
    }
}

/*
 * disconect met het banternet
 * */
void Shogi::connect::breake()
{
    zmq_close( sub);
    zmq_close( pusher );
    zmq_ctx_shutdown( context ); //optional for cleaning lady order (get ready you l*zy f*ck)
    zmq_ctx_term( context ); //cleaning lady goes to work
}
