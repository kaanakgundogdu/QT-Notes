#include <QCoreApplication>
#include <QDebug>
#include "logger.h"
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File name: " << Logger::filename;
    Logger::attach();

    qInfo() << "Random qinfo log!!!";

    //can toggle logging
    Logger::logging = false;
    qInfo() << "This will not get logged on log folder";
    Logger::logging = true;

    Test test_obj;
    test_obj.testing();

    qInfo() << "Finished...";

    return a.exec();
}
