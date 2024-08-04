#include <qwidget.h>
#include <QGraphicsView>
#include <QGraphicsScene>


class BrailleView : public QGraphicsView {
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

public:
    BrailleView(QGraphicsScene *scene, QWidget *parent = nullptr);
};
