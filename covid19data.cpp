#include "covid19data.h"
#include <QUrl>
#include <QUrlQuery>
#include <QXmlStreamReader>
#include <QEventLoop>
#include <QDate>

const QString REQUEST_URL = "http://openapi.data.go.kr/openapi/service/rest/Covid19/getCovid19InfStateJson";
const QString API_ID = "serviceKey";
const QString API_KEY = "r1LpjwCuTmdcG%2BqkiHeqh1mbl6ZukOYUIAZvd8vjIFdhdFt9xCc%2BH2ZF6LWErgYRjfp0u8VZTDSe%2F1038IakGw%3D%3D";
const QString NUMBER_OF_RESULTS_PER_PAGE = "numOfRows";
const QString PAGE_NO = "pageNo";
const QString START_SEARCH_DATE_RANGE = "startCreateDt";
const QString END_SEARCH_DATE_RANGE = "endCreateDt";
const int PREVIOUS_DAYS = -7;   /***  Graph Range
                                 ***  Ex) 1 week = -7
                                                 ***/


Covid19Data::Covid19Data(QObject *parent)
    : QObject(parent)
{
    network_manager_ = new QNetworkAccessManager(this);
    RequestAPI();
}


void Covid19Data::RequestAPI()
{
    QDate today = QDate::currentDate();
    QUrlQuery query;
    query.addQueryItem(API_ID, API_KEY);
    query.addQueryItem(NUMBER_OF_RESULTS_PER_PAGE, "10");
    query.addQueryItem(PAGE_NO, "1");
    query.addQueryItem(START_SEARCH_DATE_RANGE, today.addDays(PREVIOUS_DAYS).toString("yyyyMMdd"));  /***  Set graph range  ***/
    query.addQueryItem(END_SEARCH_DATE_RANGE, today.toString("yyyyMMdd"));                           /***                   ***/

    QUrl url(REQUEST_URL);
    url.setQuery(query);

    QNetworkRequest request(url);
    network_reply_ = network_manager_->get(request);
    QEventLoop loop;
    connect(network_reply_, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    RequestCovid19Data();
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
                confirmed_person_count_list_.push_front(xml.readElementText()); // not append, need reverse
            } else if(name == "stateDt"){   // 해당 날짜
                date_list_.push_front(xml.readElementText());                   // not append, need reverse
            }
        }
    }

    if (xml.hasError())
    {
        qDebug() << "XML error: " << xml.errorString();
    }
}
