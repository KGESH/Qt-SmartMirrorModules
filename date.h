#ifndef DATE_H
#define DATE_H

#include "mainwindow.h"
#include <QObject>

class Date : public QObject
{
    Q_OBJECT


public:
    explicit Date(QObject *parent = nullptr);

public slots:
    QString& SetDate();

private:
    QString dateText;
};

#endif // DATE_H
