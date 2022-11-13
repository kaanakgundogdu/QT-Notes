#include <QCoreApplication>
#include <QMap>
#include <QSharedPointer>
#include "test.h"

//typedef  QMap<QString,QSharedPointer<Test>>Testmap;

void test_sharedptr_map()
{
    QMap<QString,QSharedPointer<Test>> map;

    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i+1);
        QString name = "Item-" + QString::number(i+1);
        QSharedPointer<Test> ptr(new Test(nullptr,name));
        map.insert(id,ptr);
    }

    foreach(QString item, map.keys())
    {
        qInfo() << item << map[item].data();
    }
    qInfo()<<"Size before clear. " << map.count();
    map.clear();
    qInfo()<<"Size after clear. " << map.count();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test_sharedptr_map();
    return a.exec();
}
