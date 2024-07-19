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
    void updateGrid();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QGridLayout *gridLayout;
    bool isDrawing;
    int rows, cols;
    QVector<QGraphicsRectItem*> gridCells;
    int fontSize;
    QFont brailleFont;

    void drawBrailleAt(const QPoint &pos);
    void createGrid();
    QPointF snapToGrid(const QPoint &pos);
    BrailleTextBox* getTextBoxAt(const QPoint &pos);
};

#endif
