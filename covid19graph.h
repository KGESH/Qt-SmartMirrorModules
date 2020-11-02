#ifndef COVID19GRAPH_H
#define COVID19GRAPH_H

#include <QObject>
#include <QtCharts>
class Covid19Graph : public QObject
{
    Q_OBJECT
public:
    explicit Covid19Graph(QObject *parent = nullptr);
    QChart* GetGraph();



private:
    void UpdateGraph(const QStringList& date_list);
    void SetAxisX(const QStringList& date_list);
    void SetAxisY();

    QChart *chart_ = nullptr;
    QLineSeries *graph_ = nullptr;
    QCategoryAxis *axisX_ = nullptr;
    QCategoryAxis *axisY_ = nullptr;
    QChartView *graphView_ = nullptr;
    QStringList testList = {"10/25", "10/26", "10/27", "10/28", "10/29", "10/30", "10/31" };
    QFont graph_font_;



};

#endif // COVID19GRAPH_H
