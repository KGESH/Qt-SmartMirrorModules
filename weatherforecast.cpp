#include "weatherforecast.h"
#include <QDebug>
#include <QVariantMap>

WeatherForecast::WeatherForecast(QObject *parent) : QObject(parent)
{
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createSource("serialnmea", params, this);
           if (source) {
               connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                       this, SLOT(positionUpdated(QGeoPositionInfo)));
               source->startUpdates();
           }
    QGeoPositionInfo info;
    qDebug() << info.coordinate();
}


void WeatherForecast::positionUpdated(const QGeoPositionInfo &info)
{
    qDebug() << info;
    qDebug() << info.coordinate().latitude();
    qDebug() << "cord";
    coord = info.coordinate();
    qDebug() << coord;
}
