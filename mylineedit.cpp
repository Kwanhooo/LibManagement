#include "mylineedit.h"

MyLineEdit::MyLineEdit()
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void MyLineEdit::focusOutEvent(QFocusEvent *e)
{
    if(this->text().isEmpty())
    {
        emit addAll();
    }
}
