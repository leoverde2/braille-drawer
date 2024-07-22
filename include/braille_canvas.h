#ifndef BRAILLE_CANVAS_H
#define BRAILLE_CANVAS_H

#include "braille_text_box.h"
#include <QGraphicsView>
#include <qevent.h>
#include <qgridlayout.h>
#include <qpoint.h>
#include <qwidget.h>
#include <QVector>

class StateTracker;

class BrailleCanvas : public QWidget{
    Q_OBJECT

public:
    explicit BrailleCanvas(QWidget *parent = nullptr);

    void setFontSize(int size);
    QList<BrailleTextProxy> getState();
    void setState(QList<BrailleTextProxy*>);

    void stateTrackerSetter(StateTracker* state_tracker);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

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
    void applyZoom(qreal factor, const QPoint &cursorPos);

    StateTracker* state_tracker;
};

#endif
