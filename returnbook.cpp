#include "returnbook.h"
#include "ui_returnbook.h"

returnbook::returnbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::returnbook)
{
    ui->setupUi(this);
    connect(this->ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(returnABook(QModelIndex)));

}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::init(QString s,int n)
{
    QStringListModel *listmodel = new QStringListModel(list);
    ui->listView->setModel(listmodel);
    name = s;
    if(n==0)ui->label->setText("Books borrowed by Xiao Li <b>"+s+"</b> :");
    else ui->label->setText("Books in library: ");
    this->model = n;
}

void returnbook::returnABook(QModelIndex index)
{
    if(model==0){
        int x = index.row();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(NULL,"Confirm","Are you sure user <b>"+name+"</b> wants to return the Book <b>"+list.at(x)+"</b> ?",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes){
            list.erase(list.begin()+x);
            this->init(name,model);
        }
    }
    else{
        int x = index.row();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(NULL,"Confirm","Are you sure user <b>"+name+"</b> wants to borrow the Book <b>"+list.at(x)+"</b> ?",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes){
            list.erase(list.begin()+x);
            this->init(name,model);
        }
    }
}
