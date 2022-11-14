#include "person.h"

Person::Person(QObject *parent, QString f_name,QString l_name)
    : QObject{parent}
{
    m_f_name = f_name;
    m_l_name = l_name;
}

QStringView Person::display()
{
    QString full_name= m_f_name + " " + m_l_name;
    QStringView view(full_name);
    return view;
}
