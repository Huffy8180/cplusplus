#ifndef MENUITEM_H
#define MENUITEM_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

#include "review.h"

class MenuItem : public QPushButton
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = 0);
    explicit MenuItem(int id=0, QString type = "", QString name = "", QString cost = "", bool available = false, QString ingredients = "", QString options = "", QWidget *parent = 0);
    int id;
    QString type;
    QString name;
    QString cost;
    bool available;
    QStringList ingredients;
    QStringList options;

signals:
    void addOption(QString box);

public slots:
   //virtual bool	hitButton ( const QPoint & pos ) const void showMenu();

protected:
    virtual void mousePressEvent (QMouseEvent * event);
    QSize sizeHint();

private:
  //  Review *review;
    //QCheckBox *box;


};

#endif // MENUITEM_H
