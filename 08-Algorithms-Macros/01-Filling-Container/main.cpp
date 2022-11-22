#include <QCoreApplication>
#include <QtAlgorithms>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 1 << 2 << 3 << 4 <<5;

   // qFill() = do not use

    qInfo() << "List before fill\n" << list;

    list.fill(66);
    qInfo() <<"List after fill with 66\n" << list;

    list.resize(11);
    std::fill(list.begin(),list.end(),0);
    qInfo()<<"List after resize 11 and fill with 0\n" << list;

    return a.exec();
}
