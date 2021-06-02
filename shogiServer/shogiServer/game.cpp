#include "game.h"
//#include "button.h"
//#include <QGraphicsTextItem>
#include <QDebug>

Shogi::game::game()
{

}

void Shogi::game::start()
{
    int i = 0;
    int t = 0;

    printf("start\n");
    s = new Shogi::connect();
    s->make();

    while(1)
    {
       s->get();

       while(s->buffer[i] != '>')
        {
            i++;
        }
        i++;
        while(s->buffer[i] != '>')
        {
            i++;
        }
        i++;
        t=i;
        while(s->buffer[i]!=']' && newPlay == true)
        {
            if(s->buffer[i]=='>')
            {
                for(int i=0;i<8;i++)
                {
                   Cid[i]= s->buffer[i+t];
                }
                Prog();
                newPlay=false;
            }
            i++;
        }
        if(newPlay)
        {
           newPlayer();
        }else
        {
            newPlay= true;
        }
        i=0;
        t=0;
    }
}

void Shogi::game::newPlayer()
{
    for(int y=0;y<8;y++)
    {
        idL[y]=idL[y]+1;
        if(idL[y]>9)
        {
            idL[y]=0;
        }else
        {
            break;
        }
    }
    bool white;
    int idO[8];
    if(waiting == NULL)
    {
        white = true;
        for(int i = 0;i<8;i++)
        {
            idO[i] = 0;
        }
        idLB = idLB + 1;
    }else
    {
        white = false;
        for(int i = 0;i<8;i++)
        {
            idO[i] = waiting->GetId()[i];
        }
        waiting->SetOpId(idL);
        waiting = NULL;
    }
    Players* p = new Players(idL,white,idO,idLB);
    if(waiting == NULL)
    {
        waiting=p;
    }
    Plays.append(p);

    for(int i=0;i<200;i++)
    {
        if(i<8)
        {
            s->buffer[i]=loca[i];
        }else if(i<16)
        {
            s->buffer[i]=(char)idL[i-8]+(char)'0';
        }else if(i==16)
        {
            s->buffer[i]='>';
        }else if(i==17)
        {
            s->buffer[i]='[';
        }else if(i<198)
        {
            s->buffer[i]=(char)bufferiS[i-18]+(char)'0';
        }else if(i<199)
        {
            s->buffer[i]=']';
        }else
        {
            if(p->GetWhite())
            {
                s->buffer[i]='0';
            }
            if(p->GetWhite())
            {
                s->buffer[i]='1';
            }
        }

    }

    s->send();
    s->reset();
}

void Shogi::game::Prog()
{
    Convert();
    for(int i=0;i<200;i++)
        {
            if(i<8)
            {
                s->buffer[i]=loca[i];
            }else if(i<16)
            {
                 s->buffer[i]=Cid[i-8];
            }else if(i==16)
            {
                 s->buffer[i]='>';
            }else if(i==17)
            {
                 s->buffer[i]='[';
            }else if(i<198)
            {
                s->buffer[i]=(char)bufferi[i-18]+(char)'0';
            }else if(i<199)
            {
                s->buffer[i]=']';
            }else
            {
                if(1)
                {
                    s->buffer[i]='0';
                }
                if(0)
                {
                    s->buffer[i]='1';
                }
            }
        }

        s->send();

        s->reset();
}

void Shogi::game::Convert()
{
    int i = 0;
    int t = 0;
    int v = 0;
    while(s->buffer[i] != '[')
    {
        i++;
    }
    i++;
    while(s->buffer[i] != ']')
    {
        v= (int)s->buffer[i]-(int)'0';
        bufferi[t]=v;
        t++;
        i++;
    }
}
