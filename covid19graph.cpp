#include "covid19graph.h"
#include <QListIterator>
#include <QList>

const int g_MIN_AXIS_Y_RANGE = 0;
const int g_MAX_AXIS_Y_RANGE = 300;


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
        recently_date_list_.append(QDate::fromString(date,"yyyyMMdd"));
    }
}


void Covid19Graph::SetConfirmedPerson()
{
    if(graph_->count() > 0){    // if is not empty
        graph_->clear();
        confirmed_person_count.clear();
    }

    int i = 0;
    int today = 0;
    int next_day = 0;
    QStringListIterator iter = covid_data_->GetConfirmedPersonCountList();

    /*** insert nextday person count - today person cout ***/
    today = iter.next().toInt();
    while(iter.hasNext()){
        next_day = iter.next().toInt();
        confirmed_person_count.append(QString::number(next_day-today));
        today = next_day;
    }

    foreach(const QString& person_list, confirmed_person_count){
        *graph_ << QPointF(i++, person_list.toInt());    // update checking test value
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
    graph_->attachAxis(axisX_);
}


void Covid19Graph::SetAxisY()
{
    if(axisY_ != nullptr){
        delete axisY_;
    }

    axisY_ = new QCategoryAxis();
    axisY_->setLabelsFont(graph_font_);
    QStringListIterator iter = confirmed_person_count;

    /***  Set Axis Y: 0, 100, 200, 300  ***/
    foreach(const QString& y_value, axisY_value){
        axisY_->append(y_value, y_value.toInt());
    }

    axisY_->setRange(g_MIN_AXIS_Y_RANGE, g_MAX_AXIS_Y_RANGE);
    chart_->addAxis(axisY_, Qt::AlignLeft);
    graph_->attachAxis(axisY_);
}


QChart* Covid19Graph::GetGraph()
{
    return chart_;
}

