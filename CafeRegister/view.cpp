
#include "informationwindow.h"
#include "imageitem.h"
#include "view.h"

//! [0]
View::View(const QString &items, const QString &images, QWidget *parent)
    : QGraphicsView(parent)
{
    itemTable = new QSqlRelationalTableModel(this);
    itemTable->setTable(items);
    itemTable->setRelation(1, QSqlRelation(images, "Name", "Menu"));
    itemTable->select();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,parent->width(),parent->height());
    setScene(scene);

    addItems();

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 370));
    gradient.setColorAt(0, QColor("#868482"));
    gradient.setColorAt(1, QColor("#5d5b59"));
    setBackgroundBrush(gradient);
}

void View::addItems()
{
    int itemCount = itemTable->rowCount();

    int imageOffset = 150;
    int leftMargin = 70;
    int topMargin = 40;

    for (int i = 0; i < itemCount; i++) {
        ImageItem *image;
        QGraphicsTextItem *label;
        QSqlRecord record = itemTable->record(i);

        //int id = record.value("id").toInt();
        //QString file = record.value("file").toString();
        QString item = record.value("Name").toString();

        int columnOffset = ((i % 2) * 37);
        int x = ((i % 2) * imageOffset) + leftMargin + columnOffset;
        int y = ((i / 2) * imageOffset) + topMargin;

        image = new ImageItem(2, QPixmap());
        image->setData(0, i);
        image->setPos(x, y);
        scene->addItem(image);

        label = scene->addText(item);
        label->setDefaultTextColor(QColor("#d7d6d5"));
        QPointF labelOffset((120 - label->boundingRect().width()) / 2, 120.0);
        label->setPos(QPointF(x, y) + labelOffset);
    }
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
    if (QGraphicsItem *item = itemAt(event->pos())) {
        if (ImageItem *image = qgraphicsitem_cast<ImageItem *>(item))
            showInformation(image);
    }
    QGraphicsView::mouseReleaseEvent(event);
}


void View::showInformation(ImageItem *image)
{
    int id = image->id();
    if (id < 0 || id >= itemTable->rowCount())
        return;

    InformationWindow *window = findWindow(id);
    if (window && window->isVisible()) {
        window->raise();
        window->activateWindow();
    } else if (window && !window->isVisible()) {
        window->show();
    } else {
        InformationWindow *window;
        window = new InformationWindow(id, itemTable, this);

        connect(window, SIGNAL(imageChanged(int,QString)),
                this, SLOT(updateImage(int,QString)));

        window->move(pos() + QPoint(20, 40));
        window->show();
        informationWindows.append(window);
    }
}

void View::updateImage(int id, const QString &fileName)
{
    QList<QGraphicsItem *> items = scene->items();

    while(!items.empty()) {
        QGraphicsItem *item = items.takeFirst();

        if (ImageItem *image = qgraphicsitem_cast<ImageItem *>(item)) {
            if (image->id() == id){
                image->setPixmap(QPixmap(":/" +fileName));
                image->adjust();
                break;
            }
        }
    }
}

InformationWindow* View::findWindow(int id)
{
    QList<InformationWindow*>::iterator i, beginning, end;

    beginning = informationWindows.begin();
    end = informationWindows.end();

    for (i = beginning; i != end; ++i) {
        InformationWindow *window = (*i);
        if (window && (window->id() == id))
            return window;
    }
    return 0;
}

