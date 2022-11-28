#include <QCoreApplication>
#include <QtConcurrent>
#include <QFuture>
#include <QRandomGenerator>

void print_random_value(){
    int value = QRandomGenerator::global()->bounded(20);
    qInfo()<< "Hello this the new number " << value << " on " <<QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFuture<void> future1 = QtConcurrent::run(&print_random_value);
    QFuture<void> future2 = QtConcurrent::run(&print_random_value);
    QFuture<void> future3 = QtConcurrent::run(&print_random_value);
    QFuture<void> future4 = QtConcurrent::run(&print_random_value);

    return a.exec();
}
