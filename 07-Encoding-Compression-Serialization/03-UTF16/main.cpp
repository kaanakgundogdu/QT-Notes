#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>


QString makeData() {
    QString data;

    data.append("Unicode test\r\n");
    for(int i = 0; i < 10; i++) {
        int number = QRandomGenerator::global()->bounded(1024);

        data.append(QChar(number));
    }
    data.append("\r\n");

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly)) {

        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf16);
        stream << data;
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF16: " << data;
    qInfo() << "UTF8 doesn't havce any idea: : " << data.toUtf8();
    qInfo() << "ASCII too doesn't now what to do with utf16:: " << data.toLatin1();

    return a.exec();
}
