#ifndef CLOCK_H
#define CLOCK_H

#include "mainwindow.h"
#include <QObject>

class Clock : public QObject
{
    Q_OBJECT


public:
    explicit Clock(QObject *parent = 0);
    QString& GetCurrentTime();

private:
    QString timeText;
};

#endif // CLOCK_H
