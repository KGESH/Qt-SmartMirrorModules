#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include "clock.h"
#include "date.h"
#include "newsheadline.h"

class Clock;
class Date;
class NewsHeadLine;

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


};
#endif // MAINWINDOW_H
