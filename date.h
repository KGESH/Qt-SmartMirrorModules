#ifndef DATE_H
#define DATE_H

#include <QObject>

class Date : public QObject
{
    Q_OBJECT


public:
    explicit Date(QObject *parent = nullptr);
    QString& GetCurrentDate();

private:
    QString dateText_;
};

#endif // DATE_H
