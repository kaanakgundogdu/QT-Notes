#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>
#include <QDebug>

void do_cpp(){
    std::string name;
    std::cout<<"Enter your name: ";
    std::getline(std::cin,name);
    std::cout<<"Your name is "<<name<<"\n"<<std::endl;
}

void do_qt(){
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    qout<<"Enter your name: ";
    qout.flush();
    QString name= qin.readLine();
    qout<<"Hello "<<name;
    qout.flush();
}

void do_mixed(){
    QTextStream qin(stdin);
    qInfo() << "Please enter your name: ";
    QString name=qin.readLine();
    qInfo()<<"Hello"<<name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //do_cpp();
    //do_qt();
    do_mixed();
    return a.exec();
}
