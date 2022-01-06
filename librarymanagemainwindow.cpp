#include "librarymanagemainwindow.h"
#include "ui_librarymanagemainwindow.h"


libraryManageMainWindow::libraryManageMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::libraryManageMainWindow)
{
    this->setStyleSheet("background-color:#f3f6fd;");
    ui->setupUi(this);
    libmanageuser->setParent(this);
    libmanageuser->hide();
    getTime();

    ui->pushButton_manageBook->setToolTip("书籍管理");
    ui->pushButton_manageUser->setToolTip("用户管理");
    ui->pushButton_cancellation->setToolTip("注销");
    ui->pushButton_exit->setToolTip("退出");

    QFile *file = new QFile("user.txt");
    int n = 0;
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    QString line = in.readLine();
    while(line!=nullptr){
       // qDebug()<<"111";
        n++;
        line = in.readLine();
    }
    file->close();

    QString s = QString::number(n)+"人";
    this->ui->label_numUser->setText(s);

    //ui->label_administrator->setStyleSheet("color:#393733;");
    ui->pushButton_manageBook->setAutoFillBackground(true);

   // ui->label_title->setStyleSheet("color:#eef7f2;");

    QIcon book_Icon(":/booklogo.png");
    ui->pushButton_manageBook->setIcon(book_Icon);
    ui->pushButton_manageBook->setIconSize(QSize(50,50));

    QIcon user_Icon(":/userlogo.png");
    ui->pushButton_manageUser->setIcon(user_Icon);
    ui->pushButton_manageUser->setIconSize(QSize(50,50));

    QIcon cancellation_Icon(":/cancellation.png");
    ui->pushButton_cancellation->setIcon(cancellation_Icon);
    ui->pushButton_cancellation->setIconSize(QSize(50,50));

    QIcon exit_Icon(":/exit.png");
    ui->pushButton_exit->setIcon(exit_Icon);
    ui->pushButton_exit->setIconSize(QSize(50,50));


    t->setInterval(10);
    connect(this,SIGNAL(beginTime()),t,SLOT(start()));
    connect(this,SIGNAL(beginTime()),t,SLOT(stop()));
//    connect(t,&QTimer::timeout,this,&libraryManageMainWindow::updateTime);
    connect(t,SIGNAL(timeout()),this,SLOT(updateTime()));
    t->start(1000);

}

libraryManageMainWindow::~libraryManageMainWindow()
{
    delete ui;
}

void libraryManageMainWindow::getTime()
{
    time_t currentTime;
        time(&currentTime);
        struct tm *p;
        p = localtime(&currentTime);
        hour = p->tm_hour;
        min = p->tm_min;
        seconds = p->tm_sec;
        emit beginTime();
        qDebug()<<"here";
}

QString libraryManageMainWindow::changeIntToString(int p)
{
    if(p>=10)return QString::number(p);
    else {
        return "0"+QString::number(p);
    }
}

void libraryManageMainWindow::updateTime(){
    ui->lcdNumber_hour->setDigitCount(2);
    ui->lcdNumber_min->setDigitCount(2);
    ui->lcdNumber_sec->setDigitCount(2);

    seconds++;
    if(seconds>=60){
        seconds = 0;
        min++;
        if(min>=60){
            min = 0;
            hour++;
            if(hour>=24)hour=0;
        }
    }
    ui->lcdNumber_hour->display(changeIntToString(hour));
    ui->lcdNumber_min->display(changeIntToString(min));
    ui->lcdNumber_sec->display(changeIntToString(seconds));
}

void libraryManageMainWindow::on_pushButton_manageUser_clicked()
{
    libmanageuser->init();
    libmanageuser->show();
    libmanageuser->move(320,100);

    ui->groupBox->hide();
    ui->groupBox_2->hide();
    ui->groupBox_3->hide();
    book->hide();
}

void libraryManageMainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void libraryManageMainWindow::on_pushButton_manageBook_clicked()
{
    //zheli这里接入afan的shishan
    book->setParent(this);
    book->show();
    book->move(250,70);
    ui->groupBox->hide();
    ui->groupBox_2->hide();
    libmanageuser->hide();
    ui->groupBox_3->hide();
    ui->label_12->hide();
}

void libraryManageMainWindow::on_pushButton_cancellation_clicked()
{
    LoginDialog *l = new LoginDialog();
    l->show();
    delete this;
}
