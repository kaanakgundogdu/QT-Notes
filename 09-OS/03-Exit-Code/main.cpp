#include <QCoreApplication>
#include <QDebug>
#include<QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("notepad.exe",QStringList() << "http://kaanakgundogdu.github.io");
    qInfo() << "Exit code: " << proc.exitCode(); //0 is good, means no errors!

    return a.exec();
}
