#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);

    init();
}

View::View(QWidget *parent,QString s,int n) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);

    init(s,n);
}

View::~View()
{
    delete ui;
}

void View::init()
{
    ui->back->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;border-image:url(:/exit.png);}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
}

void View::init(QString s,int n)
{
    ui->back->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;border-image:url(:/exit.png);}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    QStringList list = s.split("/");

    model = new QStandardItemModel;

    for(int i=0;i<n;i++)
    {
        QString string = static_cast<QString>(list.at(i));
        QStandardItem *item = new QStandardItem(string);
        model->appendRow(item);
    }

    this->ui->book->setModel(model);

}

void View::on_back_clicked()
{
    this->close();
}
