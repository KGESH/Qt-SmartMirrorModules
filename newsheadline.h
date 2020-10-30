#ifndef NEWSHEADLINE_H
#define NEWSHEADLINE_H


#include <QObject>
#include <QtNetwork/QNetworkReply>


const QString REQUEST_URL =  "https://openapi.naver.com/v1/search/news.json";

class NewsHeadLine : public QObject
{
    Q_OBJECT
public:
    explicit NewsHeadLine(QObject *parent = nullptr);
    QStringList& GetNewsList();

public slots:
    void RequestNews();

private:
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply_;
    QStringList news_list_;
};

#endif // NEWSHEADLINE_H
