#include <QCoreApplication>

#include "test.h"

typedef QList<Test*> test_list;

test_list get_test_list(int length){
    test_list list;
    for(int i=0; i < length;i++){
        list.append(new Test());
        list.last()->setObjectName("Test " + QString::number(i+1));
    }
    return list;
}

void display_test_list(test_list list){
    foreach(Test* elem, list){
        qInfo()<<elem;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_list list = get_test_list(5);

    display_test_list(list);

    qDeleteAll(list);
    list.clear();
    // if you don't clear and call again program will crash
    display_test_list(list);

    return a.exec();
}
