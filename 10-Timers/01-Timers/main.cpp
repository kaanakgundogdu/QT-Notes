#include <QCoreApplication>
#include <QTimer>

void test()
{
    qInfo() << "Yes I'm from future!";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "There will be a message after 5 seconds.";

    QTimer::singleShot(5000,&test);

    return a.exec();
}
