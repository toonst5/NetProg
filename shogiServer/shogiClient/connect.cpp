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
    zmq_connect( pusher, "tcp://benternet.pxl-ea-ict.be:24041" );
    zmq_connect( sub, "tcp://benternet.pxl-ea-ict.be:24042" );

    this->reset();
}

void Shogi::connect::send()
{
    zmq_send( pusher, "test>[000000000000000000000000000PwPwPwPwPwPwPwPwPw0Kw00000Kw0HwHwHwHwHwHwHwHwHw000000000000000000000000000HbHbHbHbHbHbHbHbHb0Kb00000Kb0000000000000000000000000000PbPbPbPbPbPbPbPbPb]",183 , 0 );
}

void Shogi::connect::get()
{
    zmq_setsockopt(sub, ZMQ_SUBSCRIBE,"test>", 5);
    printf("waiting");
    zmq_recv (sub, buffer, 500, 0);

    printf("%s",buffer);
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
