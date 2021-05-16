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
        if(i<8)
        {
            s->buffer[i]=loca[i];
        }else if(i==8)
        {
             s->buffer[i]='[';
        }else if(i<199)
        {
            s->buffer[i]=(char)bufferi[i-9]+(char)'0';
        }else
        {
            s->buffer[i]=']';
        }
    }

    s->send();
    printf("send");

    s->reset();

    while(1)
    {
    s->get();

    for(int i=0;i<200;i++)
    {
        if(i<8)
        {
            s->buffer[i]=loca[i];
        }else if(i==8)
        {
             s->buffer[i]='[';
        }else if(i<199)
        {
            s->buffer[i]=(char)bufferi[i-9]+(char)'0';
        }else
        {
            s->buffer[i]=']';
        }
    }

    s->send();

    s->reset();

    }

    s->breake();
}
