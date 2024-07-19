#include <iostream>
#include "braille_canvas.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qwidget.h>
#include <QMouseEvent> 
#include <QGraphicsEllipseItem>
#include "QProcessEnvironment"
#include <QDir>
#include <QFontDatabase>

#include <QRawFont>
#include <QPainter>
#include <QImage>


BrailleCanvas::BrailleCanvas(QWidget *parent) : QGraphicsView(parent), isDrawing(false){
    setScene(new QGraphicsScene(this));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    scene()->setSceneRect(0, 0, 800, 600);
    setAlignment(Qt::AlignTop | Qt::AlignLeft);

    brailleFont = QFont("DejaVu Sans", fontSize);
    updateGrid();

    qDebug() << "Graphics system:" << QGuiApplication::platformName();
}

void BrailleCanvas::updateGrid(){
    QFontMetrics fm(brailleFont);
    tileWidth = fm.horizontalAdvance("⣿");
    tileHeight = fm.height();

    int sceneWidth = (width() / tileWidth) * tileWidth;
    int sceneHeight = (height() / tileHeight) * tileHeight;
    scene()->setSceneRect(0, 0, sceneWidth, sceneHeight);
}

void BrailleCanvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = true;
        drawBrailleAt(mapToScene(event->pos()));
    }
    QGraphicsView::mousePressEvent(event);
}

void BrailleCanvas::mouseMoveEvent(QMouseEvent *event){
    if (isDrawing){
        drawBrailleAt(mapToScene(event->pos()));
    }
    QGraphicsView::mouseMoveEvent(event);
}

void BrailleCanvas::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = false;
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void BrailleCanvas::drawBackground(QPainter *painter, const QRectF &rect){
    QGraphicsView::drawBackground(painter, rect);

    painter->setPen(QPen(Qt::lightGray, 0.5));

    for (int x = 0; x <= width(); x += tileWidth){
        painter->drawLine(x, 0, x, height());
    }

    for (int y = 0; y <= height(); y += tileHeight) {
        painter->drawLine(0, y, width(), y);
    }
}

QPointF BrailleCanvas::snapToGrid(const QPointF &pos){
    int x = qFloor(pos.x() / tileWidth) * tileWidth - 3;
    int y = qFloor(pos.y() / tileHeight) * tileHeight - 3;
    return QPointF(x, y);
}

void BrailleCanvas::drawBrailleAt(const QPointF &pos){
    QPointF snappedPos = snapToGrid(pos);
    if (scene()->sceneRect().contains(snappedPos)){
        int thresholdX = tileWidth / 2;
        int thresholdY = tileHeight / 4;

        QPointF relativePos = QPointF(fmod(snappedPos.x(), tileWidth), fmod(snappedPos.y(), tileHeight));
        int x = (relativePos.x() >= thresholdX) ? 1 : 0;
        int y = qMin(3, static_cast<int>(relativePos.y() / thresholdY));

        QList<QGraphicsItem*> itemsAtPos = scene()->items(snappedPos);

        QGraphicsTextItem *brailleChar = scene()->addText("⣿", brailleFont);
        QRectF boundingRect = brailleChar->boundingRect();

        brailleChar->setPos(snappedPos);
    }
}
