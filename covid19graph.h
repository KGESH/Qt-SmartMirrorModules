#ifndef COVID19GRAPH_H
#define COVID19GRAPH_H

#include <QObject>
#include <QtCharts>
class Covid19Graph : public QObject
{
    Q_OBJECT
public:
    explicit Covid19Graph(QObject *parent = nullptr);


private:
    void UpdateGraph(const QStringList& date_list);
    void SetAxisX(const QStringList& date_list);
    void SetAxisY();

    QChart *chart_;
    QLineSeries *graph_;
    QCategoryAxis *axisX_;
    QCategoryAxis *axisY_;
    QChartView *graphView_;


};

#endif // COVID19GRAPH_H
