#include "bookinformation.h"
#include "ui_bookinformation.h"
#include "libmanagement.h"
#include "ui_libmanagement.h"
#include "logindialog.h"
#include "searchwidget.h"
#include "mainpagewidget.h"
#include "mewidget.h"

BookInformation::BookInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookInformation)
{
    ui->setupUi(this);
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setRenderHint(QPainter::Antialiasing); // 反锯齿;
    p.setPen(Qt::transparent);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(), 30, 30);
    setMask(bmp);
    ui->Titlel_x->hide();
    ui->Titlel_xx->hide();
    ui->pushButton_OK->hide();
    connect(ui->pushButton_lend,SIGNAL(clicked()),this,SLOT(open()));
}

BookInformation::~BookInformation()
{
    delete ui;
}

void BookInformation::open(){
    ui->Titlel_1->hide();
    ui->Titlel_3->hide();
    ui->Titlel_4->hide();
    ui->Titlel_5->hide();
    ui->Titlel_6->hide();
    ui->textBrowser->hide();
    ui->pushButton_exit->hide();
    ui->pushButton_lend->hide();
    ui->Titlel_x->show();
    ui->Titlel_xx->show();
    ui->pushButton_OK->show();
}
