#ifndef PLAYERS_H
#define PLAYERS_H

namespace Shogi
{
class Players
{
private:
    int id[8];
    bool white;
    int opId[8];
    int boardId;
public:
    Players();
    Players(int*, bool, int*, int);
    int* GetId(){return id;}
    void SetOpId(int* a);
    int* GetOpId(){return opId;}
    bool GetWhite(){return white;}
};
}

#endif // PLAYERS_H
