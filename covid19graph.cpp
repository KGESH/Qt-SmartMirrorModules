#include "covid19graph.h"


Covid19Graph::Covid19Graph(QObject *parent)
    : QObject(parent)
    , graph_(new QLineSeries)
    , axisX_(new QCategoryAxis)
    , axisY_(new QCategoryAxis)
    , graphView_(new QChartView)
{
    graph_font_.setPixelSize(18);
    UpdateGraph();
}


void Covid19Graph::UpdateGraph()
{
    if (chart_ != nullptr){
        delete chart_;
    }

    chart_ = new QChart();
    CustomizeGraph();
    SetConfirmedPerson();

    chart_->addSeries(graph_);
    SetRecentlyDateList();
    SetAxisX();
    SetAxisY();
    graph_->attachAxis(axisX_);
    graph_->attachAxis(axisY_);
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
    QDate today = QDate::currentDate();

    for(int i= -6; i <= 0; i++){
        recently_date_list_.append(today.addDays(i));   // insert recently 7days
    }
}


void Covid19Graph::SetConfirmedPerson()
{
    *graph_ << QPointF(0, 70) << QPointF(1, 34) << QPointF(2, 50) << QPointF(3, 60) << QPointF(4,23)
            << QPointF(5, 12) << QPointF(6, 90);

}

void Covid19Graph::SetAxisX()
{
    int i = 0;
    axisX_->setLabelsFont(graph_font_);
    foreach(const QDate& date, recently_date_list_){
        axisX_->append(date.toString("MM월 dd일"), i++);
    }
    axisX_->setRange(0, --i);
    chart_->addAxis(axisX_, Qt::AlignBottom);
}


void Covid19Graph::SetAxisY()
{
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


