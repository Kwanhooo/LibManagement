#include "searchwidget.h"
#include "ui_searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
    this->setFixedSize(this->width(),this->height());
    ui->widget->hide();
    connect(ui->pushButton_search,SIGNAL(clicked()),this,SLOT(search()));
    connect(ui->pushButton_lend,SIGNAL(clicked()),this,SLOT(lend()));
    connect(ui->pushButton_inf,SIGNAL(clicked()),this,SLOT(open()));
}

SearchWidget::~SearchWidget()
{
    delete ui;
}

void SearchWidget::search(){
    ui->widget->show();
}

void SearchWidget::open(){
    BookInformation *bookInf = new BookInformation;
    bookInf->show();
}

void SearchWidget::lend(){
    BookInformation *bookInf = new BookInformation;
    bookInf->open();
    bookInf->show();
}
