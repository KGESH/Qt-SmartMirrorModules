#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include <QtPositioning/QGeoPositionInfoSource>
#include <QtPositioning/QGeoCoordinate>
#include <QGeoAddress>
#include <QGeoPositionInfo>
#include <QtNetwork/QNetworkReply>



class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = nullptr);

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
    void ParseWeatherData();


private:

    void RequestOpenWeatherMapAPI();
    QGeoCoordinate coord;
    QGeoAddress address;
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply_;


};

#endif // WEATHERFORECAST_H
