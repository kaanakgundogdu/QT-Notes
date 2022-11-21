#include <QCoreApplication>

void display(QString title, QByteArray &bytes)
{
    qDebug() << "************" << title << "************";
    qDebug() << "Data Length: " << bytes.size();
    qDebug() << "Actual Data (Plain): " << bytes;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data("This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, This is my very long and annoying data, ");

    // 0 to 9 -> 9 most greatest compression
    // More time and more cpu power
    QByteArray compressed = qCompress(data,9);
    QByteArray decompressed = qUncompress(compressed);

    display("Original", data);
    display("Compressed", compressed);
    display("Decompressed", decompressed);

    return a.exec();
}
