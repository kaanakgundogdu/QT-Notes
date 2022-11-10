#include "test.h"

Test::Test(QObject *parent, QString name)
    : QObject{parent}
{
    qInfo()<< "Constructed "<<this;
}

Test::~Test()
{
    qInfo()<< "Deconstructed "<<this;
}
