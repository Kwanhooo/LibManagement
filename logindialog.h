/*
 * 文件名：logindialog.h
 * 内容：此头文件包含了LoginDialog类以及其成员函数、成员变量的声明
 * 作用：创建一个用户登录窗口
 *      将用户的账号密码放入一个作为登陆凭证的QString中，以待发送至服务器检查
 *      能够创建一个用户注册窗口，让没有账号的用户进行注册
 *      重写鼠标事件（以实现隐藏程序标题栏之后仍旧可以拖动的效果）
 */
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "registerdialog.h"
#include <user.h>

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

//鼠标事件
#include <QMouseEvent>
#include <QPoint>

#include <QVBoxLayout>
#include <QMessageBox>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QDialog *parent = nullptr);
    ~LoginDialog();
    RegisterDialog *regDialog;

private slots:
    /*
     * 以下槽函数，用于响应用户界面中组件的操作
     */
    void on_pushButton_login_clicked();
    void on_pushButton_reg_clicked();
    void on_btn_min_clicked();
    void on_btn_close_clicked();

private:
    Ui::LoginDialog *ui;

    /*
     * 以下代码段重写鼠标事件
     * 以实现隐藏程序标题栏之后仍旧可以拖动的效果
     */
    QPoint m_lastPos;
    bool isPressedWidget;

    void mousePressEvent(QMouseEvent *event)
    {
        m_lastPos = event->globalPos();
        isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        if (isPressedWidget) {
            this->move(this->x() + (event->globalX() - m_lastPos.x()),
                       this->y() + (event->globalY() - m_lastPos.y()));
            m_lastPos = event->globalPos();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event)
    {
        m_lastPos = event->globalPos();
        isPressedWidget = false;
    }

    void loadUserInfo();
    int userListSize;
    const static int MAX_USERS_AMOUNT = 100;
    User *userList[MAX_USERS_AMOUNT];

    User* validateIdentity(QString username,QString password);
};

#endif // LOGINDIALOG_H
