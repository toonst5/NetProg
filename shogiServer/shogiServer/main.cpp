#include <QCoreApplication>
#include "game.h"

int main( int argc, char * argv[] )
{
    Shogi::game* w = new Shogi::game();
    w->start();
    printf("done");
    return 0;
}
