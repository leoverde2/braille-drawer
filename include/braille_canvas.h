#ifndef BRAILLE_CANVAS_H
#define BRAILLE_CANVAS_H

#include "braille_text_box.h"
#include <QGraphicsView>
#include <qgridlayout.h>
#include <qpoint.h>
#include <qwidget.h>

class BrailleCanvas : public QWidget{
    Q_OBJECT

public:
    explicit BrailleCanvas(QWidget *parent = nullptr);

    void setFontSize(int size);
    void applyZoom(qreal factor, const QPoint &cursorPos);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    bool isDrawing;
    int rows, cols;
    int fontSize;
    QFont brailleFont;

    QGraphicsScene* graphicsScene;
    QGraphicsView* graphicsView;

    void drawBrailleAt(const QPointF &pos);
    void createGrid();
    BrailleTextBox* getTextBoxAt(const QPointF &pos);
};

#endif
