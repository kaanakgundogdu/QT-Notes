#include <QCoreApplication>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello, my name is Kaan.";

    QByteArray byte_arr=str.toUtf8();
    QByteArray encoded_tobase64= byte_arr.toBase64();
    QByteArray decoded= byte_arr.fromBase64(encoded_tobase64);
    qInfo()<<encoded_tobase64;
    qInfo()<<"-----------------------------------";
    qInfo()<<decoded;

    return a.exec();
}
