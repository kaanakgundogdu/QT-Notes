#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.start("notepad");

    qInfo()<<"After 2 second should close notepad.";
    QTimer::singleShot(2000,&proc,&QProcess::terminate);

    return a.exec();
}
