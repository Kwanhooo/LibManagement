#include "pushbottonwithimg.h"

pushbottonWithImg::pushbottonWithImg()
{

}

bool pushbottonWithImg::event(QEvent *event)
{
    if(event->type()==QEvent::Enter){
        int x = this->mapFromGlobal(QCursor().pos()).x();
        int y = this->mapFromGlobal(QCursor().pos()).y();

        qDebug()<<"SUCCESS";
    }

}
