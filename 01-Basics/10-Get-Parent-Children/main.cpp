#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject parent;
    parent.setObjectName("Parent");

    QObject child_1;
    child_1.setObjectName("Child 1");
    child_1.setParent(&parent);
    QObject child_2;
    child_2.setObjectName("Child 2");
    child_2.setParent(&parent);
    QObject child_3;
    child_3.setObjectName("Child 3");
    child_3.setParent(&parent);

    qInfo()<<"Parents child"<<parent.children();

    foreach (QObject *c, parent.children()) {
        qInfo()<< c ;
    }


    return a.exec();
}
