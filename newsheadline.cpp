#include "newsheadline.h"

NewsHeadLine::NewsHeadLine(QObject *parent) : QObject(parent)
{
    network_manager_ = new QNetworkAccessManager(this);
    QUrl url(request_url_);
    QUrlQuery query;
    //query.addQueryItem(API_ID, API_KEY);


    query.addQueryItem("X-Naver-Client-Id", API_ID);
    query.addQueryItem("X-Naver-Client-Secret", API_KEY);

    url.setQuery(query);
    network_reply = network_manager_->get(QNetworkRequest(url));

}


void NewsHeadLine::RequestNews()
{

}
