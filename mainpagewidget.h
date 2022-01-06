#ifndef MAINPAGEWIDGET_H
#define MAINPAGEWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class MainPageWidget;
}

class MainPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainPageWidget(QWidget *parent = nullptr);
    ~MainPageWidget();

    void setupData();
    int userAmount;
    int bookAmount;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainPageWidget *ui;
    void timePassing();
    QTimer* timer;
};

#endif // MAINPAGEWIDGET_H
