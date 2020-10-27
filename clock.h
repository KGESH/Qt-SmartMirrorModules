#ifndef CLOCK_H
#define CLOCK_H

#include "mainwindow.h"
#include <QObject>

class Clock : public QObject
{
    Q_OBJECT

public:
    Clock(QObject *parent = 0);


public slots:
    QString SetTime() const;
};

#endif // CLOCK_H
