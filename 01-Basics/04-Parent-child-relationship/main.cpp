#include <QCoreApplication>
#include <QTimer>
#include "test.h"

// Set new test obj. and parent
// This looks like memory leak but parent child
// realtionship solve this
Test* get_new_test(QObject* parent){
    return new Test(parent);
}

// with no parent in constructor
// set up after cons.
Test* get_new_test(){
    return new Test();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer qtimer;
    qtimer.singleShot(3000,&a,&QCoreApplication::quit);

    qInfo()<<"This pogram will stop after 3 seconds\n";

    Test* horse= get_new_test(&a);
    horse->setObjectName("Ito");

    Test* penguin= get_new_test();
    penguin->setObjectName("Urameshi");
    penguin->setParent(horse);

    int exit_value= a.exec();
    qInfo()<<"Exit Code: "<<exit_value;

    return exit_value;
}
