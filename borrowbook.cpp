#include "borrowbook.h"
#include "ui_borrowbook.h"

borrowbook::borrowbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrowbook)
{
    ui->setupUi(this);
}

borrowbook::~borrowbook()
{
    delete ui;
}
