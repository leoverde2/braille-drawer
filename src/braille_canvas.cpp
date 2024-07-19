#include <iostream>
#include "braille_canvas.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgridlayout.h>
#include <qwidget.h>
#include <QMouseEvent> 
#include <QGraphicsEllipseItem>
#include "QProcessEnvironment"
#include <QDir>
#include <QFontDatabase>
#include "braille_text_box.h"
#include "braille_view.h"

BrailleCanvas::BrailleCanvas(QWidget *parent) : QWidget(parent), isDrawing(false){
    setFixedSize(800, 600);

    int fontId = QFontDatabase::addApplicationFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf");
    if (fontId != -1) {
        QFontDatabase fontDb;
        QStringList families = QFontDatabase::applicationFontFamilies(fontId);
        if (!families.isEmpty()) {
            brailleFont = QFont(families.first(), 12);
        } else {
            qDebug() << "Font families list is empty";
        }
    } else {
        qDebug() << "Failed to load font";
    }
   
    zoomFactor = 1;

    graphicsScene = new QGraphicsScene(this);
    graphicsView = new BrailleView(graphicsScene, this);
    graphicsView->setGeometry(rect());
    graphicsView->setRenderHint(QPainter::Antialiasing);

    createGrid();

}

void BrailleCanvas::wheelEvent(QWheelEvent *event){
    qreal factor = event->angleDelta().y() > 0 ? 1.2 : 1.0 / 1.2;
    applyZoom(factor, event->position().toPoint());
    event->accept();
}

void BrailleCanvas::applyZoom(qreal factor, const QPoint &cursorPos){
    QTransform transform = graphicsView->transform();

    transform.scale(factor, factor);
    graphicsView->setTransform(transform);

    QPointF cursorScenePos = graphicsView->mapToScene(cursorPos);
    QPointF newScrollPos = cursorScenePos - (cursorScenePos - graphicsView->mapFromScene(cursorScenePos) / factor);
}

//void BrailleCanvas::updateGrid(){
//    QLayoutItem *child;
//    while ((child = gridLayout->takeAt(0)) != nullptr){
//        delete child->widget();
//        delete child;
//    }
//    createGrid();
//}

void BrailleCanvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = true;
        QPointF scenePos = graphicsView->mapToScene(event->pos());
        drawBrailleAt(QPoint(static_cast<int>(scenePos.x()), static_cast<int>(scenePos.y())));
    }
}

void BrailleCanvas::mouseMoveEvent(QMouseEvent *event){
    if (isDrawing){
        QPointF scenePos = graphicsView->mapToScene(event->pos());
        drawBrailleAt(QPoint(static_cast<int>(scenePos.x()), static_cast<int>(scenePos.y())));
    }
}

void BrailleCanvas::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = false;
    }
}

void BrailleCanvas::createGrid(){
    QFontMetrics fm(brailleFont);
    int font_width = fm.horizontalAdvance(QChar(0x2800)) * zoomFactor;
    int font_height = fm.height() * zoomFactor;

    cols = width() / font_width;
    rows = height() / font_height;

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            BrailleTextProxy *proxy = new BrailleTextProxy();
            BrailleTextBox *box = qobject_cast<BrailleTextBox*>(proxy->widget());
            box->setFixedSize(font_width, font_height);
            box->setFont(brailleFont);
            box->setStyleSheet(QString("font-size: %1px").arg(12 * zoomFactor));

            proxy->setGeometry(QRect(j * font_width, i * font_height, font_width, font_height));
            graphicsScene->addItem(proxy);
        }
    }
}

BrailleTextBox* BrailleCanvas::getTextBoxAt(const QPoint &pos){
    QGraphicsItem *item = graphicsScene->itemAt(pos, QTransform());
    BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(item);
    if (proxy){
        return qobject_cast<BrailleTextBox*>(proxy->widget());
    }
    return nullptr;
}




void BrailleCanvas::drawBrailleAt(const QPoint &pos) {
    BrailleTextBox *box = getTextBoxAt(pos);
    if (box) {
        QRect boxRect = box->geometry();
        double relX = (pos.x() - boxRect.left()) / static_cast<double>(boxRect.width());
        double relY = (pos.y() - boxRect.top()) / static_cast<double>(boxRect.height());

        int dotX = relX < 0.5 ? 0 : 1;
        int dotY = std::min(static_cast<int>(relY * 4), 3);  // Ensure dotY is 0, 1, 2, or 3


        QString currentText = box->text();
        QChar brailleChar = currentText.isEmpty() ? QChar(0x2800) : currentText[0];
        int brailleCode = brailleChar.unicode();

        // Calculate the bit to set (0-7)
        int bitToSet;
        if (dotX == 0) {
            if (dotY < 3) {
                bitToSet = dotY;
            } else {
                bitToSet = 6;
            }
        } else {
            if (dotY < 3) {
                bitToSet = dotY + 3;
            } else {
                bitToSet = 7;
            }
        }

        // Set the appropriate bit in the Braille code
        brailleCode |= (1 << bitToSet);

        box->setText(QString(QChar(brailleCode)));
    }
}
