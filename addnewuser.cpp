#include "addnewuser.h"
#include "ui_addnewuser.h"

addNewUser::addNewUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addNewUser)
{
    ui->setupUi(this);
}

addNewUser::~addNewUser()
{
    delete ui;
}

void addNewUser::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(NULL,"Confirm","Are you sure you want to add a new user <br>"+ui->lineEdit->text()+"</br> ?",QMessageBox::Yes|QMessageBox::No);
    if(reply = QMessageBox::Yes){
        QFile *file = new QFile("user.txt");
        file->open(QIODevice::WriteOnly|QIODevice::ReadOnly);
        QTextStream io(file);
        QString s;
        s = io.readAll();
        io<<ui->lineEdit->text()<<endl;
        file->close();
        this->close();
    }

}
