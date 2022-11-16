#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QByteArray makedata()
{
    //write KAAN 5 times.

    QByteArray data;
    for(int i = 0; i < 5; i++) {
        data.append(75);
        data.append(65);
        data.append(65);
        data.append(78);
        data.append(13); // \r
        data.append(10); // \n
        // \r\n
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makedata();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
        file.close();
    }

    qInfo() << "Done...";

    return a.exec();
}
