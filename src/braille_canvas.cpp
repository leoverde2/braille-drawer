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
    graphicsView = new BrailleView(graphicsScene, this);
    graphicsView->setGeometry(rect());
    graphicsView->setRenderHint(QPainter::Antialiasing);


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

QList<QString> BrailleCanvas::getState(){
    QList<QString> text_list;
    for(auto *item : graphicsScene->items()){
        if (BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(item)) {
            if (BrailleTextBox *box = dynamic_cast<BrailleTextBox*>(proxy->widget()))
                text_list.append(box->text());
        }
    }
    return text_list;
}

void BrailleCanvas::setState(QList<QString> strings){
    QList<QGraphicsItem*> items = graphicsScene->items(); 
    for (auto i = 0; i < strings.size(); ++i){
        if (auto proxy = dynamic_cast<BrailleTextProxy*>(items[i])){
            if (auto box = dynamic_cast<BrailleTextBox*>(proxy->widget())){
                box->setText(strings[i]);
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
    QFontMetrics fm(brailleFont);
    int font_width = fm.horizontalAdvance(QChar(0x2800));
    int font_height = fm.height();

    cols = width() / font_width;
    rows = height() / font_height;

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            BrailleTextProxy *proxy = new BrailleTextProxy();
            BrailleTextBox *box = new BrailleTextBox();
            proxy->setWidget(box);

            box->setFixedSize(font_width, font_height);
            box->setFont(brailleFont);
            box->setStyleSheet(QString("font-size: %1px").arg(12));

            proxy->setGeometry(QRect(j * font_width, i * font_height, font_width, font_height));
            graphicsScene->addItem(proxy);
        }
    }    
    CanvasState* saved = new CanvasState(this, getState());
    state_tracker->push(saved); // i think the problem is that the state pointer is getting +1 here
}

BrailleTextBox* BrailleCanvas::getTextBoxAt(const QPointF &pos){
    QGraphicsItem *item = graphicsScene->itemAt(pos, QTransform());
    BrailleTextProxy *proxy = dynamic_cast<BrailleTextProxy*>(item);
    if (proxy){
        return qobject_cast<BrailleTextBox*>(proxy->widget());
    }
    return nullptr;
}


