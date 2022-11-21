#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

bool makeFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QByteArray data;
        for(int i = 0; i < 1000; i++)
        {
            if(i%10==0 && i!=0){
                data.append(QString::number(i).toUtf8() + "\r\n");
            }else{
                data.append(QString::number(i).toUtf8() + " ");
            }
        }

        file.write(data);
        file.close();

        return true;
    }

    return false;
}

QByteArray getHeader() {
    QByteArray header;
    header.append("@$@£@");
    return header;
}

bool compressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    QByteArray header = getHeader();

    if(!ofile.open(QIODevice::ReadOnly)) return false;
    if(!nfile.open(QIODevice::WriteOnly)) return  false;
    int size = 1024;

    while (!ofile.atEnd())
    {
        QByteArray buffer = ofile.read(size);
        QByteArray compressed = qCompress(buffer,9);
        //after reading 1024 add header then add what is inside
        nfile.write(header);
        nfile.write(compressed);
    }

    ofile.close();
    nfile.close();

    qInfo() << "Finished compressing successfully.";

    return true;
}

bool decompressFile(QString originalFile, QString newFile)
{
    QFile original_file(originalFile);
    QFile new_file(newFile);
    QByteArray header = getHeader();
    int size = 1024;

    // if cant open return
    if(!original_file.open(QIODevice::ReadOnly)) return false;
    if(!new_file.open(QIODevice::WriteOnly)) return false;


    //Make sure WE created this file!!!
    // peek just look dont change pos
    QByteArray buffer = original_file.peek(size);
    if(!buffer.startsWith(header))
    {
        qCritical() << "We did not create this file! There is no compressed file!";
        original_file.close();
        new_file.close();
        return false;
    }


    //Find the header positions
    original_file.seek(header.length());

    while (!original_file.atEnd())
    {
        buffer = original_file.peek(size);
        qint64 index = buffer.indexOf(header);
        qDebug() << "Head found at:" << index;

        if(index > -1)
        {
            //We found a header
            qint64 maxbytes = index;
            qInfo() << "Reading:" << maxbytes;
            buffer = original_file.read(maxbytes);
            original_file.read(header.length());
        }
        else
        {
            //Do not have a header!
            qInfo() << "Read all no header";
            buffer = original_file.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        new_file.write(decompressed);
        new_file.flush();
    }

    original_file.close();
    new_file.close();

    return true;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = "original.txt";
    QString compressedFile = "compressed.txt";
    QString decompressedFile = "decompressed.txt";

    if(makeFile(originalFile)) {
        qInfo() << "Original created";

        if(compressFile(originalFile, compressedFile)) {
            qInfo() << "File compressed";
            if(decompressFile(compressedFile,decompressedFile)) {
                qInfo() << "File decompressed!";
            } else {
                qInfo() << "Could not decompress file!";
            }
        } else {
            qInfo() << "File not compressed";
        }
    }

    return a.exec();
}
