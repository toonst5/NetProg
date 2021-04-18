#include "mainwindow.h"

#include <QApplication>
#include <zmq.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void * context; //Global context, because you only need one !

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    return a.exec();
}
