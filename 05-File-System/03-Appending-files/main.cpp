#include <QCoreApplication>
#include <QFile>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test_file.txt";

    QFile file(filename);

    //if you work this code more than one. It adds new lines not override from zero.
    if(file.open(QIODevice::Append)) //adds to the end of the file, run a few times and see
    {
        QString now = QDateTime::currentDateTime().toString();

        QByteArray data;
        data.append(now.toLocal8Bit());
        data.append(". ");
        data.append("I am Kaan.\r\n");

        file.write(data);
        file.close();
        qInfo() << "Append to file";
    }
    else
    {
        qInfo() << file.errorString();
        return -1;
    }
    return a.exec();
}
