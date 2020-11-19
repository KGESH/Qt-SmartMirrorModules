#ifndef WEATHERFORECAST_H
#define WEATHERFORECAST_H

#include <QObject>
#include <QtNetwork/QNetworkReply>


class WeatherForecast : public QObject
{
    Q_OBJECT
public:
    explicit WeatherForecast(QObject *parent = nullptr);

private slots:
    void ParseWeatherData();


private:
    void RequestOpenWeatherMapAPI();
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply_;
    QList<QDateTime> weather_time_list_;
    QList<double> temperature_list_;


};

#endif // WEATHERFORECAST_H
