#include <QCoreApplication>
#include <QSettings>
#include <QString>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("KaanAkg");
        QCoreApplication::setOrganizationDomain("https://github.com/kaanakgundogdu");
        QCoreApplication::setApplicationName("Setting-Test");

        QSettings settings(QCoreApplication::organizationName(),QCoreApplication::applicationName());

        //settings.clear();

        if(settings.allKeys().length() == 0)
        {
            QTextStream qin(stdin);
            QTextStream qout(stdout);
            qInfo() << "No setting...saving...";

            qInfo()<<"Enter your key: ";
            qout.flush();
            QString name=qin.readLine();
            qInfo()<<"Enter your value: ";
            qout.flush();
            QString number=qin.readLine();
            settings.setValue(name,number);
            return 0;
        }
        else
        {
            qInfo() << "Loading the settings...";
            foreach(QString key, settings.allKeys())
            {
                qInfo() << key << " = " << settings.value(key);
            }

        }


    return a.exec();
}
