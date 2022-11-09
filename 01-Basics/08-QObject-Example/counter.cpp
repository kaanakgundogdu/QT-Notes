#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}
{

}

void Counter::set_val_test(int num)
{
    emit valueChanged(num);
}


void Counter::setValue(int value)
{
    m_value=value;
}
