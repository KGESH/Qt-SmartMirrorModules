#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include "clock.h"
#include "date.h"
#include "newsheadline.h"
#include "covid19graph.h"

class Clock;
class Date;
class NewsHeadLine;
class Covid19Graph;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;


public slots:
    void ShowTime();
    void ShowDate();
    void ShowNewsHeadLine();


private:
    const QFont FONT;
    Clock *clock_;
    Date *date_;
    NewsHeadLine *news_;
    Covid19Graph *covid19_graph_view_;



};
#endif // MAINWINDOW_H
