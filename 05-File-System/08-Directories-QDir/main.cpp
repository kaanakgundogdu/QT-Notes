#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list_directories(QDir &root)
{
    qInfo()  << "---Listing---";
    // infolist -> filter to dir -> by name not ...
    foreach(QFileInfo fi, root.entryInfoList(QDir::Filter::Dirs,QDir::Name))
    {
        if(fi.isDir())
        {
            qInfo() << fi.absoluteFilePath();
        }
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir(QCoreApplication::applicationDirPath());
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

    dir.cdUp();
    qInfo() << dir.absolutePath();
    list_directories(dir);

    dir.mkdir("test");
    list_directories(dir);
    // should be empty for rmdir (remove dir.)
    dir.rmdir("test");
    list_directories(dir);


    return a.exec();
}
