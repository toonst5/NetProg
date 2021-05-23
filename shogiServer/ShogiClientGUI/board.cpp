#include "board.h"
#include "game.h"

Shogi::board::board()
{

}

Shogi::board::board(game* W)
{
    this->P=W;
}

Shogi::board::~board()
{

}


QList<Shogi::pion *> Shogi::board::getPionen()
{
    return Pionen;
}

void Shogi::board::placePionen(int x, int y/*, int cols, int rows*/)
{
    int i = 0;
    double xt=0;
    int yt=0;

    while(Pionen.count()>1)
    {
    Pionen.last()->~pion();
    Pionen.removeLast();
    }

    while(c->bufferi[i] != 8)
    {
        if(i < 40)
        {
            if(xt>2.5)
            {
                xt=0;
                yt++;
            }
        }else if(i<121)
        {
            if(xt>12)
            {
                xt=4;
                yt++;
            }
        }else
        {
            if(xt>17)
            {
                xt=14.5;
                yt++;
            }
        }

        if(i==40)
        {
            yt=0;
            xt=4;
        }else if(i==121)
        {
            yt=1;
            xt=14.5;
        }

        if(c->bufferi[i] == 0)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("NOONE"),QString("GRAVE"),0);
        }else if(c->bufferi[i] == 1)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER2"),QString("PION"),1);
        }else if(c->bufferi[i] == 2)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER2"),QString("KING"),2);
        }else if(c->bufferi[i] == 3)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER2"),QString("ROOK"),3);
        }else if(c->bufferi[i] == 4)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER1"),QString("PION"),4);
        }else if(c->bufferi[i] == 5)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER1"),QString("KING"),5);
        }else if(c->bufferi[i] == 6)
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("PLAYER1"),QString("ROOK"),6);
        }else
        {
            creatPionColm(x+xt*SHIFT,y+yt*SHIFT,1,QString("NOONE"),QString("NON"),9);
        }
        i++;
        xt++;
    }

}

void Shogi::board::replacePionen(int x, int y)
{

    int xp=0;
    int yp=0;
    int pp=0;

    for(int i=0;i<161;i++)
    {
        xp = Pionen[i]->x();
        yp = Pionen[i]->y();

        if(xp<(3.2*SHIFT))
        {
            pp=((xp-x-17)/SHIFT+0)+(((yp-y)/SHIFT)*3);
        }else if(xp<13*SHIFT)
        {
            pp=((xp-x-17)/SHIFT-4)+(((yp-y)/SHIFT)*9)+40;
        }else
        {
            pp=((xp-x)/SHIFT-14.5)+(((yp-y)/SHIFT)*3)+119;
        }

        c->bufferi[pp]=Pionen[i]->getPionID();

        pp = 0;
    }

}

void Shogi::board::creatPionColm(int x, int y, int numPionen, QString player, QString soort, int PionID)
{
    for(size_t i=0; i<numPionen; i++)
    {
        rect* Rect = new rect();
        Rect->setPos(x+110*i,y);
        P->scene->addItem(Rect);

        pion* Pion=nullptr;
        if(soort == QString("PION"))
        {
            Pion = new FootSoldier();
        }else if(soort == QString("KING"))
        {
            Pion = new kingGeneral();
        }else if(soort == QString("ROOK"))
        {
            Pion = new flyingChariot();
        }else
        {
            Pion = new space();
        }

        Pion->setPointer(P);
        Pion->setPos(x+110*i+17.5,y+15);
        Pionen.append(Pion);
        Pion->setIsPlaced(true);

        if(soort == QString("PION"))
        {
            Pion->draw(QString("歩\n兵"));
        }else if(soort == QString("KING"))
        {
            Pion->draw(QString("王\n將"));
        }else if(soort == QString("ROOK"))
        {
            Pion->draw(QString("飛\n車"));
        }else if(soort == QString("GRAVE"))
        {
            Pion->draw(QString("G"));
        }else
        {
            Pion->draw(QString(""));
        }
        Pion->setPionID(PionID);
        Pion->setOwner(player);
    }
}
