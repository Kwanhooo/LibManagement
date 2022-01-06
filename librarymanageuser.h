#ifndef LIBRARYMANAGEUSER_H
#define LIBRARYMANAGEUSER_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QStringListModel>
#include <QDebug>


#include <vector>

#include "addnewuser.h"
#include "manageuserinformation.h"
namespace Ui {
class libraryManageUser;
}

class libraryManageUser : public QWidget
{
    Q_OBJECT

public:

    explicit libraryManageUser(QWidget *parent = nullptr);
    ~libraryManageUser();  

   std::vector<QString> v;
   void init();

private slots:
    void on_pushButton_search_clicked();
    void manageUser(QModelIndex);
    void showImgHelp();



    void on_pushButton_add_clicked();

    void on_pushButton_help_clicked();

private:
    Ui::libraryManageUser *ui;



};

#endif // LIBRARYMANAGEUSER_H
