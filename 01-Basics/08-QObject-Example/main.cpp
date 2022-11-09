#include <QCoreApplication>
#include <QDebug>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter c;
//    c.setValue(10);
    QObject::connect(&c, &Counter::valueChanged, &c, &Counter::setValue,Qt::AutoConnection);
    c.set_val_test(999);
    qInfo()<<c.value();
    return a.exec();
}


