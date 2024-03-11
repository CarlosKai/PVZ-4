#include "enterscene.h"
#include "mainwindow.h"
#include "mypushbutton.h"
#include<QSound>
#include"help.h"

QSound *enterSound=new QSound(":/res/Grazy Dave.wav");

enterScene::enterScene(QWidget *parent) : QMainWindow(parent)
{
    //固定场景的大小
    this->setFixedSize(1350,900);
    enterSound->play();
    enterSound->setLoops(-1);

    //创建首页面的按钮
    MyPushButton *firstchoosebutton=new MyPushButton(":/res/start2.png",":/res/start1.png");
    firstchoosebutton->setParent(this);
    firstchoosebutton->move(this->width()*0.9-firstchoosebutton->width()*0.5,this->height()*0.60);
    MyPushButton *secondchoosebutton=new MyPushButton(":/res/save2.png",":/res/save1.png");
    secondchoosebutton->setParent(this);
    secondchoosebutton->move(this->width()*0.9-secondchoosebutton->width()*0.5,this->height()*0.70);
    MyPushButton *thirdchoosebutton=new MyPushButton(":/res/help2.png",":/res/help1.png");
    thirdchoosebutton->setParent(this);
    thirdchoosebutton->move(this->width()*0.9-thirdchoosebutton->width()*0.5,this->height()*0.80);
    MyPushButton *fourthchoosebutton=new MyPushButton(":/res/close2.png",":/res/close1.png");
    fourthchoosebutton->setParent(this);
    fourthchoosebutton->move(this->width()*0.9-fourthchoosebutton->width()*0.5,this->height()*0.90);

    game=NULL;

    connect(fourthchoosebutton,&MyPushButton::clicked,this,&enterScene::close);
    connect(firstchoosebutton,&MyPushButton::clicked,this,[=](){
        game=new MainWindow;
        game->setFixedSize(1350, 900);
        game->setWindowTitle("植物大战僵尸");
        game->show();
        this->hide();
        enterSound->stop();
    });
    connect(thirdchoosebutton,&MyPushButton::clicked,this,[=](){
        Help *help=new Help(this);
                help->show();

    });
    connect(secondchoosebutton,&MyPushButton::clicked,this,[=](){
           QString fileFull, fileName, filePath,fileSuffix;
           QFileInfo fileinfo;
           fileFull = QFileDialog::getOpenFileName(this,tr("file"),"/",tr("text(*.txt)"));
           string path=fileFull.toStdString();
           game=new MainWindow(path);
           game->setFixedSize(1350, 900);
           game->setWindowTitle("植物大战僵尸");
           game->show();
           this->hide();
           enterSound->stop();


    });
}
void enterScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //绘制背景
    pix.load(":/res/enter.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
