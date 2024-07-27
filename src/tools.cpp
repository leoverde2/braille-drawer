#include "tools.h"
#include <qaction.h>
#include <qlogging.h>
#include <qtoolbar.h>
#include "braille_dot.h"
#include <stdexcept>

Tool::Tool(BrailleCanvas* canvas): canvas(canvas){}

Pencil::Pencil(BrailleCanvas* canvas): Tool(canvas){}

void Pencil::useTool(QPointF point){
    auto dot = new BrailleDot(canvas, point);
    dot->turnDotOn();
    delete dot;
}

Eraser::Eraser(BrailleCanvas* canvas): Tool(canvas){}

void Eraser::useTool(QPointF point){
    auto dot = new BrailleDot(canvas, point);
    dot->turnDotOff();
    delete dot;
}


ToolManager& ToolManager::getInstance(){
    static ToolManager instance;
    return instance;
}

void ToolManager::setCurrentTool(Tool* tool){
    if (currentTool != nullptr){
        delete currentTool;
    }
    currentTool = tool;
}

void ToolManager::useCurrentTool(QPointF point){
    if (currentTool != nullptr){
        currentTool->useTool(point);
    }
}

Tool* ToolManager::getCurrentTool(){
    return currentTool;
}


ToolFactory::ToolFactory(BrailleCanvas* canvas, QObject* parent)
    : QObject(parent)
    , canvas(canvas){}

Tool* ToolFactory::createTool(){
    QAction* action = qobject_cast<QAction*>(sender());
    QString identifier = action->objectName();
    Tool* tool;
    if (identifier == "actionPencil")
        tool = new Pencil(canvas);
    else if (identifier == "actionEraser")
        tool = new Eraser(canvas);
    else
        throw std::invalid_argument("Invalid tool identifier: " + identifier.toStdString());
    return tool;
}

void ToolFactory::connectToolboxActions(QToolBar* toolbar){
    for (auto action : toolbar->actions()){
        QObject::connect(action, &QAction::triggered, this, [this](){
            Tool* newTool = createTool();
            ToolManager::getInstance().setCurrentTool(newTool);
        });
    }
}
