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
    int t=0;
    printf("start");
    Shogi::connect* s = new Shogi::connect();
    s->make();
    //s->send();

    for(int i=0;i<10;i++)
    {
        s->buffer[i]=loca[i];
    }

    s->send();
    while(s->buffer[t] != '>')
    {
        t++;
    }
    t++;
    while(s->buffer[t] != '>')
    {
        t++;
    }
    t++;
    for(int i=0;i<8;i++)
    {
       loca[i+9]= s->buffer[i+t];
    }
    loca[17]='>';

    for(int i=0;i<8;i++)
    {
       s->loca[i+8]= s->buffer[i+t];
    }
    s->loca[16]='>';
    s->locaL=16;

    while(1)
    {
        s->reset();
        s->get();
    }
    s->breake();
}
