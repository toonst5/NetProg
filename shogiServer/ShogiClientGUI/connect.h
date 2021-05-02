#ifndef CONNECT_H
#define CONNECT_H

#include <zmq.hpp>
#include <QList>

namespace Shogi
{
class connect
{
public:
    connect();
    void * context; //Global context, because you only need one !
    void *sub;
    void *pusher;
    char buffer [500];
    int bufferi [200];
    void make();
    void breake();
    void send();
    void get();
    void reset();
};
}
#endif // CONNECT_H
