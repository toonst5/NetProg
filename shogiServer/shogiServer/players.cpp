#include "players.h"

Shogi::Players::Players()
{

}

Shogi::Players::Players(int* a, bool b, int* c, int d)
{
    for(int i = 0;i<8;i++)
    {
        id[i] = a[i];
    }
    white = b;
    for(int i = 0;i<8;i++)
    {
        opId[i] = c[i];
    }
    boardId = d;
}

void Shogi::Players::SetOpId(int *a)
{
    for(int i = 0;i<8;i++)
    {
        id[i] = a[i];
    }
}
