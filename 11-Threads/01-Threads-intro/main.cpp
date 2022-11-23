#include <QCoreApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *thread = QThread::currentThread();
    thread->setObjectName("Main Thread");

    qInfo() << "Starting " << thread;

    for(int i = 0; i < 5; i++)
    {
        qInfo() << i+1 << " on " << thread;
    }
    qInfo() << "Finished" << thread;
    return a.exec();
}
