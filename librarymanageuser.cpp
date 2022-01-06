#include "librarymanageuser.h"
#include "ui_librarymanageuser.h"

libraryManageUser::libraryManageUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::libraryManageUser)
{
    ui->setupUi(this);

    QIcon search_Icon(":/search.png");
    ui->pushButton_search->setIcon(search_Icon);
    ui->pushButton_search->setIconSize(QSize(20,20));

    QIcon add_Icon(":/add.png");
    ui->pushButton_add->setIcon(add_Icon);
    ui->pushButton_add->setIconSize(QSize(20,20));


    QIcon help_Icon(":/help.png");
    ui->pushButton_help->setIcon(help_Icon);
    ui->pushButton_help->setIconSize(QSize(20,20));

    connect(this->ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(manageUser(QModelIndex)));
    //connect(this->ui->listView,SIGNAL(hover(QModeIndex)),this,SLOT(manageUser(QModelIndex)));
   // connect(this->ui->pushButton_help,SIGNAL(QEvent::Enter()),this,SLOT(show()));

    ui->lineEdit->setFocus();
    ui->pushButton_add->setToolTip("Click here to add a new user");
    ui->pushButton_help->setToolTip("Click here for help");
}

libraryManageUser::~libraryManageUser()
{
    delete ui;
}

void libraryManageUser::init()
{
    QFile *file = new QFile("user.txt");
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    QString line = in.readLine();
    int n = 0;
    while(line!=nullptr){
       // qDebug()<<"111";
        n++;
        line = in.readLine();
    }
    file->close();

    QString s = "Total number of users: "+QString::number(n);
    ui->label_numOfUser->setText(s);
}


void libraryManageUser::on_pushButton_search_clicked()
{
    std::vector<QString> v1;
    QStringList list;
    QString s = ui->lineEdit->text();
    QFile *file = new QFile("user.txt");
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    QString line = in.readLine();
    int n = 0;
    while(line!=nullptr){
       // qDebug()<<"111";
        qDebug()<<line;
        if(line.contains(s,Qt::CaseInsensitive)){
            list<<line;
            v1.push_back(line);
        }
        line = in.readLine();
    }
    QStringListModel *listmodel = new QStringListModel(list);
    v = v1;
    ui->listView->setModel(listmodel);
    file->close();
    ui->listView->setFocus();

}

void libraryManageUser::manageUser(QModelIndex index)
{
    qDebug()<<"111";
    int i = index.row();
    QString name = v.at(i);
    manageUserInformation *m = new manageUserInformation();
    m->init(name);
    m->show();
}

void libraryManageUser::showImgHelp()
{

}

void libraryManageUser::on_pushButton_add_clicked()
{
    addNewUser *addnewuser = new addNewUser();
    addnewuser->show();
}

void libraryManageUser::on_pushButton_help_clicked()
{
    QMessageBox::information(NULL,"Information","如您有疑问,请联系QQ客服1195721944!");
}
