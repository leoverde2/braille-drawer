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
    QVector<QGraphicsRectItem*> gridCells;
    int fontSize;
    QFont brailleFont;
    double zoomFactor;

    QGraphicsScene* graphicsScene;
    QGraphicsView* graphicsView;

    void drawBrailleAt(const QPoint &pos);
    void createGrid();
    QPointF snapToGrid(const QPoint &pos);
    BrailleTextBox* getTextBoxAt(const QPoint &pos);
    void updateGrid();
};

#endif
