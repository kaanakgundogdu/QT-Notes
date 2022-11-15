#include <QCoreApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString filename = "test.txt";
    QFile file(filename);

    qInfo() << "Exists:" << file.exists();
    //if you dont have build file build than add  the test.txt file
    if(file.open(QIODevice::ReadOnly))
    {
        //Small files only!!!
        qInfo() << file.readAll();

        file.close();
    }
    else
    {
        qInfo() << file.errorString();
    }

    return a.exec();
}
