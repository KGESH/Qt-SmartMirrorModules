#include "clock.h"
#include <QTimer>
#include <QTime>
Clock::Clock(QObject *parent)
    :QObject(parent)
{
}

QString Clock::SetTime() const{
    auto time = QTime::currentTime();
    QString timeText = time.toString("hh : mm");

    return timeText;
}
