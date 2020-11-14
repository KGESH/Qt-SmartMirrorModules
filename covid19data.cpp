#include "covid19data.h"
#include <QUrl>
#include <QUrlQuery>
#include <QXmlStreamReader>

const QString REQUEST_URL = "http://openapi.data.go.kr/openapi/service/rest/Covid19/getCovid19InfStateJson";
const QString API_ID = "serviceKey";
const QString API_KEY = "r1LpjwCuTmdcG%2BqkiHeqh1mbl6ZukOYUIAZvd8vjIFdhdFt9xCc%2BH2ZF6LWErgYRjfp0u8VZTDSe%2F1038IakGw%3D%3D";
const QString NUMBER_OF_RESULTS_PER_PAGE = "numOfRows";
const QString PAGE_NO = "pageNo";
const QString START_SEARCH_DATE_RANGE = "startCreateDt";
const QString END_SEARCH_DATE_RANGE = "endCreateDt";


Covid19Data::Covid19Data(QObject *parent)
    : QObject(parent)
{
    network_manager_ = new QNetworkAccessManager(this);

    QUrlQuery query;
    query.addQueryItem(API_ID, API_KEY);
    query.addQueryItem(NUMBER_OF_RESULTS_PER_PAGE, "10");
    query.addQueryItem(PAGE_NO, "1");
    query.addQueryItem(START_SEARCH_DATE_RANGE, "20201028");
    query.addQueryItem(END_SEARCH_DATE_RANGE, "20201104");

    QUrl url(REQUEST_URL);
    url.setQuery(query);

    QNetworkRequest request(url);
    network_reply_ = network_manager_->get(request);
    connect(network_reply_, SIGNAL(finished()), this, SLOT(RequestCovid19Data()));
}


QStringList& Covid19Data::GetConfirmedPersonCountList()
{
    return confirmed_person_count_list_;
}


QStringList& Covid19Data::GetDateList()
{
    return date_list_;
}


void Covid19Data::RequestCovid19Data()
{
    if (network_reply_->error()) {
            qDebug() << network_reply_->errorString();
            return;
    }

    QByteArray data = network_reply_->readAll();
    QXmlStreamReader xml(data);

    while(!xml.atEnd()){
        xml.readNext();
        if(xml.isStartElement()){
            QString name = xml.name().toString();
            if(name == "decideCnt"){    //확진자 수
                confirmed_person_count_list_.append(xml.readElementText());
            } else if(name == "stateDt"){   // 해당 날짜
                date_list_.append(xml.readElementText());
            }
        }
    }

    if (xml.hasError())
    {
        qDebug() << "XML error: " << xml.errorString();
    }
    qDebug() << confirmed_person_count_list_;
    qDebug() << date_list_;


}
