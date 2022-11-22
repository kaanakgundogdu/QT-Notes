#include "watcher.h"

Watcher::Watcher(QObject *parent) : QObject(parent)
{
    file_system_watcher.addPath(QDir::currentPath());
    file_system_watcher.addPath(QDir::currentPath() + QDir::separator() + "test.txt");

    connect(&file_system_watcher,&QFileSystemWatcher::fileChanged, this, &Watcher::fileChanged);
    connect(&file_system_watcher,&QFileSystemWatcher::directoryChanged, this, &Watcher::directoryChanged);
}

void Watcher::fileChanged(const QString &path)
{
    qInfo() << "File changed: " << path;
    if(file_system_watcher.files().length())
    {
        qInfo() << "Files that have changed: ";
        foreach(QString file, file_system_watcher.files())
        {
            qInfo() << file;
        }
    }
}

void Watcher::directoryChanged(const QString &path)
{
    qInfo() << "Directory changed: " << path;
    if(file_system_watcher.directories().length())
    {
        qInfo() << "Directory that have changed: ";
        foreach(QString dir, file_system_watcher.directories())
        {
            qInfo() << dir;
        }
    }
}
