#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "board.h"
#include <QMouseEvent>

namespace Shogi
{
class game: public QGraphicsView
{
    Q_OBJECT

private:
    void drawPanel (int x, int y, int width, int hight, QColor color, double opacity);
    void drawGUI();

    QString whosTurn_;
    QGraphicsTextItem* whosTurnText;
    char loca [20]="shogi>CL>";

    bool idR = false;

    class connect* c;
    class connectT* ct;

public:
    game(QWidget* parent=NULL);
    void displayMainMenu();
    void setWhosTurn(QString player);
    QGraphicsScene* scene;
    QString getWhosTurn();

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void pickUpCard(pion* card);
    void placeCard(pion* pionToReplace);
    void nextPlayersTurn();

    board* Board;
    pion* cardToPlace;
    QPointF originalPos;

public slots:
    void start();
    void MesRecU();
};
}

#endif // GAME_H
