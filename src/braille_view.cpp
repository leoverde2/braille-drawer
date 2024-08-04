#include "braille_view.h"
#include <QMouseEvent>
#include <QGraphicsScene>
#include <qlogging.h>


BrailleView::BrailleView(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent){

}


void BrailleView::mousePressEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleView::mouseMoveEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleView::mouseReleaseEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleView::keyPressEvent(QKeyEvent *event){
    event->ignore();
}

void BrailleView::wheelEvent(QWheelEvent *event){
    bool isCtrlPressed = event->modifiers() & Qt::ControlModifier;
    if (isCtrlPressed)
        event->ignore();
    else{
        QGraphicsView::wheelEvent(event);
        event->accept();
    } 
}

