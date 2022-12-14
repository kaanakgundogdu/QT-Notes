#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Info";
    qInfo() << "Boot Id: " << sys.bootUniqueId();
    qInfo() << "Build: " << sys.buildAbi();
    qInfo() << "Cpu: " << sys.buildCpuArchitecture();
    qInfo() << "Kernel: " << sys.kernelType();
    qInfo() << "Version: " << sys.kernelVersion();

    //Qt 5
    //qInfo() << "Mac: " << sys.macVersion();
    //qInfo() << "Windows: " << sys.windowsVersion();

    qInfo() << "Host: " << sys.machineHostName();
    qInfo() << "Product: " << sys.prettyProductName();
    qInfo() << "Type: " << sys.productType();
    qInfo() << "Version: " << sys.productVersion();

#ifdef Q_OS_LINUX
    qInfo() << "I'am on Linux. Linux code here";
#elif defined(Q_OS_WIN)
    qInfo() << "I'am on windows. Windows code here";
#elif defined(Q_OS_MACX)
    qInfo() << "I'am on Mac. Mac code here";
#else
    qInfo() << "I'am on Unknown OS. Unknown OS code here";
#endif


    return a.exec();
}
