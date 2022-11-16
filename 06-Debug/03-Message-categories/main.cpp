#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

//Declare a logging category
Q_DECLARE_LOGGING_CATEGORY(custom_category);
Q_LOGGING_CATEGORY(custom_category,"custom_category");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "normal qinfo";

    qInfo(custom_category) << "qinfo with custom_category";
    qWarning(custom_category) << "qWarning with custom_category";

    //turn it off
    QLoggingCategory::setFilterRules("custom_category.debug=false");

    //Will not log
    qDebug(custom_category) << "will not log or cant see in console";

    if(!custom_category().isDebugEnabled())
    {
        QLoggingCategory::setFilterRules("custom_category.debug=true");
        qDebug(custom_category) << "We turned it back on!";
    }

    qDebug(custom_category) << "end...";

    return a.exec();
}
