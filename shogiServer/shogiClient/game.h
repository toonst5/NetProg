#ifndef GAME_H
#define GAME_H

namespace Shogi
{
class game
{

private:
    //void drawPanel (int x, int y, int width, int hight, QColor color, double opacity);

    //QGraphicsTextItem* whosTurnText;

    char loca [20]="shogi>CL>";

    bool idR = false;

public:
    game(/*QWidget* parent=NULL*/);
    void displayMainMenu();

    void nextPlayersTurn();

    void start();


//public slots:
};
}

#endif // GAME_H
