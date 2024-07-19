#ifndef BRAILLE_TEXT_BOX_H
#define BRAILLE_TEXT_BOX_H

#include <QLineEdit>
#include <qevent.h>
#include <qwidget.h>
#include <QGraphicsProxyWidget>

class BrailleTextProxy : public QGraphicsProxyWidget{
    Q_OBJECT

public:
    explicit BrailleTextProxy(QGraphicsItem *parent = nullptr);
}; 

class BrailleTextBox : public QLineEdit {
    Q_OBJECT

public:
    explicit BrailleTextBox(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;
};
    

#endif
