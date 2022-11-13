#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

void test_sp_list()
{
    QList<QSharedPointer<Test>> list;

    for(int i = 0; i < 5; i++)
    {
        QSharedPointer<Test> item(new Test(nullptr, "Test_Obj " + QString::number(i + 1)));
        list.append(item);
    }

    foreach(QSharedPointer<Test> test, list)
    {
        qInfo() << test.data();
    }

    qInfo() << "Remove item zero";
    list.removeAt(0);

    //shared pointer delete after ref count 0 you dont have to delete.

    qInfo() << "\nClearing\n";
    list.clear();
    qInfo() << "Count of list "<<list.count();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_sp_list();

    return a.exec();
}
