#ifndef RECEIPT_H
#define RECEIPT_H

#include <QObject>
#include <QStringList>

class Receipt : public QObject
{
    Q_OBJECT
public:
    explicit Receipt(QObject *parent = 0);
    QStringList order;



signals:

public slots:
    void addItem(QString item);

};

#endif // RECEIPT_H
