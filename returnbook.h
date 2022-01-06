#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include <QStringListModel>
#include <QMessageBox>
namespace Ui {
class returnbook;
}

class returnbook : public QWidget
{
    Q_OBJECT

public:
    explicit returnbook(QWidget *parent = nullptr);
    ~returnbook();
    void init(QString,int);


private slots:
    void returnABook(QModelIndex);

private:
    Ui::returnbook *ui;
    QStringList list = {"Miserable world","Hundred years of solitude","Three Days to See,"};
    QString name;
    int model;
};

#endif // RETURNBOOK_H
