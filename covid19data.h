#ifndef COVID19DATA_H
#define COVID19DATA_H


#include <QObject>
#include <QtNetwork/QNetworkReply>


class Covid19Data : public QObject
{
    Q_OBJECT
public:
    explicit Covid19Data(QObject *parent = nullptr);
    QStringList& GetConfirmedPersonCountList();
    QStringList& GetDateList();

private:
    void RequestAPI();
    void ParseCovid19Data();
    QNetworkAccessManager *network_manager_;
    QNetworkReply *network_reply_;
    QStringList confirmed_person_count_list_;
    QStringList date_list_;
};

#endif // COVID19DATA_H
