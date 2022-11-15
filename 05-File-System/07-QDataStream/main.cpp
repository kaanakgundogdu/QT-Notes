#include <QCoreApplication>
#include <QFile>
#include <QDataStream>

bool write(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qInfo() << file.errorString();
        return false;
    }
    QDataStream stream(&file);
    //set version and check later
    stream.setVersion(QDataStream::Qt_6_0);

    int age = 27;
    QString name = "Kaan";
    double weight_kg = 75;
    double height_m = 1.75;

    stream << age << name << weight_kg << height_m;


    qInfo() << "Writing file";

    stream << age << name << weight_kg;
    // if cant flush return false
    if(!file.flush())
    {
        qInfo() << file.errorString();
        file.close();
        return false;
    }

    qInfo() << "Closing file";

    file.close();

    return true;
}

bool read(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo() << file.errorString();
        return false;
    }


    QDataStream stream(&file);
    if(stream.version() != QDataStream::Qt_6_0)
    {
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }

    int age;
    QString name;
    double weight_kg;
    double height_m;
    //Make sure is ordered correctly
    stream >> age;
    stream >> name;
    stream >> weight_kg;
    stream >> height_m;

    //make sure close when you dont need anymore
    file.close();

    qInfo() << "Name" << name;
    qInfo() << "Age" << age;
    qInfo() << "Weight" << weight_kg;
    qInfo() << "Height" << height_m;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString filename = "test.txt";

    if(write(filename))
        read(filename);

    return a.exec();
}
