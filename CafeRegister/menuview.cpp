#include "menuview.h"


MenuView::MenuView(QString type, int numberOfColumns, QWidget *parent) :
    QWidget(parent)
{
    col = 0;
    row = 0;
    numCol = numberOfColumns;
    //layout = new QGridLayout(this);
    layout = new QVBoxLayout(this);

    this->setLayout(layout);

}

void MenuView::addItem(MenuItem *item)
{
    //layout->addWidget(item,row,col,1,1);
    layout->addWidget(item,2,Qt::AlignLeft);

    col++;
    if(col == numCol)
    {
        col =0;
        row++;
    }
}

void MenuView::menu_switch(QString type)
{
    if(type == this->objectName())
    {
        this->show();
    }
    else{ this->hide(); }
}
