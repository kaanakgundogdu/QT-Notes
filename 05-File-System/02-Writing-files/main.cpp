#include <QCoreApplication>
#include <QFile>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //this will put it in the current directory
    QString filename = "createdfile.txt";

    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly)){
        qInfo() << file.errorString();
        return -1;
    }

    QString now = QDateTime::currentDateTime().toString("dd.MM.yyyy");

    QByteArray data;
    data.append(now.toLocal8Bit());
    data.append(". ");
    data.append("This file created with Qfile.");

    file.write(data);
    file.close();

    qInfo() << "Wrote to the file";

    return a.exec();
}
