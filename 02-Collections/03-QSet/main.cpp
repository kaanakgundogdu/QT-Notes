#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<QString> people;
    people << "Kaan" << "Ghidorah" << "Yama" << "Zutomayo";
    people.insert("Edison");

    foreach(QString person, people) {
        qInfo() << person;
    }

    qInfo()<<"Trying to insert Edison again";
    people.insert("Edison");
    qInfo() << people;
    qInfo() << "Tesla in collection?" << people.contains("Bryan");
    qInfo() << "Kaan in collection?" << people.contains("Kaan");

    return a.exec();
}
