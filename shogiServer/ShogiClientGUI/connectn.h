#ifndef CONNECTN_H
#define CONNECTN_H

#include "nzmqt/global.hpp"
#include <zmq.hpp>
#include <QList>

namespace Shogi
{
class connectn
{
public:
    connectn();
    //nzmqt::ZMQContext *context; //Global context, because you only need one !
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
#endif // CONNECTN_H
