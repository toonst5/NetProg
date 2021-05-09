#include "game.h"
#include "board.h"
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

    while(s->bufferi[0]!=0&&s->bufferi[1]!=0&&s->bufferi[2]!=0&&s->bufferi[3]!=0)
    {
        s->get();

    }

    for(int i=0;i<200;i++)
    {
        if(i<6)
        {
            s->buffer[i]=loca[i];
        }else
        {
            s->buffer[i]=(char)bufferi[i-6]+(char)'0';
        }
    }

    s->send();
    printf("send");

    s->reset();

    s->get();

    for(int t=0;t<200;t++)
    {
        if(t<6)
        {
            s->buffer[t]=loca[t];
        }else
        {
            s->buffer[t]=(char)bufferi[t-5]+(char)'0';
        }
    }
    s->buffer[200]=']';

    s->send();

    s->reset();

    s->breake();
}
