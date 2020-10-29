#ifndef NEWSHEADLINE_H
#define NEWSHEADLINE_H


#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

const QString API_ID = "J0Q3Ych2sPVVdjbwLVgH";
const QString API_KEY = "LQPqYitIxk";

class NewsHeadLine : public QObject
{
    Q_OBJECT
public:
    explicit NewsHeadLine(QObject *parent = nullptr);

public slots:
    void RequestNews(QNetworkReply* reply);




private:

    QString request_url_ = "https://openapi.naver.com/v1/search/news.json";
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply;



};

#endif // NEWSHEADLINE_H
