#include "date.h"
#include <QDate>

Date::Date(QObject *parent)
    : QObject(parent)
{

}

QString Date::SetDate() const{
    auto date = QDate::currentDate();
    QString dateText = date.toString("yyyy년MM월dd일");

    return dateText;
}
