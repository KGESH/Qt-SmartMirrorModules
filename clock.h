#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>

class Clock : public QObject
{
    Q_OBJECT

public:
    explicit Clock(QObject *parent = 0);
    QString& GetCurrentTime();

private:
    QString timeText_;
};

#endif // CLOCK_H
