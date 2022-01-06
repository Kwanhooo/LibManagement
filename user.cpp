
#include "user.h"

User::User(QString userName, QString password, QString email, QString phone,QString avatar,QString Bio)
{
    this->userName = userName;
    this->password = password;
    this->email = email;
    this->phone = phone;
    this->avatar = avatar;
    this->Bio = Bio;
}

QString User::toString()
{
    return QString("%1 %2 %3 %4 %5 %6 ").arg(userName).arg(password).arg(email).arg(phone).arg(avatar).arg(Bio);
}
