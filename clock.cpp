#include "clock.h"
#include <QTimer>
#include <QTime>


Clock::Clock(QObject *parent)
    :QObject(parent)
{
}

QString& Clock::SetTime(){
    auto time = QTime::currentTime();
    timeText = time.toString("hh : mm ap");     // AM PM

    return timeText;
}
