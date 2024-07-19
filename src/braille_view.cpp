#include "braille_view.h"
#include <QMouseEvent>
#include <QGraphicsScene>


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
