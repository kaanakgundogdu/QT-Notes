#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void info(QSettings &settings)
{
    qInfo() << "File name: " << settings.fileName();
    qInfo() << "Keys in settings: " << settings.allKeys();
}

void save(QSettings &settings, QString save_key)
{
    settings.setValue(save_key,9999);
    qInfo() << settings.status();
    qInfo() << "Saved";

}

void load(QSettings &settings, QString save_key)
{
    info(settings);

    qInfo() << settings.value(save_key).toString();
    bool ok;
    qInfo() << settings.value(save_key).toInt(&ok);
    if(!ok)
    {
        //something bad happened
        qInfo() << "Could not convert to int";
    }
}

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
        qInfo() << "No setting...saving...";
        save(settings, "my_save");
    }
    else
    {
        qInfo() << "Loading the settings...";
        load(settings, "my_save");
    }

    return a.exec();
}
