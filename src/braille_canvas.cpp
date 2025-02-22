#include <algorithm>
#include <iostream>
#include "braille_canvas.h"
#include <qgraphicsitem.h>
#include <qgraphicsproxywidget.h>
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
#include <state.h>
#include "tools.h"

BrailleCanvas::BrailleCanvas(QWidget *parent) : QWidget(parent), isDrawing(false){
    setFixedSize(800, 600);
    setFocusPolicy(Qt::StrongFocus);

    int fontId = QFontDatabase::addApplicationFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf");
    if (fontId != -1) {
        QStringList families = QFontDatabase::applicationFontFamilies(fontId);
        if (!families.isEmpty()) {
            brailleFont = QFont(families.first(), 12);
        } else {
            qDebug() << "Font families list is empty";
        }
    } else {
        qDebug() << "Failed to load font";
    }


    graphicsScene = new QGraphicsScene(this);
    QRectF sceneRect(0, 0, 800, 600);
    graphicsScene->setSceneRect(sceneRect);


    borderItem = new QGraphicsRectItem();
    borderItem->setRect(graphicsScene->sceneRect());
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    borderItem->setPen(borderPen);
    graphicsScene->addItem(borderItem);

    graphicsView = new BrailleView(graphicsScene, this);
    graphicsView->setGeometry(rect());
    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->viewport()->setAutoFillBackground(false);
    graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);



    QFontMetrics fm(brailleFont);
    fontWidth = fm.horizontalAdvance(QChar(0x2800));
    fontHeight = fm.height();

    cols = graphicsScene->width() / fontWidth;
    rows = graphicsScene->height() / fontHeight;
}

void BrailleCanvas::changeBorderSize(QRectF rect){
    borderItem->setRect(rect);
}


void BrailleCanvas::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(rect(), graphicsScene->backgroundBrush());
    QWidget::paintEvent(event);
}

void BrailleCanvas::stateTrackerSetter(StateTracker *tracker){
    state_tracker = tracker;
}

QGraphicsScene* BrailleCanvas::getScene(){
    return graphicsScene;
}

void BrailleCanvas::applyZoom(qreal factor, const QPoint &cursorPos){
    QPointF targetScenePos = graphicsView->mapToScene(cursorPos);

    QTransform transform = graphicsView->transform();

    transform.scale(factor, factor);
    graphicsView->setTransform(transform);

    QPointF newCenter = graphicsView->mapFromScene(targetScenePos) - cursorPos + QPointF(graphicsView->viewport()->width() / 2.0, graphicsView->viewport()->height() / 2.0);

    graphicsView->centerOn(graphicsView->mapToScene(newCenter.toPoint()));

}

QList<QList<QString>> BrailleCanvas::getState(){
    QList<QList<QString>> text_list(rows, QList<QString>(cols));
    for(auto *item : graphicsScene->items()){
        if (BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(item)) {
            if (BrailleTextBox *box = dynamic_cast<BrailleTextBox*>(proxy->widget()))
                text_list[proxy->row][proxy->col] = box->text();
        }
    }
    return text_list;
}

void BrailleCanvas::setState(QList<QList<QString>> strings){
    for (auto y = 0; y < strings.size(); ++y){
        for (auto x = 0; x < strings[y].size(); ++x){
            auto coord_y = y * fontHeight;
            auto coord_x = x * fontWidth;
            auto point = QPointF(coord_x, coord_y);
            if (auto proxy = dynamic_cast<BrailleTextProxy*>(graphicsScene->itemAt(point, QTransform()))){
                if (auto box = dynamic_cast<BrailleTextBox*>(proxy->widget())){
                    box->setText(strings[y][x]);
                }
            }
        }
    }
}

void BrailleCanvas::wheelEvent(QWheelEvent *event){
    qreal factor = event->angleDelta().y() > 0 ? 1.2 : 1.0 / 1.2;
    applyZoom(factor, event->position().toPoint());
    event->accept();
}

void BrailleCanvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = true;
        QPointF scenePos = graphicsView->mapToScene(event->pos());
        ToolManager::getInstance().useCurrentTool(scenePos);
    }
}

void BrailleCanvas::mouseMoveEvent(QMouseEvent *event){
    if (isDrawing){
        QPointF scenePos = graphicsView->mapToScene(event->pos());
        ToolManager::getInstance().useCurrentTool(scenePos);
    }
}

void BrailleCanvas::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        CanvasState* saved = new CanvasState(this, getState());
        state_tracker->push(saved);
        isDrawing = false;
    }
}

void BrailleCanvas::keyPressEvent(QKeyEvent *event){
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    if (isCtrlPressed){
        switch (event->key()){
            case Qt::Key_Z:
                state_tracker->undo();
                break;
            case Qt::Key_Y:
                state_tracker->redo();
                break;
        }
    }
}

void BrailleCanvas::clearAllText(){
    auto items = graphicsScene->items();
    for (auto item : items){
        if (auto proxy = dynamic_cast<BrailleTextProxy*>(item)){
            if (auto box = dynamic_cast<BrailleTextBox*>(proxy->widget())){
                box->clear();
            }
        }
    }
}

void BrailleCanvas::createGrid(){
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            BrailleTextProxy *proxy = new BrailleTextProxy(i, j);
            BrailleTextBox *box = new BrailleTextBox();
            proxy->setWidget(box);

            box->setFixedSize(fontWidth, fontHeight);
            box->setFont(brailleFont);
            box->setStyleSheet(QString("font-size: %1px; background-color: transparent").arg(12));

            proxy->setGeometry(QRect(j * fontWidth, i * fontHeight, fontWidth, fontHeight));
            graphicsScene->addItem(proxy);
        }
    }    
    CanvasState* saved = new CanvasState(this, getState());
    state_tracker->push(saved);
}

void BrailleCanvas::resizeGrid(int newWidth, int newHeight){
    cols = newWidth / fontWidth;
    rows = newHeight / fontHeight;

    this->setUpdatesEnabled(false);

    graphicsScene->setSceneRect(0, 0, newWidth, newHeight);
    borderItem->setRect(graphicsScene->sceneRect());


    for (int y = 0; y < rows; ++y){
        for(int x = 0; x < cols; ++x){
            QPointF point(x * fontWidth, y * fontHeight);
            BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(graphicsScene->itemAt(point, QTransform()));

            if (!proxy){
                proxy = new BrailleTextProxy(y, x);
                BrailleTextBox *box = new BrailleTextBox();
                proxy->setWidget(box);
                box->setFixedSize(fontWidth, fontHeight);
                box->setFont(brailleFont);
                box->setStyleSheet(QString("font-size: %1px; background-color: transparent").arg(12));
                graphicsScene->addItem(proxy);
            }
            auto rect = QRect(x * fontWidth, y * fontHeight, fontWidth, fontHeight);
            proxy->setGeometry(rect);
        }
    }

    for (QGraphicsItem* item : graphicsScene->items()) {
        if (item != borderItem) {
            BrailleTextProxy* proxy = dynamic_cast<BrailleTextProxy*>(item);
            if (proxy) {
                if (proxy->row >= rows || proxy->col >= cols) {
                    graphicsScene->removeItem(item);
                    delete item;
                }
            }
        }
    }


    this->setUpdatesEnabled(true);
    this->repaint();
    graphicsView->viewport()->repaint();
}

void BrailleCanvas::createCheckerboardBackground(){
    QPixmap checkerboard(16, 16);
    QPainter painter(&checkerboard);
    painter.fillRect(0, 0, 8, 8, Qt::lightGray);
    painter.fillRect(8, 0, 8, 8, Qt::white);
    painter.fillRect(0, 8, 8, 8, Qt::white);
    painter.fillRect(8, 8, 8, 8, Qt::lightGray);
    QBrush brush(checkerboard);
    graphicsScene->setBackgroundBrush(brush);
}

BrailleTextBox* BrailleCanvas::getTextBoxAt(const QPointF &pos){
    QGraphicsItem *item = graphicsScene->itemAt(pos, QTransform());
    BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(item);
    if (proxy){
        return qobject_cast<BrailleTextBox*>(proxy->widget());
    }
    return nullptr;
}


