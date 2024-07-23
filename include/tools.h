#ifndef TOOLS_H
#define TOOLS_H

#include <QPointF>
#include <QObject>
#include <qtoolbar.h>
#include "braille_canvas.h"

class Tool{
public:
    Tool(BrailleCanvas* canvas);
    virtual ~Tool() = default;
    virtual void useTool(QPointF point) = 0;

protected:
    //function that is shared among tools but can be overriden if needed to get the dots that need to be painted based on the current width
    BrailleCanvas* canvas;
};

class Pencil : public Tool{
public:
    Pencil(BrailleCanvas* canvas);

    void useTool(QPointF point) override;
};

class Eraser : public Tool{
public:
    Eraser(BrailleCanvas* canvas);

    void useTool(QPointF point) override;
};


class ToolManager{
public:
    static ToolManager& getInstance();

    void setCurrentTool(Tool* tool);
    Tool* getCurrentTool();
    void useCurrentTool(QPointF point);

private:
    Tool* currentTool = nullptr;
};


class ToolFactory : public QObject {
    Q_OBJECT

public:
    ToolFactory(BrailleCanvas* canvas, QObject *parent = nullptr);

    Tool* createTool();
    void connectToolboxActions(QToolBar* toolbar);
private:
    BrailleCanvas* canvas;
};

#endif

