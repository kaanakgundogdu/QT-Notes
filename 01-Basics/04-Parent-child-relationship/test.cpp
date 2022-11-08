#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<" Constructed "<<parent;
}

Test::~Test()
{
    foreach (QObject* child, children()) {
        qInfo()<< "parent " <<this<<" has a child: " << child;
    }
    qInfo()<<"-----"<<this<<" Deconstructed "<<this->parent();//you dont have to use this-> only, parent() works.
}
