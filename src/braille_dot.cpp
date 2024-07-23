#include "braille_dot.h"
#include "braille_text_box.h"

BrailleDot::BrailleDot(BrailleCanvas* canvas, QPointF& point): canvas(canvas), point(point){}

void BrailleDot::turnDotOn(){
    BrailleTextBox* box = canvas->getTextBoxAt(point);
    if (auto bitToSet = getBitToSet()){
        int brailleCode = getCurrentChar();
        brailleCode |= (1 << *bitToSet);
        box->setText(QString(QChar(brailleCode)));
    }
}

void BrailleDot::turnDotOff(){
    BrailleTextBox* box = canvas->getTextBoxAt(point);
    if (auto bitToSet = getBitToSet()){
        int brailleCode = getCurrentChar();
        brailleCode &= ~(1 << *bitToSet);
        box->setText(QString(QChar(brailleCode)));
    }
}

int BrailleDot::getCurrentChar(){
    BrailleTextBox* box = canvas->getTextBoxAt(point);
    QString currentText = box->text();
    QChar brailleChar = currentText.isEmpty() ? QChar(0x2800) : currentText[0];
    int brailleCode = brailleChar.unicode();
    return brailleCode;
}

std::optional<int> BrailleDot::getBitToSet(){
    BrailleTextBox *box = canvas->getTextBoxAt(point); 
    if (box) {
        QRect boxRect = box->geometry();
        double relX = (point.x() - boxRect.left()) / static_cast<double>(boxRect.width());
        double relY = (point.y() - boxRect.top()) / static_cast<double>(boxRect.height());

        int dotX;

        if (relX >= 0.07 && relX < 0.40)
            dotX = 0;
        else if (relX >= 0.40 && relX < 0.63)
            dotX = 1;
        else
            dotX = -1;         

        int dotY;

        if (relY >=0.17 && relY < 0.4)
            dotY = 0;
        else if (relY >= 0.4 && relY < 0.57)
            dotY = 1;
        else if (relY >= 0.57 && relY < 0.75)
            dotY = 2;
        else if (relY >= 0.75 && relY < 0.90)
            dotY = 3;
        else
            dotY = -1;


        if (dotY != -1 && dotX != -1){
            // Calculate the bit to set (0-7)
            int bitToSet;
            if (dotX == 0) {
                if (dotY < 3) {
                    bitToSet = dotY;
                } else {
                    bitToSet = 6;
                }
            } else {
                if (dotY < 3) {
                    bitToSet = dotY + 3;
                } else {
                    bitToSet = 7;
                }
            }
            return bitToSet;
        }
    }
    return std::nullopt;
}
