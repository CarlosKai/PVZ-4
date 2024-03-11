#ifndef HELP_H
#define HELP_H

#include <QMainWindow>

class Help : public QMainWindow
{
    Q_OBJECT
public:
    explicit Help(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:

public slots:
};

#endif // HELP_H
