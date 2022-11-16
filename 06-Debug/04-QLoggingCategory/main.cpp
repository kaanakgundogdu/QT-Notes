#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggingCategory log_test("testing");
    log_test.setEnabled(QtMsgType::QtDebugMsg,false);

    qDebug() << "is Debug Enabled = " << log_test.isDebugEnabled();
    qInfo() << "is Info Enabled = " << log_test.isInfoEnabled();
    qWarning() << "is Warning Enabled = " << log_test.isWarningEnabled();
    qCritical() << "is Critical Enabled = " << log_test.isCriticalEnabled();

    //cant log qDebug bc.log_test.setEnabled(QtMsgType::QtDebugMsg,false);
    qDebug(log_test) << "This is a debug";
    qInfo(log_test) << "This is a info";
    qWarning(log_test) << "This is a warning";
    qCritical(log_test) << "This is a critical";

    return a.exec();
}
