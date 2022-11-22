#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    number = 0;
    timer.setInterval(1000);
    connect(&timer,&QTimer::timeout,this,&Test::timeout);
}

void Test::timeout()
{
    number++;

    qInfo() << number<< ": " <<QTime::currentTime().toString(Qt::DateFormat::TextDate);

    if(number >= 10)
    {
        timer.stop();
        qInfo() << "Complete!";
    }
}

void Test::start_timer()
{
    number = 0;
    timer.start();
}
