#include <QCoreApplication>
#include <QMap>

#define random_map(map,size)\
    {\
        for(int i=0; i<size;i++)\
        {\
            map[i]=QString::number(i+1);\
        }\
    }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<int,QString> map;
    random_map(map,5);

    qInfo()<<map;

    return a.exec();
}
