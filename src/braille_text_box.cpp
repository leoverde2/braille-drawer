#include "braille_text_box.h"
#include <qevent.h>
#include <QGraphicsProxyWidget>

BrailleTextProxy :: BrailleTextProxy(QGraphicsItem *parent) : QGraphicsProxyWidget(parent){
    BrailleTextBox* textBox = new BrailleTextBox();
    setWidget(textBox);
} 

BrailleTextBox :: BrailleTextBox(QWidget *parent) : QLineEdit(parent){
    setAlignment(Qt::AlignCenter);
    setMaxLength(1);
    setReadOnly(true);
    setCursor(Qt::ArrowCursor);
    setFrame(false);
    setStyleSheet("QLineEdit { background: transparent }");
}

void BrailleTextBox :: mousePressEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleTextBox :: mouseMoveEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleTextBox :: mouseReleaseEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleTextBox :: focusInEvent(QFocusEvent *event){
    event->ignore();
}

void BrailleTextBox :: focusOutEvent(QFocusEvent *event){
    event->ignore();
}

