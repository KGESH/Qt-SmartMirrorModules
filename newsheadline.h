#ifndef NEWSHEADLINE_H
#define NEWSHEADLINE_H


#include <QObject>
#include <QtNetwork/QNetworkReply>


class NewsHeadLine : public QObject
{
    Q_OBJECT
public:
    explicit NewsHeadLine(QObject *parent = nullptr);
    QStringList& GetNewsList();

private slots:
    void RequestNews();

private:
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply_;
    QStringList news_list_;
};

#endif // NEWSHEADLINE_H
