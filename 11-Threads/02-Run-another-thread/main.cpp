#include <QCoreApplication>
#include <QThread>
#include <QScopedPointer>
#include "task.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo()<<"Starting program... on " << QThread::currentThread();

    QScopedPointer<Task> t (new Task());
    Task *task = t.data();

    task->moveToThread(&worker);
    worker.connect(&worker,&QThread::started, task, &Task::start_task);
    //connect qthread finished if you want to know when thread ends.

    worker.start();

    qInfo()<< "Free to do other things." << QThread::currentThread();

    return a.exec();
}
