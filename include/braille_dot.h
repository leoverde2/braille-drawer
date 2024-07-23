#include "braille_canvas.h"
#include <QPointF>

class BrailleDot{
public:
    BrailleDot(BrailleCanvas* canvas, QPointF& point);

    void turnDotOn();
    void turnDotOff();

private:
    std::optional<int> getBitToSet();
    int getCurrentChar();
    BrailleCanvas* canvas;
    QPointF point;
};
