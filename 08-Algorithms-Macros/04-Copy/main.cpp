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
    randoms(&list1,6);

    QList<int> list2;

    qInfo() << "list 1: " << list1;
    qInfo() << "list 2: " << list2;

    qInfo() << "Copy list 1 to list 2, first resize";
    list2.resize(list1.size());
    std::copy(list1.begin(),list1.end(),list2.begin());

    qInfo() << "list 1: " << list1;
    qInfo() << "list 2: " << list2;

    qInfo() << "Equal:" << std::equal(list1.begin(),list1.end(),list2.begin());

    return a.exec();
}
