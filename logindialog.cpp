/*
 * 文件名：logindialog.cpp
 * 内容：此源程序文件包含了LoginDialog类成员函数的定义以及部分变量的初始化
 * 作用：创建一个用户登录窗口
 *      将用户的账号密码放入一个作为登陆凭证的QString中，以待发送至服务器检查
 *      能够创建一个用户注册窗口，让没有账号的用户进行注册
 *      重写鼠标事件（以实现隐藏程序标题栏之后仍旧可以拖动的效果）
 */
#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "libmanagement.h"

#include "librarymanagemainwindow.h"

LoginDialog::LoginDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//不让用户拉伸窗口大小
    this->setWindowTitle("PowerChat 登录");
    this->setWindowFlag(Qt::FramelessWindowHint);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);//设置LineEdit的掩码模式

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setRenderHint(QPainter::Antialiasing); // 反锯齿;
    p.setPen(Qt::transparent);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(), 30, 30);
    setMask(bmp);
    loadUserInfo();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/*
 * 以下槽函数，用于响应用户界面中组件的操作
 */
void LoginDialog::on_pushButton_login_clicked()//按下登录按钮之后执行的操作
{
    QString loginCertificate; //登录凭证
    if (ui->lineEdit_account->text().trimmed() != "" && ui->lineEdit_password->text() != "")
    {
        loginCertificate = QString("##LOGIN_CERTIFICATE##%1##%2").arg(ui->lineEdit_account->text()).arg(ui->lineEdit_password->text());
        //##LOGIN_CERTIFICATE##userName##password

        if(loginCertificate.section("##",2,2)=="admin")

        {
            //从这里连接到塽哥的屎山
            libraryManageMainWindow *librarymanagemainwindow = new libraryManageMainWindow();
            librarymanagemainwindow->show();
            this->close();
        }
        else
        {
            User* loginUser = validateIdentity(loginCertificate.section("##",2,2),loginCertificate.section("##",3,3));
            if(loginUser != nullptr)

            {
                LibManagement* libManagement = new LibManagement();
                libManagement->hide();
                libManagement->userType = "CUSTOMER";
                libManagement->loginUser = loginUser;
                libManagement->userAmount = userListSize;
                libManagement->setupData();
                libManagement->show();
                close();
            }
            else
            {
                QMessageBox::information(nullptr,tr("登录错误"),tr("账号密码错误"));
                ui->lineEdit_password->setFocus();
                ui->lineEdit_password->selectAll();
            }
        }

    }
    else
    {
        QMessageBox::information(this, "账号或密码错误", "用户名或密码为空，请检查后重新输入");
    }
}

void LoginDialog::on_pushButton_reg_clicked()//点击注册之后新建一个注册窗口，并将登录窗口关闭
{
    this->hide();
    regDialog = new RegisterDialog();
    regDialog->exec();


}

void LoginDialog::on_btn_min_clicked()//最小化登录窗口
{
    this->setWindowState(Qt::WindowMinimized);
}

void LoginDialog::on_btn_close_clicked()//关闭登录窗口，直接退出程序
{
    this->close();
    exit(0);
}

void LoginDialog::loadUserInfo()
{
    //从文本流中载入用户配置
    QFile config("UserListConfig.user");
    qDebug() << "读取用户信息...";
    if(config.open(QIODevice::ReadOnly | QIODevice :: Text))
    {
        QByteArray a = QByteArray::fromBase64(config.readAll());
        QString b = QString(a);
        qDebug()<<a<<endl;
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
                qDebug() << password;
                read >> email;
                read >> phone;
                read >> avatar;
                read >> Bio;
                userList[userListSize] = new User(userName, password, email, phone,avatar,Bio);

                qDebug()<<"Index = "<< userListSize <<endl;
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

User* LoginDialog::validateIdentity(QString username, QString password)
{
    for (int i = 0;i < userListSize;i++)
    {
        if(userList[i]->userName == username && userList[i]->password == password)
        {
            qDebug()<<"是对的呢"<<endl;
            return userList[i];
        }
    }
    qDebug()<<"错啦！"<<endl;
    return nullptr;
}
