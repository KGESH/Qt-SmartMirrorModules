#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include <QtPositioning/QGeoPositionInfoSource>
#include <QtPositioning/QGeoCoordinate>
#include <QGeoAddress>
#include <QGeoPositionInfo>


class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = nullptr);

private slots:
    void positionUpdated(const QGeoPositionInfo &info);

private:
    QGeoCoordinate coord;
    QGeoAddress address;


};

#endif // WEATHERFORECAST_H
