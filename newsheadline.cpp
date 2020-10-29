#include "newsheadline.h"
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>

const QString API_ID = "X-Naver-Client-Id";
const QString API_ID_KEY = "J0Q3Ych2sPVVdjbwLVgH";
const QString API_SCRET = "X-Naver-Client-Secret";
const QString API_SCRET_KEY = "LQPqYitIxk";
const QString QUERY_STRING = "query";
const QString NEWS_KEYWORD = "뉴스";
const QString DISPLAY_OPTION = "display";
const QString NEWS_NUM = "5";
const QString SEARCH_OPTION = "start";
const QString SEARCH_START_POINT = "1";    // naver search api start point, 1 is default
const QString ENABLE_SORT_OPTION = "sort";
const QString SORT_POLICY = "date"; // date, sim    default = similar


NewsHeadLine::NewsHeadLine(QObject *parent) : QObject(parent)
{
    network_manager_ = new QNetworkAccessManager(this);
    QUrlQuery query;
    query.addQueryItem(QUERY_STRING, NEWS_KEYWORD);
    query.addQueryItem(DISPLAY_OPTION, NEWS_NUM);
    query.addQueryItem(SEARCH_OPTION, SEARCH_START_POINT);
    query.addQueryItem(ENABLE_SORT_OPTION, SORT_POLICY);

    QUrl url(request_url_);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setRawHeader(API_ID.toUtf8(), API_ID_KEY.toUtf8());
    request.setRawHeader(API_SCRET.toUtf8(), API_SCRET_KEY.toUtf8());

    network_reply_ = network_manager_->get(request);

    QEventLoop loop;
    connect(network_reply_, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    RequestNews(network_reply_);
}


void NewsHeadLine::RequestNews(QNetworkReply* reply)
{
    if (reply->error()) {
            qDebug() << reply->errorString();
            return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument json_doc(QJsonDocument::fromJson(data));
    QJsonObject json_reply = json_doc.object();
    QJsonArray title = json_reply["items"].toArray();

    foreach (const QJsonValue &val, title){
        QString str = val.toObject().value("title").toString();
        news_list_.append(str);
        qDebug() << str;
    }

    reply->close();
    reply->deleteLater();
}


QStringList& NewsHeadLine::GetNewsList()
{
    return news_list_;
}
