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

    void createGrid();
    void clearAllText();
    BrailleTextBox* getTextBoxAt(const QPointF &pos);

    void setFontSize(int size);
    QList<QList<QString>> getState();
    void setState(QList<QList<QString>>);

    void stateTrackerSetter(StateTracker* state_tracker);


    void drawBrailleAt(const QPointF &pos);
    QGraphicsScene* getScene();
    void resizeGrid(int new_width, int new_height);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    bool isDrawing;
    int fontWidth, fontHeight;
    int rows, cols;
    int fontSize;
    QFont brailleFont;
    QGraphicsRectItem *borderItem; 

    QGraphicsScene* graphicsScene;
    QGraphicsView* graphicsView;

    StateTracker* state_tracker;

    void applyZoom(qreal factor, const QPoint &cursorPos);
    void createCheckerboardBackground();
    void paintEvent(QPaintEvent* event) override;
    void changeBorderSize(QRectF rect);
};


#endif
