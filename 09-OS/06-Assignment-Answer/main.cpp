#include <QCoreApplication>
#include<QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.execute("notepad.exe",QStringList() << "kaanakgundogdu");
    int ex_code= proc.exitCode();
    if(proc.exitCode()==0){
        qInfo() << "Exit code: "<<ex_code;
        proc.execute("notepad.exe",QStringList() << "kaanakgundogdu");
        ex_code= proc.exitCode();
        qInfo() << "Exit code: " << ex_code;
    }


    return a.exec();
}
