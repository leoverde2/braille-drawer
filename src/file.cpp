#include "file.h"
#include <qfiledialog.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qwidget.h>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include "braille_text_box.h"

void exportSceneAsImage(QGraphicsScene *scene, QWidget *parent) {
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

void exportSceneAsTransparentImage(QGraphicsScene* scene, QWidget *parent){
    QString fileName = QFileDialog::getSaveFileName(parent, "Save Transparent Image", "", "Images (*.png)");
    if (fileName.isEmpty())
        return;

    QSize size = scene->sceneRect().size().toSize();
    QImage image(size, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);

    for (QGraphicsItem* item : scene->items()) {
        if (BrailleTextProxy* proxy = dynamic_cast<BrailleTextProxy*>(item)) {
            if (BrailleTextBox* box = dynamic_cast<BrailleTextBox*>(proxy->widget())) {
                // Render only the text content
                QPointF pos = proxy->scenePos();
                painter.setFont(box->font());
                painter.drawText(QRectF(pos, box->size()), box->text());
            }
        }
    }

    painter.end();

    image.save(fileName, "PNG");
}

void saveScene(QGraphicsScene* scene, QWidget *parent){

}



