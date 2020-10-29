#include "newsheadline.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
NewsHeadLine::NewsHeadLine(QObject *parent) : QObject(parent)
{
    network_manager_ = new QNetworkAccessManager(this);
    QUrl url(request_url_);
    QNetworkRequest request(url);
    request.setRawHeader("X-Naver-Client-Id", "J0Q3Ych2sPVVdjbwLVgH");
    request.setRawHeader("X-Naver-Client-Secret", "LQPqYitIxk");
    QUrlQuery query;


    network_reply = network_manager_->get(request);
    connect(network_reply, SIGNAL(finished(network_reply)),this, SLOT(RequestNews(network_reply)));


}


void NewsHeadLine::RequestNews(QNetworkReply* reply)
{

    if (reply->error()) {
            qDebug() << reply->errorString();
            return;
        }
        QJsonDocument jd;
        jd =  QJsonDocument::fromJson(reply->readAll());
        QJsonObject jo = jd.object();
     //   QJsonArray ja = jo[""].toArray();
        qDebug() << jo[""].toString();


        //QString answer = reply->readAll();


}
