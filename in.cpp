#include "in.h"
#include "ui_in.h"

in::in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);

    ui->lineEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");
    this->ui->writer->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");
    ui->confirm->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->clear->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->cancel->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    connect(parent,SIGNAL(showBook(QString)),this,SLOT(getShowBook(QString)));
}


in::~in()
{
    delete ui;
}

void in::on_confirm_clicked()
{
    if(this->ui->lineEdit->text()=="")
    {
        QMessageBox *box = new QMessageBox();

        QPushButton *btn_1=new QPushButton("确认");
        QPushButton *btn_2=new QPushButton("取消");

        btn_1->setShortcut(QKeySequence("Y"));
        btn_2->setShortcut(QKeySequence("N"));

        box->setText("请添加书名");

        box->addButton(btn_1,QMessageBox::AcceptRole);
        box->addButton(btn_2,QMessageBox::AcceptRole);

        box->exec();
        if(box->clickedButton()==btn_1)
        {
            box->close();
        }
        else {
            box->close();
        }
    }
    else if(this->ui->lineEdit->text()=="book1"||this->ui->lineEdit->text()=="book2"||this->ui->lineEdit->text()=="book3")
    {
        QMessageBox *box = new QMessageBox();

        QPushButton *btn_1=new QPushButton("确认");
        QPushButton *btn_2=new QPushButton("取消");

        btn_1->setShortcut(QKeySequence("Y"));
        btn_2->setShortcut(QKeySequence("N"));

        box->setText("书库中有重名，请选一本新书");

        box->addButton(btn_1,QMessageBox::AcceptRole);
        box->addButton(btn_2,QMessageBox::AcceptRole);

        box->exec();
        this->ui->lineEdit->setFocus();
        this->ui->lineEdit->selectAll();
        if(box->clickedButton()==btn_1)
        {
            box->close();
        }
        else {
            box->close();
        }
    }
    else {
        QMessageBox *box = new QMessageBox();

        QPushButton *btn_1=new QPushButton("确认");
        QPushButton *btn_2=new QPushButton("取消");

        btn_1->setShortcut(QKeySequence("Y"));
        btn_2->setShortcut(QKeySequence("N"));

        box->setText("你确定要添加名为"+this->ui->lineEdit->text()+"的书么");

        box->addButton(btn_1,QMessageBox::AcceptRole);
        box->addButton(btn_2,QMessageBox::AcceptRole);

        box->exec();
        if(box->clickedButton()==btn_1)
        {
            box->close();
            QMessageBox *box0 = new QMessageBox();

            QPushButton *btn0_1=new QPushButton("确认");
            QPushButton *btn0_2=new QPushButton("取消");

            btn0_1->setShortcut(QKeySequence("Y"));
            btn0_2->setShortcut(QKeySequence("N"));

            box0->setText("你已经成功添加名为"+this->ui->lineEdit->text()+"的书");

            box0->addButton(btn0_1,QMessageBox::AcceptRole);
            box0->addButton(btn0_2,QMessageBox::AcceptRole);

            box0->exec();

            if(box0->clickedButton()==btn0_1||box0->clickedButton()==btn0_2)
            {
                emit(addNew(this->ui->lineEdit->text()));
                this->close();
                box0->close();
                qDebug()<<"fuck";

            }
        }
        else {
            box->close();
            this->ui->lineEdit->selectAll();
        }
    }

}

void in::on_cancel_clicked()
{
this->close();
}

void in::on_clear_clicked()
{
    this->ui->lineEdit->clear();
    this->ui->writer->clear();
}

void in::getShowBook(QString s)
{
    this->ui->lineEdit->setText(s);
}
