#ifndef GAME_H
#define GAME_H

#include <QList>
#include "players.h"
#include "connect.h"

namespace Shogi
{
class game
{

private:

public:
    game(/*QWidget* parent=NULL*/);
    void displayMainMenu();
    void setWhosTurn(QString player);

    void start();
    void newPlayer();
    void Prog();
    void Convert();

    int bufferiS [200]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,9,2,9,9,9,9,9,2,9,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,4,4,4,4,4,4,4,4,4,9,5,9,9,9,9,9,5,9,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8};
    char loca [10]="shogi>S>";

    bool newPlay = true;
    int idL[8]={0,0,0,0,0,0,0,0};
    int idLB = 0;

    int Cid[8]={0,0,0,0,0,0,0,0};

    Players* waiting = NULL;

    QList<Players*> Plays;
    int bufferi [200];

    connect* s;

//public slots:
};
}

#endif // GAME_H
