#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Same as qlist
    QVector<int> numbers;
    numbers << 1 << 2 << 3 << 4;

    for (int i = 55; i < 58; ++i) {
        numbers.append(i);
    }

    numbers << 4 << 4 << 4;
    // even its vector output is still says its list.
    // QVector is an alias for QList
    qInfo()<<numbers;

    qInfo()<< "Length of vector: "  << numbers.length();
    qInfo()<< "Size of vector: "  << numbers.size();
    qInfo()<< "Count of vector: "  << numbers.count();
    qInfo()<< "Count of 4's in vector: "  << numbers.count(4);
    return a.exec();
}
