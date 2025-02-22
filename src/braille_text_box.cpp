#include "braille_text_box.h"
#include <qevent.h>
#include <QGraphicsProxyWidget>

BrailleTextProxy :: BrailleTextProxy(int row, int col, QGraphicsItem *parent) : QGraphicsProxyWidget(parent), row(row), col(col){} 

BrailleTextBox :: BrailleTextBox(QWidget *parent) : QLineEdit(parent){
    setAlignment(Qt::AlignCenter);
    setMaxLength(1);
    setReadOnly(true);
    setCursor(Qt::ArrowCursor);
    setFrame(false);
    setStyleSheet("QLineEdit { background: transparent }");
    setAttribute(Qt::WA_TranslucentBackground);
    setAutoFillBackground(false);
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

void BrailleTextBox :: mouseDoubleClickEvent(QMouseEvent *event){
    event->ignore();
}

void BrailleTextBox :: focusInEvent(QFocusEvent *event){
    event->ignore();
}

void BrailleTextBox :: focusOutEvent(QFocusEvent *event){
    event->ignore();
}

