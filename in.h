#ifndef IN_H
#define IN_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class in;
}

class in : public QWidget
{
    Q_OBJECT

public:
    explicit in(QWidget *parent = nullptr);
    ~in();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_clear_clicked();

    void getShowBook(QString s);

public:
    Ui::in *ui;

signals:
    void addNew(QString s);

};

#endif // IN_H
