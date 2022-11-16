#include <QCoreApplication>
#include <QTemporaryFile>
#include <QDebug>
#include <QDir>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTemporaryFile file;

    if (file.open()) {
        // file.fileName() returns the unique file name
        qInfo()<<file.fileName();
        file.open();

        file.seek(0);
        file.write("Hello I am Kaan.");

        file.close();
    }


    return a.exec();
}
