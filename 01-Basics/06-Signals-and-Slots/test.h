#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    void testing();

    ~Test();

signals:
    //Always public, defined. Never implemented.
    void alarm(QString str);


public slots:
    // Can be public,private,protected, always defined and implemented
    // Must match the signal
    void wake(QString str);


};

#endif // TEST_H
