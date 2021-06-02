#ifndef GAME_H
#define GAME_H

namespace Shogi
{
class game
{

private:
    //void drawPanel (int x, int y, int width, int hight, QColor color, double opacity);
    void drawGUI();
    void createInitialCards();

    //QGraphicsTextItem* whosTurnText;

public:
    game(/*QWidget* parent=NULL*/);
    void displayMainMenu();
    //QGraphicsScene* scene;

    //void mouseMoveEvent(QMouseEvent* event);
    //void mousePressEvent(QMouseEvent* event);
    void nextPlayersTurn();

    //QPointF originalPos;
    void start();


//public slots:
};
}

#endif // GAME_H
