#include <QCoreApplication>
#include <QProcess>

bool test()
{

    QProcess gzip;
    //gonna change later
    gzip.start("gzip.exe", QStringList() << "-c");

    if(!gzip.waitForStarted(3000)) return false;

    QByteArray data;
    for(int i = 0; i < 100; i++)
    {
        QString item = "Item " + QString::number(i);
        data.append(item.toUtf8());
    }

    gzip.write(data);
    gzip.closeWriteChannel();
    if(!gzip.waitForFinished(3000)) return false;

    QByteArray result = gzip.readAll();

    qInfo() << "Before: " << data.size();
    qInfo() << "Result: " << result.size();
    qInfo() << "Compressed: " << result;
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(test()) {
        qInfo() << "Compressed with gzip!";
    } else {
        qInfo() << "Failed to use gzip";
    }

    return a.exec();
}
