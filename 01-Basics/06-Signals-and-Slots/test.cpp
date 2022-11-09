#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo()<< this <<" Constructed ";
}

void Test::testing()
{
    QString noise= "Wake Wake It's time for school. Come on Wake up...";
    emit alarm(noise);
}

Test::~Test()
{
    qInfo()<< this <<" Destructed ";
}

void Test::wake(QString noise)
{
    qInfo()<<"This is "<< this <<", a signal from"<< sender()<<": "<< noise;
}
