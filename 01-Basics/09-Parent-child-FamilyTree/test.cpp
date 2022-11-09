#include "test.h"

Test::Test(QObject *parent, QString name): QObject(parent)
{
    setObjectName(name);
    qInfo()<< this <<" Constructed.";
}

Test::~Test()
{
    qInfo()<< this <<" Destructed.";
}
