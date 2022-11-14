#include <QCoreApplication>
#include <QString>
#include <QStringView>
#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Person p(nullptr, "Kaan", "Akgu");

    qInfo()<< p.display();

    return a.exec();
}


