#include <QCoreApplication>
#include <QTime>
#include <QTimer>


void print_time(){
    qInfo()<<"Curent time is: "<< QTime::currentTime().toString();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"After 3 seconds time will print.";
    QTimer::singleShot(3000,print_time);

    return a.exec();
}
