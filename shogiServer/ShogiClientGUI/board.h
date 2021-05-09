#ifndef BOARD_H
#define BOARD_H

#include <QList>
#include "pion.h"
#include "rect.h"
#include "space.h"
#include "kinggeneral.h"
#include "footsoldier.h"
#include "flyingchariot.h"
#include "connect.h"
#include "connectt.h"

namespace Shogi
{
class game;
class board
{
private:
    void creatPionColm(int x, int y, int numPionen, QString player, QString soort,int PionID);
    QList<pion*> Pionen;
    game* P;
    const unsigned char SHIFT=110;
    connect* c;

public:
    board();

    connect* getC(){return c;}

    board(game* W);

    ~board();

    void setConect(connect* C){c=C;}

    QList<pion*> getPionen();

    void placePionen(int x, int y/*, int cols, int rows*/);
    void replacePionen(int x, int y);
};
}

#endif // BOARD_H
