#ifndef BORROWBOOK_H
#define BORROWBOOK_H

#include <QWidget>

namespace Ui {
class borrowbook;
}

class borrowbook : public QWidget
{
    Q_OBJECT

public:
    explicit borrowbook(QWidget *parent = nullptr);
    ~borrowbook();
    void init(QString);

private:
    Ui::borrowbook *ui;
    QStringList list = {"Miserable world","Hundred years of solitude","Three Days to See,"};
    QString name;
};

#endif // BORROWBOOK_H
