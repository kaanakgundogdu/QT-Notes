#include <QCoreApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data=("abcdefghijklmnopqrstuvwxyz1234567890");
    QByteArray compressed = qCompress(data,9);

    qDebug() << "Data Length: " << data.size();
    qDebug() << "Compressed Data Length: " << compressed.size();

    return a.exec();
}
