#ifndef MEWIDGET_H
#define MEWIDGET_H

#include <QWidget>
#include <QMessageBox>

#include <ActiveQt>

#include "user.h"

namespace Ui {
class MeWidget;
}

class MeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MeWidget(QWidget *parent = nullptr);
    ~MeWidget();

    User* currentUser;
    void setupData();

private slots:

    void on_pushButton_showPassword_clicked();


    void on_btn_OK_clicked();

    void on_btn_cancel_clicked();

    void on_btn_apply_clicked();

    void on_pushButton_Q1_clicked();

    void on_pushButton_Q2_clicked();

    void on_pushButton_Q3_clicked();

    void on_pushButton_Q4_clicked();

    void on_pushButton_Q5_clicked();

    void on_lineEdit_email_editingFinished();

    void on_lineEdit_username_editingFinished();

private:
    Ui::MeWidget *ui;

    QAxScriptManager *scrpt_mgr;
    QAxScript *main_scrpt;
     bool initVBScripts();

     int userListSize;
     const static int MAX_USERS_AMOUNT = 100;
     User *userList[MAX_USERS_AMOUNT];

     void loadUserInfo();

signals:
    void userInfoChanged(User* user,QString reason);
};

#endif // MEWIDGET_H
