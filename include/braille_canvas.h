#ifndef BRAILLE_CANVAS_H
#define BRAILLE_CANVAS_H

#include <QGraphicsView>
#include <qpoint.h>
#include <qwidget.h>

class BrailleCanvas : public QGraphicsView{
    Q_OBJECT

public:
    explicit BrailleCanvas(QWidget *parent = nullptr);

    void setFontSize(int size);
    void updateGrid();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    bool isDrawing;
    int fontSize;
    int tileWidth;
    int tileHeight;
    QFont brailleFont;
    void drawBrailleAt(const QPointF &pos);
    QPointF snapToGrid(const QPointF &pos);
};

#endif
