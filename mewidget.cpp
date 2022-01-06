#include "mewidget.h"
#include "ui_mewidget.h"

MeWidget::MeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeWidget)
{
    ui->setupUi(this);

    loadUserInfo();
}

MeWidget::~MeWidget()
{
    delete ui;
}

void MeWidget::setupData()
{
    //TODO:初始化工作
    ui->lineEdit_username->setText(currentUser->userName);
    ui->lineEdit_bio->setText(currentUser->Bio);
    ui->lineEdit_email->setText(currentUser->email);
    ui->lineEdit_phone->setText(currentUser->phone);
    ui->lineEdit_password->setText(currentUser->password);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}


void MeWidget::on_pushButton_showPassword_clicked()
{
    if(ui->lineEdit_password->echoMode()==QLineEdit::Normal)
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    else
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
}

void MeWidget::on_btn_OK_clicked()
{
    currentUser->userName = ui->lineEdit_username->text();
    currentUser->Bio = ui->lineEdit_bio->text();
    currentUser->email = ui->lineEdit_email->text();
    currentUser->phone = ui->lineEdit_phone->text();
    currentUser->password = ui->lineEdit_password->text();

    connect(this,SIGNAL(userInfoChanged(User*,QString)),parent(),SLOT(onUserInfoChanged(User*,QString)));
    emit(userInfoChanged(currentUser,"OK"));
}

void MeWidget::on_btn_cancel_clicked()
{
    connect(this,SIGNAL(userInfoChanged(User*)),parent(),SLOT(onUserInfoChanged(User*)));
    emit(userInfoChanged(nullptr,"APPLY"));
}

void MeWidget::on_btn_apply_clicked()
{
    currentUser->userName = ui->lineEdit_username->text();
    currentUser->Bio = ui->lineEdit_bio->text();
    currentUser->email = ui->lineEdit_email->text();
    currentUser->phone = ui->lineEdit_phone->text();
    currentUser->password = ui->lineEdit_password->text();

    connect(this,SIGNAL(userInfoChanged(User*,QString)),parent(),SLOT(onUserInfoChanged(User*,QString)));
    emit(userInfoChanged(currentUser,"APPLY"));
    QMessageBox::information(this,"修改成功","您修改的信息已保存！");
}

void MeWidget::on_pushButton_Q1_clicked()
{
    QMessageBox::information(this,"程序出现了问题？","很抱歉给您带来了不愉快的体验\n请将问题反馈至\ncustomer_service@libmanagement.com");
    initVBScripts();
    main_scrpt->call("fun()");
}

void MeWidget::on_pushButton_Q2_clicked()
{
    QMessageBox::information(this,"邮箱不可用？","请在此页面重新绑定邮箱！");
}

void MeWidget::on_pushButton_Q3_clicked()
{
    QMessageBox::information(this,"忘记密码？","请联系 customer_service@libmanagement.com");
    initVBScripts();
    main_scrpt->call("fun()");
}

void MeWidget::on_pushButton_Q4_clicked()
{
    QMessageBox::information(this,"手机号不可用？","请在此页面重新绑定手机！");
}

void MeWidget::on_pushButton_Q5_clicked()
{
    QMessageBox::information(this,"我要绑定的手机号已经注册了，怎么办？","请在此页面重新绑定手机！或联系 customer_service@libmanagement.com");
}

bool MeWidget::initVBScripts()
{
    scrpt_mgr = new QAxScriptManager(this);
    main_scrpt = scrpt_mgr->load(":/email_command.vbs", "MyScript");
    if(!main_scrpt)
        return false;
    return true;
}

void MeWidget::loadUserInfo()
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


void MeWidget::on_lineEdit_username_editingFinished()
{
    bool available = true;
    for (int i = 0;i < userListSize;i++) {
        if(userList[i]->userName == ui->lineEdit_username->text()&&ui->lineEdit_username->text() != currentUser->userName)
        {
            available = false;
            ui->label_username_hint->setText("用户名已被占用");
            ui->label_username_hint->setStyleSheet("color:red;background:transparent;");
            ui->lineEdit_username->setStyleSheet("color:red");
            return;
        }
    }
    if(ui->lineEdit_username->text().contains(" ")|| ui->lineEdit_username->text().trimmed()== "")
    {
        available = false;
        ui->label_username_hint->setText("用户名不能含有空格");
        ui->label_username_hint->setStyleSheet("color:red;background:transparent;");
        ui->lineEdit_username->setStyleSheet("color:red");
        return;
    }

    if(available&&ui->lineEdit_username->text() != currentUser->userName)
    {
        ui->label_username_hint->setText("用户名可用");
        ui->label_username_hint->setStyleSheet("color:green;background:transparent;");
        ui->lineEdit_username->setStyleSheet("");
    }
}

void MeWidget::on_lineEdit_email_editingFinished()
{
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
    else if(ui->lineEdit_email->text() != currentUser->email){
        ui->label_email_hint->setStyleSheet("background:transparent;");
        ui->label_email_hint->setText("");
    }
}
