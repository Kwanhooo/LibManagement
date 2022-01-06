#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    View(QWidget *parent = nullptr,QString s="",int n=0);
    ~View();

    void init();
    void init(QString s,int n);

private slots:
    void on_back_clicked();

private:
    Ui::View *ui;
    QStandardItemModel *model;
};

#endif // VIEW_H
