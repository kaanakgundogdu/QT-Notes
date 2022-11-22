#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Args:";
    for(int i = 0; i < argc; i++)
    {
        qInfo() << "Argc "<< i << ": " <<argv[i];
    }

    QTimer::singleShot(3000,&a, SLOT(quit()));
    qInfo()<<"After 3 seconds ask to quit.";
    int code = a.exec();
    qInfo() << "Exit code " << code;

    return code;
}
