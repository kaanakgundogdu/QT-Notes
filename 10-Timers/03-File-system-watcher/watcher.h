#ifndef WATCHER_H
#define WATCHER_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFileSystemWatcher>

class Watcher : public QObject
{
    Q_OBJECT
public:
    explicit Watcher(QObject *parent = nullptr);

signals:

public slots:
    void fileChanged(const QString &path);
    void directoryChanged(const QString &path);

private:
    QFileSystemWatcher file_system_watcher;
};

#endif // WATCHER_H
