#include <QCoreApplication>
#include "commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Commander cmd;
    cmd.action(QByteArray("pwd"));
    cmd.action(QByteArray("dir"));

    return a.exec();
}
