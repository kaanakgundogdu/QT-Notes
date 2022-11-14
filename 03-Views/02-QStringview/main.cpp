#include <QCoreApplication>
#include <QString>
#include <QStringView>

void display(QStringView &view)
{
    qInfo() << view;

    qInfo() << "Size" << view.size();
    qInfo() << "Data" << view.constData();
    qInfo() << "Slice (6-6):" << view.sliced(6,6);
    qInfo() << "Contains 'ello': " << view.contains(QString("ello"));
    qInfo() << "Count of l" << view.count('l');
    qInfo() << "At 1:" << view.at(1);
    qInfo() << "Index 0:" << view[0];
    qInfo() << "Indexof 'e':" << view.indexOf('e');

    for(auto c : view)
    {
        qInfo() << c;
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = "Hello I'm Kaan.";

    QStringView view(data);
    display(view);

    return a.exec();
}
