#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QList<int> *list, int max) {

    list->reserve(max);

    for(int i = 0; i < max; i++){
        int value = QRandomGenerator::global()->bounded(20);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list1;
    randoms(&list1,5);

    QList<int> list2;
    randoms(&list2,5);

    qInfo() << list1;
    qInfo() << list2;

    qInfo() << "Is Equal: " << std::equal(list1.begin(), list1.end(), list2.begin());

    list1.fill(11);
    list2.fill(11);
    qInfo() << list1;
    qInfo() << list2;

    qInfo() << "Check Equality after fill with 11: " << std::equal(list1.begin(), list1.end(), list2.begin());

    return a.exec();
}
