#include <QCoreApplication>
#include <QFile>

void save_file(QString path, QList<int> &numbers){
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)){
        qInfo()<<"Cant open the file...";
        return;
    }

    QDataStream data_stream(&file);
    data_stream.setVersion(QDataStream::Qt_6_0);
    data_stream<<numbers;
    file.close();
}

QList<int> load_file(QString path){
    QFile file(path);
    QList<int> nums;
    if(!file.open(QIODevice::ReadOnly)){
        qInfo()<<"Cant open the file...";
        return nums;
    }

    QDataStream data_stream(&file);

    if(data_stream.version() != QDataStream::Qt_6_0) {
        qCritical() << "Not same version!";
        file.close();
        return nums;
    }
    data_stream>>nums;
    file.close();
    return nums;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> numbers= {1,2,3,4,5,6};
    QString path="kaanTest.txt";

    save_file(path,numbers);
    QList<int> saved_data = load_file(path);
    qInfo()<<saved_data;
    return a.exec();
}
