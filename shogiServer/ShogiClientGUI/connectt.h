#ifndef CONNECTT_H
#define CONNECTT_H

#include <QThread>

namespace Shogi
{
class connectT : public QThread
{
    Q_OBJECT
private:
    void run();
public:
    connectT();
};
}

#endif // CONNECTT_H
