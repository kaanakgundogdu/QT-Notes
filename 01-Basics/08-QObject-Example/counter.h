#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);

    int value() const { return m_value; }
    void set_val_test(int num);
public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;

};

#endif // COUNTER_H
