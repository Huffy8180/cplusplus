#ifndef REVIEW_H
#define REVIEW_H

#include <QDialog>
#include <QCheckBox>
#include "menuitem.h"

class MenuItem;

namespace Ui {
class Review;
}

class Review : public QDialog
{
    Q_OBJECT

public slots:
     void addOption(QString box);


public:
    explicit Review(QWidget *parent = 0);
    void update_cost(QString cost);
    void setItem(MenuItem item);
    ~Review();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Review *ui;
    QString cost_initial;
    QString cost_current;



};

#endif // REVIEW_H
