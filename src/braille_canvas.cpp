#include <iostream>
#include "braille_canvas.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgridlayout.h>
#include <qwidget.h>
#include <QMouseEvent> 
#include <QGraphicsEllipseItem>
#include "QProcessEnvironment"
#include <QDir>
#include <QFontDatabase>
#include "braille_text_box.h"

BrailleCanvas::BrailleCanvas(QWidget *parent) : QWidget(parent), isDrawing(false){
    setFixedSize(800, 600);

    int fontId = QFontDatabase::addApplicationFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf");
    if (fontId != -1) {
        QFontDatabase fontDb;
        QStringList families = QFontDatabase::applicationFontFamilies(fontId);
        if (!families.isEmpty()) {
            brailleFont = QFont(families.first(), 12);
        } else {
            qDebug() << "Font families list is empty";
        }
    } else {
        qDebug() << "Failed to load font";
    }
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    createGrid();

}


void BrailleCanvas::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = true;
        drawBrailleAt(event->pos());
    }
}

void BrailleCanvas::mouseMoveEvent(QMouseEvent *event){
    if (isDrawing){
        drawBrailleAt(event->pos());
    }
}

void BrailleCanvas::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        isDrawing = false;
    }
}

void BrailleCanvas::createGrid(){
    QFontMetrics fm(brailleFont);
    int font_width = fm.horizontalAdvance(QChar(0x2800));
    int font_height = fm.height();

    cols = width() / font_width;
    rows = height() / font_height;

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            BrailleTextBox *box = new BrailleTextBox(this);
            box->setFixedSize(font_width, font_height);
            box->setFont(brailleFont);
            gridLayout->addWidget(box, i, j);
        }
    }
}

BrailleTextBox* BrailleCanvas::getTextBoxAt(const QPoint &pos){
    QWidget *widget = childAt(pos);
    return qobject_cast<BrailleTextBox*>(widget);
}




void BrailleCanvas::drawBrailleAt(const QPoint &pos) {
    BrailleTextBox *box = getTextBoxAt(pos);
    if (box) {
        QRect boxRect = box->geometry();
        double relX = (pos.x() - boxRect.left()) / static_cast<double>(boxRect.width());
        double relY = (pos.y() - boxRect.top()) / static_cast<double>(boxRect.height());

        int dotX = relX < 0.5 ? 0 : 1;
        int dotY = std::min(static_cast<int>(relY * 4), 3);  // Ensure dotY is 0, 1, 2, or 3
        std::cout << "x:" << dotX;
        std::cout << "y:" << dotY << std::endl;


        QString currentText = box->text();
        QChar brailleChar = currentText.isEmpty() ? QChar(0x2800) : currentText[0];
        int brailleCode = brailleChar.unicode();

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
        std::cout << "bit" << bitToSet + 1 << std::endl;

        // Set the appropriate bit in the Braille code
        brailleCode |= (1 << bitToSet);

        box->setText(QString(QChar(brailleCode)));
    }
}
