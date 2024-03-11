#ifndef ENTERSCENE_H
#define ENTERSCENE_H
#include"mainwindow.h"
#include <QMainWindow>
#include<QObject>
#include<dialog.h>
#include<QFile>
class enterScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit enterScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    MainWindow *game;
    Dialog *dialog;
signals:

public slots:
};

#endif // ENTERSCENE_H
