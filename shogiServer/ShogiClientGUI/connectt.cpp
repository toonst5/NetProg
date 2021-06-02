#include "connectt.h"
#include <QtCore>
#include <QDebug>
#include "connect.h"

Shogi::connectT::connectT()
{
    c = new class connect();
    c->make();
    c->reset();
}

void Shogi::connectT::run()
{
    if(not stop)
    {
        switch (stat)
        {
            case 0:
                c->send();
            break;
            case 1:
                c->get();
                emit MesRec();

            break;
            case 2:
                c->reset();
            break;
        }
        stop = true;
    }
}
