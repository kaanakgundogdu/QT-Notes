#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,int> results;
    results.insert("Kaan", 54);
    results.insert("Shitei", 88);
    results.insert("Matsunaga", 47);
    results.insert("Chenon", 96);
    results.insert("Gnu", 15);

    qInfo() << "Keys:" << results.keys();
    qInfo() << "Values:" << results.values();
    qInfo() << "Shitei gets a:" << results["Shitei"];

    results.remove("Choe");
    qInfo() << "is Contains Choe" << results.contains("Rango");

    foreach(QString key, results.keys())
    {
        qInfo() << key << " = " << results[key];
    }

    qInfo() << "Test" << results.value("Test",-1);

    results["Kaan"] = 11;
    qInfo() << "Kaan" << results.value("Kaan",-1);

    results["Test"] = 100;
    qInfo() << "Test" << results.value("Test",-1);


    return a.exec();
}
