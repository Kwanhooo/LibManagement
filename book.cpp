#include "book.h"
#include "ui_book.h"

Book::Book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);

    init();
}

Book::~Book()
{
    delete ui;
}

void Book::init()
{
//    this->list.append("one");

//    listview=new QListView(this);
//    listview -> setViewMode ( QListView :: IconMode );
//    listview -> setMovement ( QListView :: Static );
//    listview -> setIconSize ( QSize ( 100 , 100 ));
//    listview -> setGridSize ( QSize ( 150 , 130 ));
//    listview -> setGeometry ( 0 , 0 , 480 , 272 );
//    listview -> setResizeMode ( QListView :: Adjust );



//    for(int i=0;i<this->list.length();i++)
//    {
//        QStandardItem *item = new QStandardItem(QIcon(":/2a0f4afab6d3b2932a3de633e1e686d1.jpeg"),list[i]);
//        this->model->appendRow(item);
//    }
//    s1=new QStandardItem(QIcon(":/515.png"),"普通员工");
//    s2=new QStandardItem(QIcon(":/t01e28c73faf31c0d8c.jpg"),"领导");
//    s3=new QStandardItem(QIcon(":/520.png"),"huangling");
//    s4=new QStandardItem(QIcon(":/521.png"),"bailing");
//    s5=new QStandardItem(QIcon(":/518.png"),"jinling");
//    s6=new QStandardItem(QIcon(":/519.png"),"heiling");
//    slm=new QStandardItemModel(this);slm->appendRow(s1);
//    slm->appendRow(s2);
//    slm->appendRow(s3);
//    slm->appendRow(s4);
//    slm->appendRow(s5);
//    slm->appendRow(s6);
//    listview->setModel(slm);

//listview->setModel(model);

    this->total=3;
    this->ui->book4->hide();
    this->ui->checkBox_4->hide();

    //this->line->show();
    // 设置按钮样式及悬浮、按下时的状态


    ui->in->setToolTip("在此添加新书");
    ui->check->setToolTip("在此查看详细信息");
    ui->out->setToolTip("在此删除书籍");

    ui->pushButton->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}"
                                              "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");

    ui->in->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;border-image:url(:/getIn.png);}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->check->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;border-image:url(:/search.png);}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->out->setStyleSheet("QPushButton{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:50px;padding:2px 4px;border-style: outset;border-image:url(:/getOut.png);}"
                                               "QPushButton:hover{background-color:rgb(229, 241, 251); color: black;}"
                                               "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}");
    ui->lineEdit->setStyleSheet("QLineEdit{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");

    ui->book1->setStyleSheet("QPushButton{border-image:url(:/2a0f4afab6d3b2932a3de633e1e686d1.jpeg);}"
                               "QPushButton::hover{border-image:url(:/-1.jpeg);}"
                             "QPushButton::pressed{border-image:url(:/-2.jpeg);}");
    ui->book2->setStyleSheet("QPushButton{border-image:url(:/2a0f4afab6d3b2932a3de633e1e686d1.jpeg);}"
                               "QPushButton::hover{border-image:url(:/-1.jpeg);}"
                             "QPushButton::pressed{border-image:url(:/-2.jpeg);}");
    ui->book3->setStyleSheet("QPushButton{border-image:url(:/2a0f4afab6d3b2932a3de633e1e686d1.jpeg);}"
                               "QPushButton::hover{border-image:url(:/-1.jpeg);}"
                             "QPushButton::pressed{border-image:url(:/-2.jpeg);}");
    ui->what->setStyleSheet("QPushButton{border-image:url(:/what.jpeg);}"
                               "QPushButton::hover{border-image:url(:/what_1.jpeg);}"
                             "QPushButton::pressed{border-image:url(:/what.jpeg);}");


}

void Book::on_in_clicked()
{
    class in *child=new class in();
    connect(child,SIGNAL(addNew(QString)),this,SLOT(getNewOne(QString)));
    child->show();
}

void Book::getNewOne(QString s)
{
    ui->book4->setStyleSheet("QPushButton{border-image:url(:/2a0f4afab6d3b2932a3de633e1e686d1.jpeg);}"
                               "QPushButton::hover{border-image:url(:/-1.jpeg);}"
                             "QPushButton::pressed{border-image:url(:/-2.jpeg);}");
    ui->checkBox_4->setText(s);

    this->ui->book4->show();
    this->ui->checkBox_4->show();
    this->total+=1;
}

void Book::on_book1_clicked()
{
    if(this->ui->checkBox->isChecked())
    {
        this->ui->checkBox->setChecked(false);

    }
    else {
        this->ui->checkBox->setChecked(true);
    }
}

void Book::on_book2_clicked()
{
    if(this->ui->checkBox_2->isChecked())
    {
        this->ui->checkBox_2->setChecked(false);

    }
    else {
        this->ui->checkBox_2->setChecked(true);
    }
}

void Book::on_book3_clicked()
{
    if(this->ui->checkBox_3->isChecked())
    {
        this->ui->checkBox_3->setChecked(false);

    }
    else {
        this->ui->checkBox_3->setChecked(true);
    }
}

void Book::on_book4_clicked()
{
    if(this->ui->checkBox_4->isChecked())
    {
        this->ui->checkBox_4->setChecked(false);

    }
    else {
        this->ui->checkBox_4->setChecked(true);
    }
}

void Book::on_check_clicked()
{
        bool ch =false;
        QMessageBox *box = new QMessageBox();

        QPushButton *btn_1=new QPushButton("确认");
        QPushButton *btn_2=new QPushButton("取消");

        btn_1->setShortcut(QKeySequence("Y"));
        btn_2->setShortcut(QKeySequence("N"));

        QString s="你确定要查看名为 ";
        if(this->ui->checkBox->isChecked())
        {
            s+=this->ui->checkBox->text()+" ";
            ch=true;
        }
        if(this->ui->checkBox_2->isChecked())
        {
            s+=this->ui->checkBox_2->text()+" ";
            ch=true;
        }
        if(this->ui->checkBox_3->isChecked())
        {
            s+=this->ui->checkBox_3->text()+" ";
            ch=true;
        }
        if(this->ui->checkBox_4->isChecked())
        {
            s+=this->ui->checkBox_4->text()+" ";
            ch=true;
        }
        s+="的书么";
        if(ch==false)
        {
            QMessageBox::warning(this,"警告","请选择要查看的书籍");
        }
        else {
            box->setText(s);

            box->addButton(btn_1,QMessageBox::AcceptRole);
            box->addButton(btn_2,QMessageBox::AcceptRole);

            box->exec();

            if(box->clickedButton()==btn_1)
            {
                int tem=0;
                QString m;
                if(this->ui->checkBox->isChecked())
                {
                    m+=this->ui->checkBox->text()+"/";
                    tem++;
                }
                if(this->ui->checkBox_2->isChecked())
                {
                    m+=this->ui->checkBox_2->text()+"/";
                    tem++;
                }
                if(this->ui->checkBox_3->isChecked())
                {
                    m+=this->ui->checkBox_3->text()+"/";
                    tem++;
                }
                if(this->ui->checkBox_4->isChecked())
                {
                    m+=this->ui->checkBox_4->text()+"/";
                    tem++;
                }

                View *view = new View(this,m,tem);
                view->setParent(NULL);
                view->show();
            }
        }
}

void Book::on_pushButton_clicked()
{
    if(this->ui->lineEdit->text().isEmpty())
    {
        if(isViewing==false)
        {
            QMessageBox::warning(this,"提示","请输入书名");
            this->ui->lineEdit->setFocus();
        }
        else {
            switch(viewOne)
            {
            case 1:{
                this->ui->book2->show();
                this->ui->book3->show();
                this->ui->book4->show();
                this->ui->checkBox_2->show();
                this->ui->checkBox_3->show();
                this->ui->checkBox_4->show();
                isViewing=false;
                viewOne = 0;
            }
            default:{
                this->ui->checkBox->setText("book1");
                this->ui->book2->show();
                this->ui->book3->show();
                this->ui->book4->show();
                this->ui->checkBox_2->show();
                this->ui->checkBox_3->show();
                this->ui->checkBox_4->show();
                isViewing=false;
                viewOne = 0;
            }
            }
        }
    }
    else {
        QString tem = this->ui->lineEdit->text();

        if(tem==this->ui->checkBox->text())
        {
            this->ui->book2->hide();
            this->ui->book3->hide();
            this->ui->book4->hide();
            this->ui->checkBox_2->hide();
            this->ui->checkBox_3->hide();
            this->ui->checkBox_4->hide();
            isViewing=true;
            viewOne = 1;
        }
        else if(tem==this->ui->checkBox_2->text())
        {
            this->ui->checkBox->setText(this->ui->checkBox_2->text());
            this->ui->book2->hide();
            this->ui->book3->hide();
            this->ui->book4->hide();
            this->ui->checkBox_2->hide();
            this->ui->checkBox_3->hide();
            this->ui->checkBox_4->hide();
            isViewing=true;
            viewOne = 2;
        }
        else if(tem==this->ui->checkBox_3->text())
        {
            this->ui->checkBox->setText(this->ui->checkBox_3->text());
            this->ui->book2->hide();
            this->ui->book3->hide();
            this->ui->book4->hide();
            this->ui->checkBox_2->hide();
            this->ui->checkBox_3->hide();
            this->ui->checkBox_4->hide();
            isViewing=true;
            viewOne = 3;
        }
        else if(tem==this->ui->checkBox_4->text())
        {
            this->ui->checkBox->setText(this->ui->checkBox_4->text());
            this->ui->book2->hide();
            this->ui->book3->hide();
            this->ui->book4->hide();
            this->ui->checkBox_2->hide();
            this->ui->checkBox_3->hide();
            this->ui->checkBox_4->hide();
            isViewing=true;
            viewOne = 4;
        }
        else {
            qDebug()<<"没有书";
            QPushButton *btn1=new QPushButton("添加该书");
            QPushButton *btn2=new QPushButton("重新查找");
            QMessageBox *box = new QMessageBox;
            box->setText("书库中没有这本书，请添加或重新查找");
            box->addButton(btn1,QMessageBox::AcceptRole);
            box->addButton(btn2,QMessageBox::AcceptRole);

            box->exec();
            if(box->clickedButton()==btn1)
            {
                class in *child=new class in();
                connect(child,SIGNAL(addNew(QString)),this,SLOT(getNewOne(QString)));
                emit(showBook(this->ui->lineEdit->text()));
                child->show();
            }

        }
    }
}



void Book::on_out_clicked()
{
    int num[10];
    int t=0;
    if (!ui->checkBox->isChecked()&&!ui->checkBox_2->isChecked()&&!ui->checkBox_3->isChecked()&&!ui->checkBox_4->isChecked())
    {
        QMessageBox::warning(this,"警告","您没有选中任何一本书，请选中");
    }
    else {
        if(ui->checkBox->isChecked())
        {
            num[t]=0;
            t++;
        }
        if(ui->checkBox_2->isChecked())
        {
            num[t]=1;
            t++;
        }
        if(ui->checkBox_3->isChecked())
        {
            num[t]=2;
            t++;
        }
        if(ui->checkBox_4->isChecked())
        {
            num[t]=3;
            t++;
        }

        QString s ="您将删除第";
        for(int i=0;i<t;i++)
        {
            switch (num[i]){
                case 0:{s+="1 ";break;}
            case 1:{s+="2 ";break;}
            case 2:{s+="3 ";break;}
            case 3:{s+="4 ";break;}
            }
        }
        s+="本书";
        QMessageBox::warning(this,"提示",s);

        qDebug()<<t;
        for(int i=0;i<t;i++)
        {
            switch (num[i]) {
            case 0:
            {
                this->ui->book1->hide();
                this->ui->checkBox->hide();
                this->ui->checkBox->setChecked(false);
                break;
            }
            case 1:
            {
                this->ui->book2->hide();
                this->ui->checkBox_2->hide();
                this->ui->checkBox_2->setChecked(false);
                break;
            }
            case 2:
            {
                this->ui->book3->hide();
                this->ui->checkBox_3->hide();
                this->ui->checkBox_3->setChecked(false);
                break;
            }
            case 3:
            {
                this->ui->book4->hide();
                this->ui->checkBox_4->hide();
                this->ui->checkBox_4->setChecked(false);
                break;
            }
        }
        //获得没有被除去的书本编号
        int result[4];
        int re=0;
        for(int j=0;j<4;j++)
        {
            bool fh=false;
            for(int m=0;m<4-t;m++)
            {
                if(j==num[m])
                {
                    fh=true;
                }
            }
            if(!fh)
            {
                result[re]=j;
                re++;
            }
        }
        qDebug()<<re;

//        打印留下的书本
        for(int i=0;i<4-t;i++)
        {
            int nu=0;
            int re;
            for(int j=0;j<4;j++)
            {
                if(j!=num[i])
                {
                    if(nu==i)
                        re=0;
                }
            }


            switch (i) {
            case 0:{
                switch (result[i]) {
                case 0:this->ui->checkBox->setText("book1");
                case 1:this->ui->checkBox->setText("book2");
                case 2:this->ui->checkBox->setText("book3");
                case 3:this->ui->checkBox->setText(this->ui->checkBox_4->text());
                }
                }

            case 1:{
                switch (result[i]) {
                case 0:this->ui->checkBox->setText("book1");
                case 1:this->ui->checkBox->setText("book2");
                case 2:this->ui->checkBox->setText("book3");
                case 3:this->ui->checkBox->setText(this->ui->checkBox_4->text());
                }            }
            case 2:{
                switch (result[i]) {
                case 0:this->ui->checkBox->setText("book1");
                case 1:this->ui->checkBox->setText("book2");
                case 2:this->ui->checkBox->setText("book3");
                case 3:this->ui->checkBox->setText(this->ui->checkBox_4->text());
                }            }
            case 3:{
                switch (result[i]) {
                case 0:this->ui->checkBox->setText("book1");
                case 1:this->ui->checkBox->setText("book2");
                case 2:this->ui->checkBox->setText("book3");
                case 3:this->ui->checkBox->setText(this->ui->checkBox_4->text());
                }            }
            }
        }
        for(int i=0;i<t;i++)
        {
            switch (num[i]){
                case 0:{;break;}
            case 1:{s+="2 ";break;}
            case 2:{s+="3 ";break;}
            case 3:{s+="4 ";break;}
            }
        }
    }
}
}



void Book::on_what_clicked()
{
    QMessageBox::warning(this,"帮助","其他帮助请访问官方网站 www.du.com");
}
