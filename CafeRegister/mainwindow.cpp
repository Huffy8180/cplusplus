#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     QApplication::setStyle(QStyleFactory::create("Fusion"));
    ui->setupUi(this);
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("C:/Users/PinkyXP/Projects/CafeRegister/Cafe");

    if(db->open())
    {
        status("Database Opened");
        query = new QSqlQuery(*db);
    }
    else
    {   status("Database Failed to Open"); }
    setup();
    status("Ready");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::status(QString update)
{
    ui->label_status->setText("Status:  "+update);
    log(update);
}

void MainWindow::log(QString update)
{
    update.clear();
}


void MainWindow::setup()
{
    QGridLayout lay;
    ui->scrollAreaWidgetContents->setLayout(&lay);
    query->exec("SELECT Type FROM MenuType ORDER BY Type ASC");
    while (query->next())
    {
        types.append(query->value(0).toString());
    }
    ui->comboBox_type->addItems(types);

    for(int k=0;k<types.size();k++)
    {
        view = new MenuView(types.value(k),4,ui->scrollAreaWidgetContents);
        connect(this,SIGNAL(menu_switch(QString)),view,SLOT(menu_switch(QString)));

        view->setObjectName(types.value(k));
        query->exec("SELECT * FROM MenuItems WHERE Type = '"+types.value(k)+"'");
        while(query->next())
        {
            item = new MenuItem(query->value(0).toInt(),query->value(1).toString(),query->value(2).toString(),query->value(3).toString(),query->value(4).toBool(),query->value(5).toString(),query->value(6).toString(),view);
            view->addItem(item);
        }
    }
    emit on_comboBox_type_activated(ui->comboBox_type->currentText());
}

void MainWindow::on_comboBox_type_activated(const QString &arg1)
{
    menu_switch(arg1);
}
