#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = a.applicationDirPath() + "/settings.ini";
    qInfo() << filename;

    QSettings settings(filename,QSettings::Format::IniFormat);
    settings.beginGroup("songs");
    settings.setValue("Sunset",4);
    settings.endGroup();

    settings.sync(); //saving

    settings.beginGroup("songs");
    qInfo() << "Plastic Love: " << settings.value("Plastic Love",QVariant("Song not found!"));
    qInfo() << "Sunset: " << settings.value("Sunset",QVariant("Song not found!"));
    settings.endGroup();


    return a.exec();
}
