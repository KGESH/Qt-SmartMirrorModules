#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clock.h"
#include "date.h"

class Clock;
class Date;

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


private:
    const QFont FONT;
    Clock *clock_;
    Date *date_;


};
#endif // MAINWINDOW_H
