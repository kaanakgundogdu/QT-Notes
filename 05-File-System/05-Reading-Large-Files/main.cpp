#include <QCoreApplication>
#include <QFile>

void read_lines(QFile &file)
{
    if(!file.isReadable())
        return;
    //make sure its position 0
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.readLine(); // untill find \n
    }
}

void read_chunks_byte(QFile &file)
{
    if(!file.isReadable())
        return;
    file.seek(0);
    while(!file.atEnd())
    {
        qInfo() << file.read(80);   // read byte byte
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = "test.txt"; //create this manually

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) //reads the file can not modify it
    {
        qInfo() << "\n-------Read line by line------------\n";
        read_lines(file);
        qInfo() << "\n-------Read Chunks------------\n";
        read_chunks_byte(file);

        file.close();

    }
    else
    {
        qInfo() << file.errorString();
    }


    return a.exec();
}
