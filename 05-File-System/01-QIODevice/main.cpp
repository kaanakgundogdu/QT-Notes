#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    if(!buffer.open(QIODevice::ReadWrite))
    {
        qInfo() << "Could not open the device";
        return -1;
    }

    qInfo() << "Device is open (buffer).";

    QByteArray data("I am Kaan.");
    for(int i = 0; i < 3; i ++)
    {
        buffer.write(data);
        buffer.write("\r\n");
    }
    //buffer.flush();
    //Reimplements: QIODevice::seek(qint64 pos).
    buffer.seek(0);
    //Make pos 0 and read all
    qInfo() << buffer.readAll();

    qInfo() << "Closing buffer...";
    buffer.close();
    qInfo() << "Finished";

    return a.exec();
}
