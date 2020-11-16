#include "covid19graph.h"

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
   // chart_->addAxis(axisX_, Qt::AlignLeft);
    //chart_->addAxis(axisY_, Qt::AlignBottom);

   // graph_->attachAxis(axisX_);
    //graph_->attachAxis(axisY_);
}


void Covid19Graph::UpdateGraph()
{
    auto chart = new QChart();
    graph_ = new QLineSeries();


    //graph_->clear();
    SetConfirmedPerson();
    chart->addSeries(graph_);
    SetRecentlyDateList();



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
    int i = 0;
    QStringList& confirmed_person_count = covid_data_->GetConfirmedPersonCountList();
    //qDebug() << confirmed_person_count;

    foreach(const QString& person_list, confirmed_person_count){
        *graph_ << QPointF(i++, person_list.toInt() % 100);
    }
}


void Covid19Graph::SetAxisX()
{
    if(axisX_ != nullptr){
        //graph_->detachAxis(axisX_);
        //chart_->removeAxis(axisX_);

        delete axisX_;
    }

    axisX_ = new QCategoryAxis();
    int i = 0;
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
        //graph_->detachAxis(axisY_);
        //chart_->removeAxis(axisY_);
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


