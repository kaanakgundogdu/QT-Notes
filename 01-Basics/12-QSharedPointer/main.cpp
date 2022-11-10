#include <QCoreApplication>
#include <QDebug>
#include "test.h"

QSharedPointer<Test> get_shared_pointer(QString name){
    qInfo()<<"---------creating shared ptr------------";
    QSharedPointer<Test> shared_ptr (new Test());
    shared_ptr->setObjectName(name);
    return shared_ptr;
}

void use_shared_ptr(QSharedPointer<Test> shared){
    qInfo()<<"---------use_shared_ptr------------";
    qInfo()<<"Shared pointer data " <<shared.data();
    qInfo()<<"Shared pointer " << &shared;
}

void test(){
    qInfo()<<"Getting shared pointer.";
    QSharedPointer<Test> shp=get_shared_pointer("Kaan");
    qInfo()<<"-------After getting ptr----------";
    qInfo()<<"Data "<<shp.data();
    qInfo()<<"Ptr"<<&shp;
    use_shared_ptr(shp);
    qInfo()<<"-----Completed!--------";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test();
    return a.exec();
}
