#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include <QtPositioning/QGeoPositionInfoSource>


class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = nullptr);

signals:

};

#endif // WEATHERFORECAST_H
