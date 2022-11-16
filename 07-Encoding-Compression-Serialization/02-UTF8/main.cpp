#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makeData()
{
    QString data;
    data.append("Unicode test\r\n");
    //generates random unicode chars
    for(int i = 0; i < 10; i++)
    {
        int number = QRandomGenerator::global()->bounded(1024);
        data.append(QChar(number));
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();
    qInfo() << data;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly)) {

        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8);
        stream << data;
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF8: " << data;
    qInfo() << "ASCII: " << data.toLatin1();

    return a.exec();
}
