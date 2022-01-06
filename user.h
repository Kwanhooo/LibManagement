
#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(QString userName, QString password,QString email,QString phone,QString avatar,QString Bio);
    QString userName;
    QString password;
    QString email;
    QString phone;
    QString avatar;
    QString Bio;
    QString toString();
};

#endif // USER_H
