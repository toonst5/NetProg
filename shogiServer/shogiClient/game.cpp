#include "game.h"
#include "connect.h"
//#include "button.h"
//#include <QGraphicsTextItem>
#include <QDebug>

Shogi::game::game()
{

}

void Shogi::game::start()
{
    printf("start");
    Shogi::connect* s = new Shogi::connect();
    s->make();
    //s->send();
    s->get();
    s->reset();
    s->get();
    s->breake();
}
