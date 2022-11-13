#include <QCoreApplication>
#include <QDebug>
#include <QList>

QList<int> make_list(){
    QList<int> ints {1,2,3,4,5,6,7,8,9,10};
    return ints;
}
void find(QList<int> &l, int value_to_find){

    if(l.contains(value_to_find)){
        qInfo()<<"Found "<<value_to_find << " at "<<l.indexOf(value_to_find);
        return;
    }
    qInfo()<<"Couldn't found "<<value_to_find;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list=make_list();
    qInfo()<< list;
    find(list,5);
    return a.exec();
}
