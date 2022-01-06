#include "mainpagewidget.h"
#include "ui_mainpagewidget.h"

#include <QDesktopServices>
#include <QUrl>

MainPageWidget::MainPageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPageWidget)
{
    ui->setupUi(this);
    QFont textFont("微软雅黑");
    textFont.setPixelSize(30);
    ui->textBrowser->setFont(textFont);

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->label_date->setText(currentDateTime.toString("yyyy年MM月dd日   ddd"));

    ui->label_hh->setText(currentDateTime.toString("HH:mm:ss").section(":",0,0));
    ui->label_mm->setText(currentDateTime.toString("HH:mm:ss").section(":",1,1));
    ui->label_ss->setText(currentDateTime.toString("HH:mm:ss").section(":",2,2));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainPageWidget::timePassing);
    timer->start(1000);

    ui->label_userAmount->setText(QString::number(this->userAmount));
    ui->label_bookAmount->setText(QString::number(this->bookAmount));
}

MainPageWidget::~MainPageWidget()
{
    delete ui;
}

void MainPageWidget::setupData()
{
    ui->label_userAmount->setText(QString::number(this->userAmount));
    ui->label_bookAmount->setText(QString::number(this->bookAmount));
}

void MainPageWidget::timePassing()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->label_hh->setText(currentDateTime.toString("HH:mm:ss").section(":",0,0));
    ui->label_mm->setText(currentDateTime.toString("HH:mm:ss").section(":",1,1));
    ui->label_ss->setText(currentDateTime.toString("HH:mm:ss").section(":",2,2));
}

void MainPageWidget::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://read.douban.com/reader/ebook/56693613/?from=book")));
}
