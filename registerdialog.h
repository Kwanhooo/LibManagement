/*
 * 文件名：registerdialog.h
 * 内容：此头文件包含了RegisterDialog类以及其成员函数、成员变量的声明
 * 作用：创建一个用户注册的窗口
 *      将用户的所有注册信息放入一个作为注册凭证的QString中，以待发送至服务器登记
 *      用户可以在此窗口中进行所有注册信息的填写以及头像的选择
 *      重写鼠标事件（以实现隐藏程序标题栏之后仍旧可以拖动的效果）
 */
#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

//鼠标时间
#include <QMouseEvent>
#include <QPoint>

#include "user.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    /*
     * 以下槽函数，用于响应用户界面中组件的操作
     */
    void on_checkBox_stateChanged(int arg1);//检查用户是否勾选了同意用户协议
    void on_pushButton_cancel_clicked();//取消注册关闭当前窗口
    void on_pushButton_reg_clicked();//确认注册，关闭窗口，保存注册凭证
    void on_btn_min_clicked();//最小化窗口
    void on_btn_close_clicked();//关闭窗口

    //以下为15个头像选择按钮关联的槽函数
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_10_clicked();
    void on_btn_11_clicked();
    void on_btn_12_clicked();
    void on_btn_13_clicked();
    void on_btn_14_clicked();
    void on_btn_15_clicked();

    void on_lineEdit_userName_editingFinished();

    void on_lineEdit_email_editingFinished();

private:
    Ui::RegisterDialog *ui;

    QString avatarSetting;//当前用户选择的头像
    QString Bio;//用户设定的个性签名

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

    int userListSize;
    const static int MAX_USERS_AMOUNT = 100;
    User *userList[MAX_USERS_AMOUNT];

    void loadUserInfo();
    void updateUserConfig();
};

#endif // REGISTERDIALOG_H
