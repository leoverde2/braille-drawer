#include "state.h"
#include <qlist.h>
#include <QDebug>

StateTracker::StateTracker()
:stack_index(-1){
}

void StateTracker::undo(){
    if (stack_index > 0){
        --stack_index;
        state_stack[stack_index]->load();
    }
}

void StateTracker::redo(){
    if (stack_index < state_stack.size() - 1){
        ++stack_index;
        state_stack[stack_index]->load();
    }
}

void StateTracker::push(State* state){
    stack_index ++;
    if (stack_index >= state_stack.size())
        state_stack.resize(stack_index + 1);
    state_stack[stack_index] = state;
}



CanvasState::CanvasState(BrailleCanvas* current_canvas, QList<QString> saved_state)
    : canvas(current_canvas), 
    saved_state(saved_state){
}

void CanvasState::load(){
    canvas->setState(saved_state);
}
