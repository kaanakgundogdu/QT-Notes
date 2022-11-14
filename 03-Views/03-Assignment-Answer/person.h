#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QStringView>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
public:
private:
    QString m_f_name;
    QString m_l_name;
public:
    explicit Person(QObject *parent=nullptr, QString f_name="",QString l_name="");
    QStringView display();

signals:

};

#endif // PERSON_H
