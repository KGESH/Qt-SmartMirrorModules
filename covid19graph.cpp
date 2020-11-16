#include "covid19graph.h"
#include <QListIterator>
#include <QList>

Covid19Graph::Covid19Graph(QObject *parent)
    : QObject(parent)
    , covid_data_(new Covid19Data(this))
    , chart_(new QChart())
    , graph_(new QLineSeries)
    , graphView_(new QChartView)
{
    graph_font_.setPixelSize(18);
    SetConfirmedPerson();
    CustomizeGraph();
    chart_->addSeries(graph_);
    SetRecentlyDateList();
    SetAxisX();
    SetAxisY();
}


void Covid19Graph::UpdateGraph()
{
    SetConfirmedPerson();
    SetRecentlyDateList();
    SetAxisX();
    SetAxisY();
}


void Covid19Graph::CustomizeGraph()
{
    QPen pen(QRgb(0xfdb157));
    chart_->setTitle("Covid19 Graph");
    chart_->setTitleFont(graph_font_);
    pen.setWidth(5);
    graph_->setPen(pen);
}


void Covid19Graph::SetRecentlyDateList()
{
    if(!recently_date_list_.isEmpty()){
        recently_date_list_.clear();
    }

    QStringList& date_list = covid_data_->GetDateList();

    foreach(const QString& date, date_list){  // insert 7days covid19
        recently_date_list_.push_front(QDate::fromString(date,"yyyyMMdd")); // not append, need reverse
    }
}


void Covid19Graph::SetConfirmedPerson()
{
    if(graph_->count() > 0){    // if is not empty
        graph_->clear();
    }

    int i = 0;
    QStringList& confirmed_person_count = covid_data_->GetConfirmedPersonCountList();

    foreach(const QString& person_list, confirmed_person_count){
        *graph_ << QPointF(i++, person_list.toInt() % 100 + update_value++);    // update checking test value
    }
}


void Covid19Graph::SetAxisX()
{
    if(axisX_ != nullptr){
        delete axisX_;
    }

    int i = 0;
    axisX_ = new QCategoryAxis();
    axisX_->setLabelsFont(graph_font_);

    foreach(const QDate& date, recently_date_list_){
        axisX_->append(date.toString("MM월 dd일"), i++);
    }

    axisX_->setRange(0, --i);
    chart_->addAxis(axisX_,Qt::AlignBottom);
}


void Covid19Graph::SetAxisY()
{
    if(axisY_ != nullptr){
        delete axisY_;
    }

    axisY_ = new QCategoryAxis();
    axisY_->setLabelsFont(graph_font_);

    foreach(const QString& person_count, confirmed_person_count){
        axisY_->append(person_count, person_count.toInt());
    }

    axisY_->setRange(0, confirmed_person_count.back().toInt());
    chart_->addAxis(axisY_, Qt::AlignLeft);
}


QChart* Covid19Graph::GetGraph()
{
    return chart_;
}


