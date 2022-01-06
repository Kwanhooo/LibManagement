#ifndef PUSHBOTTONWITHIMG_H
#define PUSHBOTTONWITHIMG_H
#include<QPushButton>
#include<QEvent>
#include<QLabel>
#include<QDebug>
class pushbottonWithImg: public QPushButton
{
public:
    pushbottonWithImg();


protected:
    bool event(QEvent *event) override;

};

#endif // PUSHBOTTONWITHIMG_H
