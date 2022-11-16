#include <QCoreApplication>
#include <QLoggingCategory>


void test(QLoggingCategory &log_cat){
    qDebug(log_cat) << "This is a debug";
    qInfo(log_cat) << "This is a info";
    qWarning(log_cat) << "This is a warning";
    qCritical(log_cat) << "This is a critical";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggingCategory log_test("test log");

    log_test.setEnabled(QtMsgType::QtDebugMsg,false);
    log_test.setEnabled(QtMsgType::QtInfoMsg,false);
    log_test.setEnabled(QtMsgType::QtWarningMsg,false);

    qInfo()<<"-------debug info warning disabled-------";
    test(log_test);

    log_test.setEnabled(QtMsgType::QtDebugMsg,true);
    log_test.setEnabled(QtMsgType::QtInfoMsg,true);
    log_test.setEnabled(QtMsgType::QtCriticalMsg,false);

    qInfo()<<"-------critical and warning disabled-------";
    test(log_test);


    return a.exec();
}
