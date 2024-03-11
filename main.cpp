#include <QApplication>
#include "mainwindow.h"
#include"enterscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    enterScene w;
    w.setWindowTitle("植物大战僵尸");
    w.show();

//    MainWindow w;
//    w.setFixedSize(1350, 900);
//    w.setWindowTitle("植物大战僵尸");
//    w.show();
    return a.exec();
}
