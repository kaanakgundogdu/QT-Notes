#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QLockFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file...";

    //sperator makes system seperator. unix windows doesn't matter.
    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);
    QLockFile lock(file.fileName() +"lock");
    lock.setStaleLockTime(5000);

    if(lock.tryLock())
    {
        qInfo() << "Putting into file...";
        if(file.open(QIODevice::WriteOnly)) {
            QByteArray data;
            data.append("My name is Kaan.");
            file.write(data);
            file.close();
            qInfo() << "Finished with file...";
            //Took over 5 seconds here, auto unlock
        }
        qInfo() << "Unlocking file";
        lock.unlock(); //Comment out to see it lock
    }
    else
    {
        qInfo() << "Could not lock the file!";
        qint64 pid;
        QString host;
        QString application;

        if(lock.getLockInfo(&pid,&host,&application)) {
            qInfo() << "The file is locked by:";
            qInfo() << "Pid: " << pid;
            qInfo() << "Host: " << host;
            qInfo() << "Application: " << application;

        } else {
            qInfo() << "File is locked, but we can't get the info!";
        }
    }

    return a.exec();
}
