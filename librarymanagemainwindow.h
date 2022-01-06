#ifndef LIBRARYMANAGEMAINWINDOW_H
#define LIBRARYMANAGEMAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include "librarymanageuser.h"
#include "book.h"
#include "logindialog.h"
namespace Ui {
class libraryManageMainWindow;
}

class libraryManageMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit libraryManageMainWindow(QWidget *parent = nullptr);
    ~libraryManageMainWindow();
    void getTime();

    libraryManageUser *libmanageuser = new libraryManageUser();
    Book *book = new Book();
    QString changeIntToString(int);
private:
    Ui::libraryManageMainWindow *ui;
    int hour;
    int min;
    int seconds;
    QTimer *t = new QTimer();

signals:
    void beginTime();


private slots:
    void updateTime();
    void on_pushButton_manageUser_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_manageBook_clicked();
    void on_pushButton_cancellation_clicked();
};

#endif // LIBRARYMANAGEMAINWINDOW_H
