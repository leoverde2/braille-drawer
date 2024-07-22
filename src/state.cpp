#include "state.h"
#include <qlist.h>
#include <QDebug>

StateTracker::StateTracker()
    :stack_index(0){
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
    if (stack_index < state_stack.size() - 1)
        state_stack.erase(state_stack.begin() + stack_index, state_stack.end());
    state_stack.append(state);
    stack_index ++;
}

CanvasState::CanvasState(BrailleCanvas* current_canvas, QList<QString> saved_state)
    : canvas(current_canvas), 
    saved_state(saved_state){
}

void CanvasState::load(){
    canvas->setState(saved_state);
}
