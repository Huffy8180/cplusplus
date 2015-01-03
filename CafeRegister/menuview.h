#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QWidget>
#include <QGridLayout>
#include "menuitem.h"
#include <QDebug>
class MenuView : public QWidget
{
    Q_OBJECT
public:
    explicit MenuView(QString type, int numberOfColumns, QWidget *parent = 0);

    void addItem(MenuItem *item);

  //  QGridLayout *layout;
    QVBoxLayout *layout;
    QString type;



signals:

public slots:
     void menu_switch(QString type);

private:
    int col;
    int row;
    int numCol;

};

#endif // MENUVIEW_H
