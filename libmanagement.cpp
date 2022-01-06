#include "libmanagement.h"
#include "ui_libmanagement.h"

#include "logindialog.h"
#include "searchwidget.h"
#include "mainpagewidget.h"
#include "mewidget.h"

LibManagement::LibManagement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibManagement)
{
    ui->setupUi(this);

    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//不让用户拉伸窗口大小
    this->setWindowTitle("LibManagement 登录");
    this->setWindowFlag(Qt::FramelessWindowHint);

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setRenderHint(QPainter::Antialiasing); // 反锯齿;
    p.setPen(Qt::transparent);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(), 30, 30);
    setMask(bmp);

    QIcon btn_home_icon(":/home.png");
    QIcon btn_me_icon(":/me.png");
    QIcon btn_search_icon(":/search.png");
    QIcon btn_logout_icon(":/logout.png");
    QIcon btn_exit_icon(":/exit.png");

    ui->btn_home->setIcon(btn_home_icon);
    ui->btn_home->setIconSize(QSize(40,40));
    ui->btn_me->setIcon(btn_me_icon);
    ui->btn_me->setIconSize(QSize(40,40));
    ui->btn_search->setIcon(btn_search_icon);
    ui->btn_search->setIconSize(QSize(40,40));
    ui->btn_logout->setIcon(btn_logout_icon);
    ui->btn_logout->setIconSize(QSize(35,35));
    ui->btn_exit->setIcon(btn_exit_icon);
    ui->btn_exit->setIconSize(QSize(40,40));

    connect(ui->btn_min,SIGNAL(clicked()),this,SLOT(on_btn_min_clicked()));
    connect(ui->btn_close,SIGNAL(clicked()),this,SLOT(on_btn_close_clicked()));
    connect(ui->btn_search,SIGNAL(clicked()),this,SLOT(on_btn_search_clicked()));
    connect(ui->btn_home,SIGNAL(clicked()),this,SLOT(on_btn_home_clicked()));
    connect(ui->btn_logout,SIGNAL(clicked()),this,SLOT(on_btn_logout_clicked()));
    connect(ui->btn_exit,SIGNAL(clicked()),this,SLOT(on_btn_close_clicked()));
    connect(ui->btn_me,SIGNAL(clicked()),this,SLOT(on_btn_me_clicked()));

    bookAmount = 63927;
}

LibManagement::~LibManagement()
{
    delete ui;
}

void LibManagement::setupData()
{
    MainPageWidget* mainPageWidget = new MainPageWidget(this);
    currentDisplayWidget = mainPageWidget;
    mainPageWidget->userAmount = userAmount;
    mainPageWidget->bookAmount = bookAmount;
    mainPageWidget->setupData();
    mainPageWidget->move(ORIGIN_X,ORIGIN_Y);
    mainPageWidget->show();
    ui->label_Bio->setText("    "+this->loginUser->Bio);
    if(loginUser->userName == "mq")
    {
        loginUser->avatar = "666.jpg";
        ui->label_avatar->setStyleSheet(QString("background-color:white;border-radius:30px;"));
        QPixmap mqPic(":/"+loginUser->avatar);
        ui->label_avatar->setPixmap(mqPic.scaled(50,50));
    }
    else
    {
        ui->label_avatar->setStyleSheet(QString("background-color:white;border-radius:30px;"));
        QPixmap pic(":/"+loginUser->avatar+".png");
        ui->label_avatar->setPixmap(pic.scaled(60,60));
    }
}

void LibManagement::updateUserConfig()
{
    //文件保存
    QFile config("UserListConfig.user");
    if(config.open(QIODevice::WriteOnly)) //以文本文式写入
    {
        QByteArray output;
        for(int i = 0; i< userListSize; i++)
        {
            output.append(userList[i]->userName.toUtf8());
            output.append(QString(" ").toUtf8());
            output.append(userList[i]->password.toUtf8());
            output.append(QString(" ").toUtf8());
            output.append(userList[i]->email.toUtf8());
            output.append(QString(" ").toUtf8());
            output.append(userList[i]->phone.toUtf8());
            output.append(QString(" ").toUtf8());
            output.append(userList[i]->avatar.toUtf8());
            output.append(QString(" ").toUtf8());
            output.append(userList[i]->Bio.toUtf8());
            output.append(QString(" ").toUtf8());
        }
        qDebug()<<output<<endl;

        config.write(output.toBase64());
        config.close();
    }
    else
    {
        QMessageBox::warning(this, "输出错误", "用户列表配置文件打开失败！", QMessageBox::Yes);
        close();
    }
}

void LibManagement::onUserInfoChanged(User *user,QString reason)
{
    if(user != nullptr)
    {
        this->loginUser = new User(user->userName,user->password,user->email,user->phone,user->avatar,user->Bio);
        ui->label_Bio->setText("    "+loginUser->Bio);

        loadUserInfo();
        for (int i = 0;i < userListSize;i++)
        {
            if(userList[i]->userName == loginUser->userName)
            {
                userList[i] = loginUser;
                break;
            }
        }
        updateUserConfig();
    }

    if(reason == "OK")
    {
        qDebug()<<"show main widget"<<endl;
        if(currentDisplayWidget != nullptr){
            delete currentDisplayWidget;
            currentDisplayWidget = nullptr;
        }
        MainPageWidget* mainPageWidget = new MainPageWidget(this);
        mainPageWidget->bookAmount = bookAmount;
        mainPageWidget->userAmount = userAmount;
        mainPageWidget->setupData();
        currentDisplayWidget = mainPageWidget;
        mainPageWidget->move(ORIGIN_X,ORIGIN_Y);
        mainPageWidget->show();
    }


}


void LibManagement::on_btn_min_clicked()//最小化登录窗口
{
    this->setWindowState(Qt::WindowMinimized);
}

void LibManagement::on_btn_close_clicked()//关闭登录窗口，直接退出程序
{
    this->close();
    exit(0);
}

void LibManagement::on_btn_search_clicked()
{
    qDebug()<<"show search widget"<<endl;
    if(currentDisplayWidget != nullptr){
        delete currentDisplayWidget;
        currentDisplayWidget = nullptr;
    }
    SearchWidget* searchWidget = new SearchWidget(this);
    currentDisplayWidget = searchWidget;
    searchWidget->move(ORIGIN_X,ORIGIN_Y);
    searchWidget->show();
}

void LibManagement::on_btn_home_clicked()
{
    qDebug()<<"show main widget"<<endl;
    if(currentDisplayWidget != nullptr){
        delete currentDisplayWidget;
        currentDisplayWidget = nullptr;
    }
    MainPageWidget* mainPageWidget = new MainPageWidget(this);
    mainPageWidget->bookAmount = bookAmount;
    mainPageWidget->userAmount = userAmount;
    mainPageWidget->setupData();
    currentDisplayWidget = mainPageWidget;
    mainPageWidget->move(ORIGIN_X,ORIGIN_Y);
    mainPageWidget->show();
}

void LibManagement::on_btn_logout_clicked()
{
    this->close();
    LoginDialog* loginDialog = new LoginDialog();
    loginDialog->show();
    delete this;
}

void LibManagement::on_btn_me_clicked()
{
    ui->setupUi(this);
    return;
    qDebug()<<"show search widget"<<endl;
    if(currentDisplayWidget != nullptr){
        delete currentDisplayWidget;
        currentDisplayWidget = nullptr;
    }
    MeWidget* meWidget = new MeWidget(this);
    currentDisplayWidget = meWidget;
    meWidget->currentUser = loginUser;
    meWidget->setupData();
    meWidget->move(ORIGIN_X,ORIGIN_Y);
    meWidget->show();
}

void LibManagement::loadUserInfo()
{
    //从文本流中载入用户配置
    QFile config("UserListConfig.user");
    qDebug() << "读取用户信息...";
    if(config.open(QIODevice::ReadOnly | QIODevice :: Text))
    {
        QByteArray a = QByteArray::fromBase64(config.readAll());
        QString b = QString(a);
        QTextStream read(&b);

        QString userName = "";
        QString password = "";
        QString email = "";
        QString phone = "";
        QString avatar = "";
        QString Bio = "";

        userListSize = 0;

        while(!read.atEnd())
        {
            read >> userName;
            if(userName != "")
            {
                qDebug() << userName;
                read >> password;
                read >> email;
                read >> phone;
                read >> avatar;
                read >> Bio;
                userList[userListSize] = new User(userName, password, email, phone,avatar,Bio);

                qDebug()<<"userListSize = "<< userListSize <<endl;
                userListSize++;
            }
            else
            {
                break;
            }
        }
        config.close();
    }
    else
    {
        QMessageBox::warning(this, "读取错误", "用户列表配置文件打开失败！现在没有任何用户信息！", QMessageBox::Yes);
        close();
    }
}
