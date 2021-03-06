#include "clock.h"
#include <QTimer>
#include <QTime>



Clock::Clock(QObject *parent)
    :QObject(parent)
{
}


QString& Clock::GetCurrentTime()
{
    auto time = QTime::currentTime();
    timeText_ = time.toString("hh : mm : ss ap");     // AM PM

    return timeText_;
}
