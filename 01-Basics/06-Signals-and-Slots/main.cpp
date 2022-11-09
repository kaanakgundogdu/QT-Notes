#include <QCoreApplication>
#include "test.h"


void call_wake_signal(){
    Test papa;
    Test child;
    papa.setObjectName("Papa");
    child.setObjectName("Velet");

    QObject::connect(&papa, &Test::alarm, &child, &Test::wake,Qt::AutoConnection);

    papa.testing();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    call_wake_signal();

    return a.exec();
}
