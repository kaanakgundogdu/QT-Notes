#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    qInfo()<<"Constructed on "<< QThread::currentThread();
}

Task::~Task()
{
    qInfo()<<"Deconstructed on "<< QThread::currentThread();
}

void Task::start_task()
{
    QThread *thread= QThread::currentThread();

    for(int i=0; i<8;i++){
        qInfo()<< i+1 <<" on "<<thread;
    }

    qInfo()<<"Finito!";

}
