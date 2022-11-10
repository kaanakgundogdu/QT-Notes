#include <QCoreApplication>
#include <QDebug>
#include "test.h"

void scope_test(){
    QScopedPointer<Test> scp(new Test());
    scp->setObjectName("Scoped Pointer");

    qInfo() << "Scoped pointer " << &scp;
    qInfo() << "Scoped pointer data " << scp.data();
    qInfo() << scp->objectName();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    scope_test();

    return a.exec();
}
