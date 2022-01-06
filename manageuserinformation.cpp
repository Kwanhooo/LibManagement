#include "manageuserinformation.h"
#include "ui_manageuserinformation.h"

manageUserInformation::manageUserInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manageUserInformation)
{
    ui->setupUi(this);

}

manageUserInformation::~manageUserInformation()
{
    delete ui;
}

void manageUserInformation::init(QString s)
{
    QStringList slist = {"Normal","Logged off","Illegal freezing"};
    this->ui->label_userName->setText(s);
    int sex = rand()%2;
    int age = rand()%45+15;
    int status = rand()%10;
    if(sex==0){
        ui->label_Sex->setText("Man");
        QIcon man_Icon(":/man.png");
        ui->pushButton_head->setIcon(man_Icon);
        ui->pushButton_head->setIconSize(QSize(70,70));
        ui->radioButton_Man->setChecked(1);
    }
    else {
        ui->label_Sex->setText("Woman");
        QIcon woman_Icon(":/woman.png");
        ui->pushButton_head->setIcon(woman_Icon);
        ui->pushButton_head->setIconSize(QSize(70,70));
        ui->radioButton_Woman->setChecked(1);
    }

    ui->label_Age->setText(QString::number(age));
    ui->spinBox->setValue(age);
    ui->spinBox->setRange(15,60);

    ui->comboBox->addItems(slist);

    if(status==0){
        ui->comboBox->setCurrentIndex(2);
        ui->label_Status->setText("Illegal freezing");
        ui->label_Status->setStyleSheet("color:#b2bbbe;");
        ui->label_statuslab->setStyleSheet("color:#b2bbbe;");
        ui->label_Age->setStyleSheet("color:#b2bbbe;");
        ui->label_agelab->setStyleSheet("color:#b2bbbe;");
        ui->label_Sex->setStyleSheet("color:#b2bbbe;");
        ui->label_sexlab->setStyleSheet("color:#b2bbbe;");
        ui->label_userName->setStyleSheet("color:#b2bbbe;");
        ui->label_usernamelab->setStyleSheet("color:#b2bbbe;");
        ui->label_listlab->setStyleSheet("color:#b2bbbe;");
    }
    else if (status==1){
        ui->comboBox->setCurrentIndex(1);
        ui->label_Status->setText("Logged off");
    }
    else {
        ui->comboBox->setCurrentIndex(0);
        ui->label_Status->setText("Normal");
    }

    QIcon modfiy_Icon(":/modify.png");
    this->ui->pushButton_modfiyUserName->setIcon(modfiy_Icon);
    this->ui->pushButton_modfiySex->setIcon(modfiy_Icon);
    this->ui->pushButton_modfiyAge->setIcon(modfiy_Icon);
    this->ui->pushButton_modfiyStatus->setIcon(modfiy_Icon);

    this->ui->pushButton_modfiyUserName->setIconSize(QSize(12,12));
    this->ui->pushButton_modfiySex->setIconSize(QSize(12,12));
    this->ui->pushButton_modfiyAge->setIconSize(QSize(12,12));
    this->ui->pushButton_modfiyStatus->setIconSize(QSize(12,12));

    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->radioButton_Man);
    group->addButton(ui->radioButton_Woman);


    this->ui->lineEdit_userName->hide();
    this->ui->radioButton_Man->hide();
    this->ui->radioButton_Woman->hide();
    this->ui->spinBox->hide();
    this->ui->comboBox->hide();

    QStringListModel *listmodel = new QStringListModel(list);
    ui->listView->setModel(listmodel);
}

void manageUserInformation::on_pushButton_clicked()
{
    QString s  = "Are you sure you want to modify the information of user <b>"+ui->label_userName->text()+"</b>?";
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(NULL,"Confrim",s,QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)this->close();
}

void manageUserInformation::on_pushButton_modfiyUserName_clicked()
{
    if(i1==0){
        i1 = 1;
        QIcon confirm_Icon(":/confirm.png");
        this->ui->pushButton_modfiyUserName->setIcon(confirm_Icon);
        this->ui->pushButton_modfiyUserName->setIconSize(QSize(12,12));
        ui->lineEdit_userName->show();
        ui->lineEdit_userName->setText(ui->label_userName->text());
        ui->lineEdit_userName->setFocus();
        ui->lineEdit_userName->selectAll();
        ui->label_userName->hide();
    }
    else {
        i1 = 0;
        QIcon modfiy_Icon(":/modify.png");
        this->ui->pushButton_modfiyUserName->setIcon(modfiy_Icon);
        this->ui->pushButton_modfiyUserName->setIconSize(QSize(12,12));
        ui->label_userName->setText(ui->lineEdit_userName->text());
        ui->label_userName->show();
        ui->lineEdit_userName->hide();
    }
}

void manageUserInformation::on_radioButton_Woman_clicked()
{

}

void manageUserInformation::on_pushButton_modfiySex_clicked()
{
    if(i2==0){
        i2 = 1;
        QIcon confirm_Icon(":/confirm.png");
        this->ui->pushButton_modfiySex->setIcon(confirm_Icon);
        this->ui->pushButton_modfiySex->setIconSize(QSize(12,12));
        ui->radioButton_Man->show();
        ui->radioButton_Woman->show();
        if(ui->radioButton_Man->isChecked())ui->radioButton_Man->setFocus();
        else ui->radioButton_Woman->setFocus();
        ui->label_Sex->hide();
    }
    else{
        i2 = 0;
        QIcon modfiy_Icon(":/modify.png");
        this->ui->pushButton_modfiySex->setIcon(modfiy_Icon);
        this->ui->pushButton_modfiySex->setIconSize(QSize(12,12));
        if(ui->radioButton_Man->isChecked()){
            ui->label_Sex->setText("Man");
            QIcon man_Icon(":/man.png");
            ui->pushButton_head->setIcon(man_Icon);
            ui->pushButton_head->setIconSize(QSize(70,70));
            ui->radioButton_Man->setChecked(1);
        }
        else{
            ui->label_Sex->setText("Woman");
            QIcon woman_Icon(":/woman.png");
            ui->pushButton_head->setIcon(woman_Icon);
            ui->pushButton_head->setIconSize(QSize(70,70));
            ui->radioButton_Woman->setChecked(1);
        }
        ui->radioButton_Man->hide();
        ui->radioButton_Woman->hide();
        ui->label_Sex->show();
    }
}

void manageUserInformation::on_pushButton_modfiyAge_clicked()
{
    if(i3==0){
        i3 = 1;
        QIcon confirm_Icon(":/confirm.png");
        this->ui->pushButton_modfiyAge->setIcon(confirm_Icon);
        this->ui->pushButton_modfiyAge->setIconSize(QSize(12,12));
        ui->spinBox->show();
        ui->label_Age->hide();
    }
    else {
        i3 = 0;
        QIcon modfiy_Icon(":/modify.png");
        this->ui->pushButton_modfiyAge->setIcon(modfiy_Icon);
        this->ui->pushButton_modfiyAge->setIconSize(QSize(12,12));
        QString num =QString::number(ui->spinBox->value());
        ui->label_Age->setText(num);
        ui->label_Age->show();
        ui->spinBox->hide();
    }
}

void manageUserInformation::on_pushButton_modfiyStatus_clicked()
{
    if(i4==0){
        i4 = 1;
        QIcon confirm_Icon(":/confirm.png");
        this->ui->pushButton_modfiyStatus->setIcon(confirm_Icon);
        this->ui->pushButton_modfiyStatus->setIconSize(QSize(12,12));
        ui->comboBox->show();
        ui->label_Status->hide();
    }
    else {
        i4 = 0;
        QIcon modfiy_Icon(":/modify.png");
        this->ui->pushButton_modfiyStatus->setIcon(modfiy_Icon);
        this->ui->pushButton_modfiyStatus->setIconSize(QSize(12,12));
        ui->label_Status->setText(ui->comboBox->currentText());
        ui->comboBox->hide();
        ui->label_Status->show();
    }
}

void manageUserInformation::on_pushButton_returnbook_clicked()
{
    returnbook *rb = new returnbook();
    rb->init(ui->label_userName->text(),0);
    rb->show();
}

void manageUserInformation::on_pushButton_borrowbook_clicked()
{
    returnbook *rb = new returnbook();
    rb->init(ui->label_userName->text(),1);
    rb->show();
}

void manageUserInformation::on_pushButton_2_clicked()
{
    this->close();
}

void manageUserInformation::on_pushButton_3_clicked()
{
    QMessageBox::information(nullptr,"Information","已成功保存！");
}
