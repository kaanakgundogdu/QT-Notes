#include <QCoreApplication>
#include <QDebug>

void test_sent_pointer(QObject *p){
    qInfo()<<p;
}


void test_sent_address(QObject &p){
    qInfo()<<&p;
}

//You cannot make copy QObject
void test_sent_copy(QObject p){
    qInfo()<<&p;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject test_object;
    test_object.setObjectName("Kaan");
    test_sent_pointer(&test_object);
    test_sent_address(test_object);
    // Cannot copy. Disable copy, deleted copy cosructor.
    //test_sent_copy(test_object);

    return a.exec();
}
