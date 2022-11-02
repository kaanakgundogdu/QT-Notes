#include <QCoreApplication>

#include "cat.h"

void test1(Cat c){

}

void test2(const Cat &c){
    qInfo()<<"Address: "<< &c;
}

void test3(Cat *c){
    qInfo()<<"Ptr: "<< c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Cat kedi;
    kedi.setObjectName("Leplep");
    Cat zurna;
    zurna.setObjectName("Josuke");

    //you cannot copy or move qobjects.
    //test1(kedi);
//    qInfo()<< &kedi;//gives address

    test2(kedi);
    test3(&kedi);

    test2(zurna);
    test3(&zurna);

    return a.exec();
}
