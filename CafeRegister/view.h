#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QtSql>
#include <QScreen>

class ImageItem;
class InformationWindow;



class View : public QGraphicsView
{
    Q_OBJECT
public:
    View(const QString &items, const QString &images, QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void updateImage(int id, const QString &fileName);

private:
    void addItems();
    InformationWindow* findWindow(int id);
    void showInformation(ImageItem *image);


    //QScreen *screen;
    QGraphicsScene *scene;
    QList<InformationWindow *> informationWindows;
    QSqlRelationalTableModel *itemTable;
};

#endif



