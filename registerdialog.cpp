/*
 * 文件名：registerdialog.cpp
 * 内容：此源程序文件包含了RegisterDialog类成员函数的定义以及部分变量的初始化
 * 作用：创建一个用户注册的窗口
 *      将用户的所有注册信息放入一个作为注册凭证的QString中，以待发送至服务器登记
 *      用户可以在此窗口中进行所有注册信息的填写以及头像的选择
 *      重写鼠标事件（以实现隐藏程序标题栏之后仍旧可以拖动的效果）
 */
#include "registerdialog.h"
#include "ui_registerdialog.h"

#include "libmanagement.h"
#include "logindialog.h"

#include <QRegExp>
#include <QRegExpValidator>


RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    //初始化UI
    ui->setupUi(this);

    this->setWindowTitle("PowerChat 注册");
    this->setWindowFlag(Qt::FramelessWindowHint);

    ui->pushButton_reg->setEnabled(false);//开始时注册按钮设置不可用
    this->setFixedSize(this->width(),this->height());//不让用户拉伸窗口大小

    //连接选择头像按钮的信号和槽
    connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(on_btn_1_clicked()));
    connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(on_btn_2_clicked()));
    connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(on_btn_3_clicked()));
    connect(ui->btn_4,SIGNAL(clicked()),this,SLOT(on_btn_4_clicked()));
    connect(ui->btn_5,SIGNAL(clicked()),this,SLOT(on_btn_5_clicked()));
    connect(ui->btn_6,SIGNAL(clicked()),this,SLOT(on_btn_6_clicked()));
    connect(ui->btn_7,SIGNAL(clicked()),this,SLOT(on_btn_7_clicked()));
    connect(ui->btn_8,SIGNAL(clicked()),this,SLOT(on_btn_8_clicked()));
    connect(ui->btn_9,SIGNAL(clicked()),this,SLOT(on_btn_9_clicked()));
    connect(ui->btn_10,SIGNAL(clicked()),this,SLOT(on_btn_10_clicked()));
    connect(ui->btn_11,SIGNAL(clicked()),this,SLOT(on_btn_11_clicked()));
    connect(ui->btn_12,SIGNAL(clicked()),this,SLOT(on_btn_12_clicked()));
    connect(ui->btn_13,SIGNAL(clicked()),this,SLOT(on_btn_13_clicked()));
    connect(ui->btn_14,SIGNAL(clicked()),this,SLOT(on_btn_14_clicked()));
    connect(ui->btn_15,SIGNAL(clicked()),this,SLOT(on_btn_15_clicked()));

    ui->label_avatarStatus->setAlignment(Qt::AlignCenter);//使提示选择了第几个头像的label中的文字居中显示
    this->avatarSetting = "1";//默认设为1
    ui->label_avatarStatus->setText("您选择了第 1 个头像");

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

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

/*
 * 以下槽函数，用于响应用户界面中组件的操作
 */
void RegisterDialog::on_checkBox_stateChanged(int arg1)//同意用户协议之后允许注册
{
    if(ui->checkBox->isChecked()==true)
        ui->pushButton_reg->setEnabled(true);
    if(ui->checkBox->isChecked()==false)
        ui->pushButton_reg->setEnabled(false);
}

void RegisterDialog::on_pushButton_cancel_clicked()//若取消注册，则关闭注册窗口
{
    this->close();
    LoginDialog* loginDialog = new LoginDialog();
    loginDialog->show();
}

void RegisterDialog::on_pushButton_reg_clicked()//点击确认注册按钮执行
{
    User* newUser;
    QString loginCertificate;
    qDebug()<<"头像编号为："<< this->avatarSetting <<endl;
    if(ui->lineEdit_email->text().trimmed().isEmpty()||ui->lineEdit_phone->text().trimmed().isEmpty()||ui->lineEdit_password->text().trimmed().isEmpty()||ui->lineEdit_userName->text().trimmed().isEmpty())
        //信息填写不全
    {
        QMessageBox::information(this,tr("信息不完整"),tr("您尚有信息为填写完整，请检查后再次提交"));
        return;
    }
    else
    {
        //检查非法字符
        if(ui->lineEdit_userName->text().contains("#")||ui->lineEdit_password->text().contains("#")||
                ui->lineEdit_email->text().contains("#")||ui->lineEdit_phone->text().contains("#"))
        {
            QMessageBox::information(this,"信息不合法","您的输入中包含了非法字符\"#\"，请修改后重新提交！");
            return;
        }

        //检查邮箱格式
        QRegExp exp("[a-zA-Z0-9-_]+@[a-zA-Z0-9-_]+\\.[a-zA-Z]+");//正则表达式
        QRegExpValidator *rval = new QRegExpValidator(exp);
        QString emailToValidate(ui->lineEdit_email->text());
        int pos = 0;
        if(rval->validate(emailToValidate,pos) != QValidator::Acceptable)
        {
            QMessageBox::information(this,"邮箱输入错误","您的输入的邮箱格式不正确，请重新输入！");
            return;
        }


        //用户不设定个性签名，给予一个默认的
        if(ui->lineEdit->text().trimmed().isEmpty())
        {
            this->Bio = "这个人很懒，什么都没有写";
        }
        else
        {
            this->Bio = ui->lineEdit->text().trimmed();//将两侧空白滤去
        }
        //生成注册凭证

        loginCertificate = QString("##REGISTER_CERTIFICATE##%1##%2##%3##%4##%5##%6").arg(ui->lineEdit_userName->text()).arg(ui->lineEdit_password->text()).arg(ui->lineEdit_email->text()).arg(ui->lineEdit_phone->text()).arg(avatarSetting).arg(Bio);
        newUser = new User(loginCertificate.section("##",2,2),
                           loginCertificate.section("##",3,3),
                           loginCertificate.section("##",4,4),
                           loginCertificate.section("##",5,5),
                           loginCertificate.section("##",6,6),
                           loginCertificate.section("##",7,7));

        LibManagement* libManagement = new LibManagement();
        libManagement->hide();
        libManagement->userType = "CUSTOMER";
        libManagement->loginUser = newUser;
        libManagement->userAmount = userListSize;
        libManagement->setupData();
        libManagement->show();
        this->hide();
    }
    userList[userListSize] = newUser;
    userListSize++;
    this->updateUserConfig();
}

void RegisterDialog::on_btn_min_clicked()//最小化窗口
{
    this->setWindowState(Qt::WindowMinimized);
}

void RegisterDialog::on_btn_close_clicked()//关闭窗口
{
    this->close();
    exit(0);
}

/*
 * 以下为头像选择按钮的槽函数定义
 */
void RegisterDialog::on_btn_1_clicked()
{
    avatarSetting = "1";
    ui->label_avatarStatus->setText("您选择了第 1 个头像");
}
void RegisterDialog::on_btn_2_clicked()
{
    avatarSetting = "2";
    ui->label_avatarStatus->setText("您选择了第 2 个头像");
}
void RegisterDialog::on_btn_3_clicked()
{
    avatarSetting = "3";
    ui->label_avatarStatus->setText("您选择了第 3 个头像");
}
void RegisterDialog::on_btn_4_clicked()
{
    avatarSetting = "4";
    ui->label_avatarStatus->setText("您选择了第 4 个头像");
}
void RegisterDialog::on_btn_5_clicked()
{
    avatarSetting = "5";
    ui->label_avatarStatus->setText("您选择了第 5 个头像");
}
void RegisterDialog::on_btn_6_clicked()
{
    avatarSetting = "6";
    ui->label_avatarStatus->setText("您选择了第 6 个头像");
}
void RegisterDialog::on_btn_7_clicked()
{
    avatarSetting = "7";
    ui->label_avatarStatus->setText("您选择了第 7 个头像");
}
void RegisterDialog::on_btn_8_clicked()
{
    avatarSetting = "8";
    ui->label_avatarStatus->setText("您选择了第 8 个头像");
}
void RegisterDialog::on_btn_9_clicked()
{
    avatarSetting = "9";
    ui->label_avatarStatus->setText("您选择了第 9 个头像");
}
void RegisterDialog::on_btn_10_clicked()
{
    avatarSetting = "10";
    ui->label_avatarStatus->setText("您选择了第 10 个头像");
}
void RegisterDialog::on_btn_11_clicked()
{
    avatarSetting = "11";
    ui->label_avatarStatus->setText("您选择了第 11 个头像");
}
void RegisterDialog::on_btn_12_clicked()
{
    avatarSetting = "12";
    ui->label_avatarStatus->setText("您选择了第 12 个头像");
}
void RegisterDialog::on_btn_13_clicked()
{
    avatarSetting = "13";
    ui->label_avatarStatus->setText("您选择了第 13 个头像");
}
void RegisterDialog::on_btn_14_clicked()
{
    avatarSetting = "14";
    ui->label_avatarStatus->setText("您选择了第 14 个头像");
}
void RegisterDialog::on_btn_15_clicked()
{
    avatarSetting = "15";
    ui->label_avatarStatus->setText("您选择了第 15 个头像");
}

void RegisterDialog::loadUserInfo()
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

void RegisterDialog::updateUserConfig()
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

void RegisterDialog::on_lineEdit_userName_editingFinished()
{
    bool available = true;
    for (int i = 0;i < userListSize;i++) {
        if(userList[i]->userName == ui->lineEdit_userName->text())
        {
            available = false;
            ui->label_username_hint->setText("用户名已被占用");
            ui->label_username_hint->setStyleSheet("color:red;background:transparent;");
            ui->lineEdit_userName->setStyleSheet("color:red");
            return;
        }
    }
    if(available)
    {
        ui->label_username_hint->setText("用户名可用");
        ui->label_username_hint->setStyleSheet("color:green;background:transparent;");
        ui->lineEdit_userName->setStyleSheet("");
    }
}

void RegisterDialog::on_lineEdit_email_editingFinished()
{
    if(ui->lineEdit_email->text().trimmed() == "")
        return;
    //检查邮箱格式
    QRegExp exp("[a-zA-Z0-9-_]+@[a-zA-Z0-9-_]+\\.[a-zA-Z]+");//正则表达式
    QRegExpValidator *rval = new QRegExpValidator(exp);
    QString emailToValidate(ui->lineEdit_email->text());
    int pos = 0;
    if(rval->validate(emailToValidate,pos) != QValidator::Acceptable)
    {
        ui->label_email_hint->setStyleSheet("color:red;background:transparent;");
        ui->label_email_hint->setText("邮箱格式不正确");
    }
    else{
        ui->label_email_hint->setStyleSheet("background:transparent;");
        ui->label_email_hint->setText("");
    }
}
