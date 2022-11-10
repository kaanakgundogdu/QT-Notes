#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include <QSharedPointer>
#include "test.h"

Test* get_object(){
    return new Test();
}

void test(){
    QSharedPointer<Test> obj_1 (get_object());
    obj_1->setObjectName("Obj 1");
    QScopedPointer<Test> obj_2 (get_object());
    obj_2->setObjectName("Obj 2");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}
