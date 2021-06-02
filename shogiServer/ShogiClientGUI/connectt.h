#ifndef CONNECTT_H
#define CONNECTT_H

#include <QThread>
#include <zmq.hpp>
#include <QList>

namespace Shogi
{
class connectT : public QThread
{
    Q_OBJECT
private:
public:
    connectT();
    void run();

    bool stop;
    int stat;
    class connect* c;

signals:
    void MesRec();
};
}

#endif // CONNECTT_H
