#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void saveAge(QSettings *setting,QString group,QString name, int age)
{
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int getAge(QSettings *setting, QString group, QString name)
{
    setting->beginGroup(group);

    if(!setting->contains(name))
    {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok)
    {
        qWarning() << "Could not convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("KaanAkg");
    QCoreApplication::setOrganizationDomain("https://github.com/kaanakgundogdu");
    QCoreApplication::setApplicationName("Random");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(&settings,"people","Kaan",27);
    saveAge(&settings,"singer","yama",21);
    saveAge(&settings,"singer","Kaan",66);

    qInfo() << "Singer Yama " << getAge(&settings,"singer","yama");
    qInfo() << "Kaan (people)" << getAge(&settings,"people","Kaan");
    qInfo() << "Kaan (singer)" << getAge(&settings,"singer","Kaan");

    return a.exec();
}
