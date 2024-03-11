#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QTimer>
#include "shop.h"
#include "card.h"
#include "shovel.h"
#include "button.h"
#include "map.h"
#include "mower.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"
#include"jackintheboxzombie.h"
#include"snowzombie.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(string path,QWidget *parent = nullptr);
    ~MainWindow() override;
    void addZombie();
    void check();
private:
    QSound *sound;
    QSound *begin;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Button *bt;
};

#endif // MAINWINDOW_H
