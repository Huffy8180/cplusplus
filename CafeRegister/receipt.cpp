#include "receipt.h"

Receipt::Receipt(QObject *parent) :
    QObject(parent)
{
    order.clear();
}

void Receipt::addItem(QString item)
{
    order << item;
}
