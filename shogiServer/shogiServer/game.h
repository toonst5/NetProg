#ifndef GAME_H
#define GAME_H

#include "board.h"

namespace Shogi
{
class game
{

private:
    void createInitialCards();

    QString whosTurn_;

    QList<pion*> GRAVE1;
    QList<pion*> GRAVE2;

public:
    game(/*QWidget* parent=NULL*/);
    void displayMainMenu();
    void setWhosTurn(QString player);
    //QGraphicsScene* scene;
    QString getWhosTurn();

    //void mouseMoveEvent(QMouseEvent* event);
    //void mousePressEvent(QMouseEvent* event);
    void pickUpCard(pion* card);
    void placeCard(pion* pionToReplace);
    void nextPlayersTurn();

    board* Board;
    pion* cardToPlace;
    //QPointF originalPos;
    void start();

    int bufferi [200]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,9,2,9,9,9,9,9,2,9,3,3,3,3,3,3,3,3,3,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,4,4,4,4,4,4,4,4,4,9,5,9,9,9,9,9,5,9,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8};
    char loca [10]="shogi>";

//public slots:
};
}

#endif // GAME_H
