#include <QCoreApplication>
#include "test.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    QObject::connect(&test,&Test::close,&a,&QCoreApplication::quit,Qt::QueuedConnection);

    test.do_stuff();

    int value=a.exec();
    qInfo()<<"Exit value is "<<value;

    return value;
}
