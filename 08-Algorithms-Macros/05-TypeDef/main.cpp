#include <QCoreApplication>
#include <QDebug>
#include <QMap>

typedef QMap<QString,int> Map_string_int;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Map_string_int people;
    people.insert("Kaan", 45);
    people.insert("Conan", 12);
    people.insert("Lupin", 38);

    foreach(auto k, people.keys())
    {
        qInfo() << k << people[k];
    }

    return a.exec();
}
