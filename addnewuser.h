#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
namespace Ui {
class addNewUser;
}

class addNewUser : public QWidget
{
    Q_OBJECT

public:
    explicit addNewUser(QWidget *parent = nullptr);
    ~addNewUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addNewUser *ui;
};

#endif // ADDNEWUSER_H
