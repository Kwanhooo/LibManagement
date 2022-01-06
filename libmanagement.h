#ifndef LIBMANAGEMENT_H
#define LIBMANAGEMENT_H

#include <QMainWindow>

#include <QBitmap>
#include <QPainter>

//鼠标事件
#include <QMouseEvent>
#include <QPoint>

#include <QVBoxLayout>
#include <QMessageBox>

#include <QDebug>

#include <QPicture>


#include "user.h"

namespace Ui {
class LibManagement;
}

class LibManagement : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibManagement(QWidget *parent = nullptr);
    ~LibManagement();

    QString userType;
    User* loginUser;
    int userAmount;
    int bookAmount;

    void setupData();

public slots:
    void onUserInfoChanged(User* user,QString reason);

private slots:
    void on_btn_min_clicked();
    void on_btn_close_clicked();

    void on_btn_search_clicked();

    void on_btn_home_clicked();

    void on_btn_logout_clicked();


    void on_btn_me_clicked();

private:
    const int ORIGIN_X = 140;
    const int ORIGIN_Y = 110;
    const int WIDGET_WIDTH = 820;
    const int WIDGET_HEIGHT = 470;
    QWidget* currentDisplayWidget;

    Ui::LibManagement *ui;

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

#endif // LIBMANAGEMENT_H
