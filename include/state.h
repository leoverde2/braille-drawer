#ifndef STATE_H
#define STATE_H

#include "braille_canvas.h"
#include <QPointF>
#include <QVector>
#include <any>
#include <qgraphicsitem.h>
#include <qlist.h>

class State{
public:
    std::any saved_state;
    virtual void load() = 0;
    virtual ~State() = default;
};

class CanvasState : public State{
public:
    CanvasState(BrailleCanvas* current_state, QList<QString>);

    BrailleCanvas* canvas;
    QList<QString> saved_state;
    void load();
};


class StateTracker{
public:
    StateTracker();

    void undo();
    void redo();
    void push(State* state);

private:
    int stack_index = 0;
    QVector<State*> state_stack;
};

#endif
