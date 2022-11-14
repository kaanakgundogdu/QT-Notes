#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QRandomGenerator>

void save_point(QSettings *setting,QString group, QString name, int age) {
    setting->beginGroup(group);
    setting->setValue(name,age);
    setting->endGroup();
}

int get_point(QSettings *setting,QString group, QString name) {
    setting->beginGroup(group);

    if(!setting->contains(name)) {
        qWarning() << "Does not contain " << name << " in " << group;
        setting->endGroup();
        return 0;
    }

    bool ok;
    int value = setting->value(name).toInt(&ok);
    setting->endGroup();

    if(!ok) {
        qWarning() << "Failed to convert ot int!!!";
        return 0;
    }

    return value;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setOrganizationName("VoidRealms");
    QCoreApplication::setOrganizationDomain("VoidRealms.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    save_point(&settings,"singers","Vaundy",9);
    save_point(&settings,"songs","Connect",5);
    save_point(&settings,"songs","Zankyosanka",7);

    QStringList groups;
    groups << "Creepy Nuts" << "nobodyknows" << "UNISON SQUARE GARDEN" << "Wednesday Campanella";

    foreach(QString group, groups)
    {
        int value = QRandomGenerator::global()->bounded(11);
        save_point(&settings,"test",group,value);
    }

    //SAVE
    settings.sync();
    qInfo() << "File:" << settings.fileName();

    foreach(QString group, settings.childGroups())
    {
        settings.beginGroup(group);
        qInfo() << "Group:" << group;
        foreach(QString key, settings.childKeys())
        {
            qInfo() << "--key:" << key << " : " << settings.value(key).toString();
        }


        settings.endGroup();
    }

    return a.exec();
}
