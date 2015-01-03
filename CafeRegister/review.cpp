#include "review.h"
#include "ui_review.h"
#include <QDebug>


Review::Review(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Review)
{
    ui->setupUi(this);
    //update_cost(cost);


}

Review::~Review()
{
    delete ui;
}

void Review::addOption(QString box)
{

   // QCheckBox boxy = new QCheckBox(box,this->parentWidget());
   // ui->horizontalLayout->addWidget(boxy);
}

void Review::update_cost(QString cost)
{
    ui->label_cost->setText("$ "+cost);
    this->cost_initial = cost;
    this->cost_current = cost;
}

void Review::setItem(MenuItem item)
{

}

void Review::on_buttonBox_accepted()
{
    qDebug() << ui->label_cost->text();
    this->cost_current ;

}

void Review::on_buttonBox_rejected()
{
    this->cost_current = this->cost_initial;
}
