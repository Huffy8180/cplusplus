#include "menuitem.h"



MenuItem::MenuItem(QWidget *parent)
{
 this->setText("name");


}

MenuItem::MenuItem(int id, QString type, QString name, QString cost, bool available, QString ingredients, QString options, QWidget *parent) :
    QPushButton(parent)
{
    this->id = id;
    this->type = type;
    this->name = name;
    this->cost = cost;
    this->available = available;
    this->ingredients = ingredients.split(",");
    this->options = options.split(",");
    this->setText(name);
   // this->setFixedHeight(40);


}


void MenuItem::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "testing";
    Review temp;

    //connect(this,SIGNAL(addOption(QString)),R,SLOT(addOption(QString)));
    temp.update_cost(cost);
    temp.setWindowTitle(name);
    for(int i =0; i<options.size();i++)
    {
        addOption(options.value(i));
    }

    temp.exec();
}

QSize MenuItem::sizeHint()
{
    return QSize(this->parentWidget()->width(),this->parentWidget()->height());
}
