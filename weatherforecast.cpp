#include "weatherforecast.h"
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

/***  OpenWeatherMap API      ***/
const QString REQUEST_URL = "https://api.openweathermap.org/data/2.5/onecall";
const QString LATITUDE = "lat";
const QString LONGITUDE = "lon";
const QString LATITUDE_VALUE = "37.470985";    /***  my home  ***/
const QString LONGITUDE_VALUE = "126.911062";  /***  position ***/
const QString APP_ID = "APPID";
const QString API_KEY = "fbe231cb5c0c34afdf3d789cff255a2a";
const QString EXCLUDE = "exclude";
const QString EXCLUDE_OPTION = "current,minutely,daily,alerts"; // API response include only hourly. ex) 1hour, 2hour, ...
const QString LANGUAGE = "lang";
//const QString LANGUAGE_VALUE = "kr";
/***  OpenWeatherMap API END  ***/

const double ZERO_KELVIN = 273.15;  /***  temperature 0°C  ***/



WeatherForecast::WeatherForecast(QObject *parent)
    : QObject(parent)
    , network_manager_(new QNetworkAccessManager(this))
{
    RequestOpenWeatherMapAPI();
}


void WeatherForecast::RequestOpenWeatherMapAPI()
{
    QUrl url(REQUEST_URL);
    QUrlQuery query;

    query.addQueryItem(LATITUDE,LATITUDE_VALUE);
    query.addQueryItem(LONGITUDE, LONGITUDE_VALUE);
    query.addQueryItem(EXCLUDE, EXCLUDE_OPTION);
    query.addQueryItem(APP_ID, API_KEY);
    url.setQuery(query);
    qDebug() << url;

    QNetworkRequest request(url);
    network_reply_ = network_manager_->get(request);
    connect(network_reply_, SIGNAL(finished()), this, SLOT(ParseWeatherData()));
}


void WeatherForecast::ParseWeatherData()
{
    if (network_reply_->error()) {
            qDebug() << network_reply_->errorString();
            return;
    }

     QByteArray data = network_reply_->readAll();
     QJsonDocument json_doc(QJsonDocument::fromJson(data));
     QJsonObject json_reply = json_doc.object();
     QJsonValue value = json_reply.value("hourly");
     QJsonArray title = value.toArray();

     QDateTime date;
     foreach (const QJsonValue &val, title){
         uint unix_time_stamp = val.toObject().value("dt").toInt();
         double temperature = val.toObject().value("temp").toDouble() - ZERO_KELVIN;
         date.setTime_t(unix_time_stamp);
         weather_time_list_.append(date);
         temperature_list_.append(temperature);
     }

     qDebug() << weather_time_list_;
     qDebug() << temperature_list_;
     network_reply_->close();
     network_reply_->deleteLater();
}
