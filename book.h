#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>
#include <QList>
#include <QLabel>
#include <QStandardItemModel>
#include <QListView>
#include <QGridLayout>
#include "item.h"
#include "in.h"
#include "view.h"
#include "mylineedit.h"

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();

    private:
    Ui::Book *ui;
    //in *child;
    int total;
    MyLineEdit *line=new MyLineEdit;
    bool isViewing=false;
    int viewOne = 0;
//    QList<itemProperty> listItems;
//    QStandardItemModel *listModel;
//    listViewDelegate *listItemDelegate;
//    QStandardItemModel *model;
//    QStandardItemModel *slm;
//    QListView *listview;

//    QStringList list;

//    QStandardItem   * s1 ;
//    QStandardItem   * s2 ;
//    QStandardItem   * s3 ;
//    QStandardItem   * s4 ;
//    QStandardItem   * s5 ;
//    QStandardItem   * s6 ;


public:
    void init();
    QString divert(int n);
private slots:
    void on_in_clicked();
    void getNewOne(QString s);

    void on_book1_clicked();

    void on_book2_clicked();

    void on_book3_clicked();

    void on_check_clicked();

    void on_pushButton_clicked();

    void on_book4_clicked();

    void on_out_clicked();

    void on_what_clicked();

signals:
    void in();
    void showBook(QString s);

};

#endif // BOOK_H
