#include "game.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QDebug>

Shogi::game::game(QWidget *parent)
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setFixedSize(1900,1200);
    setFixedSize(1920,1080);

    //set up scene
    scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,1900,1200);
    scene->setSceneRect(0,0,1920,1080);
    setScene(scene);

    cardToPlace = nullptr;
}

void Shogi::game::start()
{
    char send[10]="[0000]";
    scene->clear();

    c = new class connect();
    c->make();

    /*ct = new connectT();
    ct->start();
    ct->wait();*/

    for(int i=0;i<16;i++)
    {
        if(i<10)
        {
            c->buffer[i]=loca[i];
        }else
        {
            c->buffer[i]=send[i-10];
        }
    }

    c->send();

    c->reset();

    drawGUI();
    Board = new board(this);
    Board->setConect(c);
    c->get();
    Board->placePionen(0,20/*,9,9*/);
}

void Shogi::game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("shogi"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}


void Shogi::game::drawPanel(int x, int y, int width, int hight, QColor color, double opacity)
{
    QGraphicsRectItem* panal = new QGraphicsRectItem(x,y,width,hight);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panal->setBrush(brush);
    panal->setOpacity(opacity);
    scene->addItem(panal);
}

void Shogi::game::drawGUI()
{
   drawPanel(10,20,330,900,Qt::darkCyan,1);

   drawPanel(1550,100,330,900,Qt::darkCyan,1);

   QGraphicsTextItem* p1= new QGraphicsTextItem("player 1's pieces: ");
   p1->setPos(25,0);
   scene->addItem(p1);

   QGraphicsTextItem* p2= new QGraphicsTextItem("player 2's pieces: ");
   p2->setPos(1740+25,0);
   scene->addItem(p2);

   whosTurnText = new QGraphicsTextItem();
   setWhosTurn(QString("PLAYER1"));
   whosTurnText->setPos(850,0);
   scene->addItem(whosTurnText);
}

QString Shogi::game::getWhosTurn()
{
    return whosTurn_;
}

void Shogi::game::setWhosTurn(QString player)
{
    whosTurn_ = player;
    whosTurnText->setPlainText(QString("Whos Turn: ")+player);
}

void Shogi::game::mouseMoveEvent(QMouseEvent* event)
{
    if(cardToPlace)
    {
        cardToPlace->setPos(event->pos());
        cardToPlace->setXText(event->x()+25);
        cardToPlace->setYText(event->y()+30);
        cardToPlace->rePos();
    }

    QGraphicsView::mouseMoveEvent(event);
}

void Shogi::game::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::RightButton)
    {
        if(cardToPlace)
        {
            cardToPlace->setPos(originalPos);
            cardToPlace->setXText(originalPos.x()+25);
            cardToPlace->setYText(originalPos.y()+30);
            cardToPlace->rePos();
            cardToPlace = nullptr;
        }
    }
}

void Shogi::game::pickUpCard(pion *card)
{
    if(card->getOwner()==getWhosTurn() && cardToPlace==nullptr)
    {
        cardToPlace=card;
        originalPos=card->pos();
        cardToPlace->setXText(card->x()+25);
        cardToPlace->setYText(card->y()+30);
        cardToPlace->rePos();
    }
}

void Shogi::game::placeCard(pion *pionToReplace)
{
    int i = 0;
    cardToPlace->setPos(pionToReplace->pos());
    cardToPlace->setXText(pionToReplace->x()+25);
    cardToPlace->setYText(pionToReplace->y()+30);
    cardToPlace->rePos();

    if(cardToPlace->getYard()&&cardToPlace->getOwner()==QString("PLAYER1"))
    {
        pionToReplace->setPos(originalPos);
        pionToReplace->setPionID(9);
        pionToReplace->setOwner(QString("GRAVE"));

        cardToPlace->setYard(false);
    }else if(cardToPlace->getYard()&&cardToPlace->getOwner()==QString("PLAYER2"))
    {
        pionToReplace->setPos(originalPos);
        pionToReplace->setPionID(9);
        pionToReplace->setOwner(QString("GRAVE"));

        cardToPlace->setYard(false);
    }else if((pionToReplace->getOwner()==QString("PLAYER2")&&cardToPlace->getOwner()==QString("PLAYER1")))
    {
        pionToReplace->setOwner(QString("PLAYER1"));
        pionToReplace->setPionID(pionToReplace->getPionID()+3);
        pionToReplace->setYard(true);
        while(i<40&&Board->getPionen()[i]->getPionID()!=0)
        {
            i++;
        }
        cardToPlace->setPos(pionToReplace->pos());
        originalPos=pionToReplace->pos();
        pionToReplace->setPos(Board->getPionen()[i]->pos());
        Board->getPionen()[i]->setPos(originalPos);
        Board->getPionen()[i]->setPionID(9);
    }else if((pionToReplace->getOwner()==QString("PLAYER1")&&cardToPlace->getOwner()==QString("PLAYER2")))
    {
        pionToReplace->setOwner(QString("PLAYER2"));
        pionToReplace->setPionID(pionToReplace->getPionID()-3);
        pionToReplace->setYard(true);
        i=122;
        while(i<162&&Board->getPionen()[i]->getPionID()!=0)
        {
            i++;
        }
        cardToPlace->setPos(pionToReplace->pos());
        originalPos=pionToReplace->pos();
        pionToReplace->setPos(Board->getPionen()[i]->pos());
        Board->getPionen()[i]->setPos(originalPos);
        Board->getPionen()[i]->setPionID(9);
    }else
    {
        pionToReplace->setPos(originalPos);
    }
    pionToReplace->setXText(pionToReplace->x()+25);
    pionToReplace->setYText(pionToReplace->y()+30);
    pionToReplace->rePos();

    cardToPlace = nullptr;



    c->reset();

    Board->replacePionen(0,17);

    for(int i=0;i<200;i++)
    {
        if(i<10)
        {
            c->buffer[i]=loca[i];
        }else if(i==10)
        {
            c->buffer[i]='[';
        }else if(i<199)
        {
            c->buffer[i]=(char)c->bufferi[i-11]+(char)'0';
        }else
        {
            c->buffer[i]=']';
        }
    }


    c->send();

    nextPlayersTurn();

    c->reset();
    c->get();

    Board->placePionen(0,20);

}


void Shogi::game::nextPlayersTurn()
{
    if(getWhosTurn()==QString("PLAYER1"))
    {
        setWhosTurn(QString("PLAYER2"));
    }else
    {
        setWhosTurn(QString("PLAYER1"));
    }
}





