#include "covid19graph.h"


Covid19Graph::Covid19Graph(QObject *parent)
    : QObject(parent)
    , graph_(new QLineSeries)
    , axisX_(new QCategoryAxis)
    , axisY_(new QCategoryAxis)
    , graphView_(new QChartView)

{
     UpdateGraph(testList);
}


void Covid19Graph::UpdateGraph(const QStringList& date_list)
{
    if (chart_ != nullptr){
        delete chart_;
    }

    chart_ = new QChart();
    chart_->setTitle("Cvoid19 Graph");
    *graph_ << QPointF(0, 20) << QPointF(1, 34) << QPointF(2, 50) << QPointF(3, 60) << QPointF(4,23)
            << QPointF(5, 12) << QPointF(6,20);
    chart_->addSeries(graph_);
    SetAxisX(date_list);
    SetAxisY();
    chart_->addAxis(axisX_, Qt::AlignBottom);
    chart_->addAxis(axisY_, Qt::AlignLeft);
    graph_->attachAxis(axisX_);
    graph_->attachAxis(axisY_);

}

QChart* Covid19Graph::GetGraph()
{
    return chart_;
}




void Covid19Graph::SetAxisX(const QStringList& date_list)
{
    int i = 0;
    foreach(const QString& date, date_list){
        axisX_->append(date, i++);
    }
    axisX_->setRange(0, --i);
}


void Covid19Graph::SetAxisY()
{
    QStringList confirmed_person_count = {"20", "40", "60", "80", "100"};

    foreach(const QString& person_count, confirmed_person_count){
        axisY_->append(person_count, person_count.toInt());
    }
    axisY_->setRange(0, confirmed_person_count.back().toInt());
}


