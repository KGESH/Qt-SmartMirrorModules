#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


const int FONT_SIZE = 30;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , FONT("Arial", FONT_SIZE, QFont::Bold)
{
    clock_ = new Clock(this);
    date_ = new Date(this);
    news_ = new NewsHeadLine(this);
    covid19_graph_view_ = new Covid19Graph(this);
    auto timer = new QTimer(this);

    ui->setupUi(this);
    ui->ui_myfeel_text->setFont(FONT);
    ui->ui_time->setFont(FONT);
    ui->ui_date->setFont(FONT);
    ui->ui_covid19->setChart(covid19_graph_view_->GetGraph());

    connect(timer, SIGNAL(timeout()), SLOT(ShowNewsHeadLine()));
    connect(timer, SIGNAL(timeout()), SLOT(ShowTime()));
    connect(timer, SIGNAL(timeout()), SLOT(ShowDate()));
    timer->start(1000); // 1000 ms == 1sec
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ShowTime()
{
    ui->ui_time->setText(clock_->GetCurrentTime());
}


void MainWindow::ShowDate()
{
    ui->ui_date->setText(date_->GetCurrentDate());
}


void MainWindow::ShowNewsHeadLine()
{

    QStringList news_list = news_->GetNewsList();
    QString str = news_list.join("\n"); // concat String by \n
    ui->ui_news->setText(str);
}
