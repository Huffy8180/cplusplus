#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <QLayout>

#include "menuview.h"
#include "menuitem.h"
#include "view.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void menu_switch(QString type);

private slots:
    void on_comboBox_type_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;

    void status(QString update);
    void log(QString update);
    void setup();

    QList<MenuView> layout_list;
    MenuView *view;



    View *itemview;
    MenuItem *item;\
    QVBoxLayout *layout;
    QSqlDatabase *db;
    QSqlQuery *query;


    QStringList types;
};

#endif // MAINWINDOW_H
