#include <QCoreApplication>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> numbers;
    numbers << 1 << 2 << 3 << 4;

    for (int i = 10; i < 15; ++i) {
        numbers.append(i);
    }

    numbers << 4 << 3 << 2 << 4 << 1 << 4;

    qInfo()<<numbers;

    qInfo()<< "Length of list: "  << numbers.length();
    qInfo()<< "Size of list: "  << numbers.size();
    qInfo()<< "Count of list: "  << numbers.count();
    qInfo()<< "Count of 4's in list: "  << numbers.count(4);

    numbers.replace(2,77);
    numbers.remove(4);
    qInfo()<<"Replace 3 wtth 77 and remove 4";
    qInfo()<<numbers;

    foreach (int i, numbers) {
        qInfo()<<i;
    }

    numbers.removeAll(4);
    qInfo()<<numbers;

    QList<int> slice = numbers.sliced(2,3);
    qInfo()<<"slice: " << slice;

    qInfo()<< "Cpntains 6: "  << numbers.contains(6);
    qInfo()<< "Index of 6: "  << numbers.indexOf(6);

    numbers.clear();
    qInfo()<<"Clear";

    qInfo()<< "Length of list: "  << numbers.length();
    qInfo()<< "Size of list: "  << numbers.size();
    qInfo()<< "Count of list: "  << numbers.count();
    return a.exec();
}
