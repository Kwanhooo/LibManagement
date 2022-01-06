#ifndef MANAGEUSERINFORMATION_H
#define MANAGEUSERINFORMATION_H

#include <QWidget>
#include <QMessageBox>
#include <QButtonGroup>
#include "returnbook.h"
namespace Ui {
class manageUserInformation;
}

class manageUserInformation : public QWidget
{
    Q_OBJECT

public:
    explicit manageUserInformation(QWidget *parent = nullptr);
    ~manageUserInformation();

    void init(QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_modfiyUserName_clicked();

    void on_radioButton_Woman_clicked();

    void on_pushButton_modfiySex_clicked();

    void on_pushButton_modfiyAge_clicked();

    void on_pushButton_modfiyStatus_clicked();

    void on_pushButton_returnbook_clicked();

    void on_pushButton_borrowbook_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manageUserInformation *ui;
    QString name;
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    QStringList list = {"Miserable world","Hundred years of solitude","Three Days to See,"};

};

#endif // MANAGEUSERINFORMATION_H
