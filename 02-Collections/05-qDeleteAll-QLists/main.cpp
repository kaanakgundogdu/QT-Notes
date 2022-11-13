#include <QCoreApplication>
#include "test.h"
#include <QList>

void testListDelete()
{
    QList<Test*> list;
    for(int i = 0; i < 5; i++)
    {
        list.append(new Test(nullptr,"Test_Object " + QString::number(i+1)));
    }

    foreach(Test* test, list)
    {
        qInfo() << test;
    }

    // item type must be pointer
    qDeleteAll(list);
    qInfo() << "İtem count before clear after delete all: " << list.count();
    //qInfo() << list.at(0); //Dangling Pointer
    list.clear();

    qInfo() << "İtem count after clear: " << list.count();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testListDelete();

    return a.exec();
}
