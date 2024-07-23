#include "tools.h"
#include <qaction.h>
#include <qlogging.h>
#include <qtoolbar.h>

Tool::Tool(BrailleCanvas* canvas): canvas(canvas){}

Pencil::Pencil(BrailleCanvas* canvas): Tool(canvas){}

void Pencil::useTool(QPointF point){
    canvas->drawBrailleAt(point);
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
    ToolManager tool_manager = ToolManager::getInstance();
    Tool* tool;
    if (identifier == "actionPencil")
        tool = new Pencil(canvas);
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
