#include <QCoreApplication>
#include <QDebug>
#include <QDataStream>
#include <QFile>

bool saveFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);

    QString title = "I'm gonna use this file later.";
    qint64 num = 99988;

    out  << title;
    out << num;

    file.close();

    return true;
}

bool readFile(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0)
    {
        qCritical() << "Versions do not match";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    file.close();

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file = "saveTest.txt";

    if(saveFile(file)) {
        qInfo() << "File Saved!";
        readFile(file);
    }


    return a.exec();
}
