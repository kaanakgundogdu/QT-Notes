#include <QCoreApplication>
#include <QMap>
#include "test.h"

void test_map_delete()
{
    QMap<QString,Test*> map;

    for(int i = 0; i < 5; i++)
    {
        QString id = "ID-" + QString::number(i+1);
        QString name = "Item-" + QString::number(i+1);
        map.insert(id,new Test(nullptr,name));
    }

    foreach(QString key, map.keys())
    {
        qInfo() << key << map[key];
    }

    qDeleteAll(map);
    //qInfo() << list.at(0); //Dangling pointer!
    qInfo()<< "map size after delete all "<< map.size();
    map.clear();
    qInfo()<< "map size after delete clear "<< map.size();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test_map_delete();
    return a.exec();
}
