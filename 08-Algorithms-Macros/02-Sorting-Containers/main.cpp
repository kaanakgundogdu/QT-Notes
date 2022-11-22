#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QRandomGenerator>

void randoms(QList<int> *list, int max)
{
    list->reserve(max);
    for(int i = 0; i < max; i++)
    {
        int value = QRandomGenerator::global()->bounded(100);
        list->append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    randoms(&list,8);

    qInfo() << "Unsorted List:" << list;

    //qSort - do not use

    std::sort(list.begin(),list.end());
    qInfo() << "Sorted smaller to bigger:" << list;

    std::reverse(list.begin(),list.end());
    qInfo() << "Reversed bigger to smaller:" << list;




    return a.exec();
}
