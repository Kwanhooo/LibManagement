#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit :public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit();
    void focusOutEvent (QFocusEvent *event);

public slots:
    //void Slot_LostFocus();

signals:
    //void lostFocus();
    void addAll();
};

#endif // MYLINEEDIT_H
