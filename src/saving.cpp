#include "saving.h"
#include <qfiledialog.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qwidget.h>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>

void saveSceneAsImage(QGraphicsScene *scene, QWidget *parent) {
    QString fileName = QFileDialog::getSaveFileName(parent, "Save Image", "", "Images (*.png)");

    QSize size = scene->sceneRect().size().toSize();

    QPixmap pixmap(size);

    QPainter painter(&pixmap);

    scene->render(&painter);
    painter.end();


    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    pixmap.save(&file, "PNG");

    file.close();
}



