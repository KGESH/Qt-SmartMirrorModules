#ifndef COVID19GRAPH_H
#define COVID19GRAPH_H

#include <QObject>
#include <QtCharts>
#include <QDate>
#include "covid19data.h"


class Covid19Data;

class Covid19Graph : public QObject
{
    Q_OBJECT
public:
    explicit Covid19Graph(QObject *parent = nullptr);
    QChart* GetGraph();
    void UpdateGraph();



private:
    void SetAxisX();
    void SetAxisY();
    void CustomizeGraph();
    void SetRecentlyDateList();
    void SetConfirmedPerson();
    void SetCovid19Data();


    Covid19Data *covid_data_ = nullptr;
    QChart *chart_ = nullptr;
    QLineSeries *graph_ = nullptr;
    QCategoryAxis *axisX_ = nullptr;
    QCategoryAxis *axisY_ = nullptr;
    QChartView *graphView_ = nullptr;
    QList<QDate> recently_date_list_;
    QFont graph_font_;
    QStringList confirmed_person_count = { "20", "40", "60", "80", "100" };


};

#endif // COVID19GRAPH_H
