#include <QCoreApplication>
#include <QByteArray>
#include <QByteArrayView>

void display(QByteArrayView &view)
{
    qInfo() << view;
    qInfo() << "Size" << view.size();
    qInfo() << "Data" << view.constData();
    qInfo() << "Slice (7-9): " << view.sliced(7,9);
    qInfo() << "Contains Kaan: " << view.contains("Kaan");
    qInfo() << "At one: " << view.at(1);
    qInfo() << "Index zero: " << view[0];
    qInfo() << "Indexof 'i': " << view.indexOf('i');

    for(auto c : view)
    {
        qInfo() << c;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bytes("Hello my name is Kaan.");
    QByteArrayView view(bytes);

    display(view);

    return a.exec();
}
