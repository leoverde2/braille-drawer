#include "state.h"
#include <qlist.h>
#include <QDebug>

StateTracker::StateTracker()
:stack_index(-1){
}

StateTracker::~StateTracker(){
    qDeleteAll(state_stack);
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
    if (stack_index < state_stack.size() - 1) {
        qDeleteAll(state_stack.begin() + stack_index + 1, state_stack.end());
        state_stack.erase(state_stack.begin() + stack_index + 1, state_stack.end());
    }
    state_stack.push_back(state);
    ++stack_index;
}

//void StateTracker::debug(){
//    for (auto state : state_stack){
//        if (auto s = dynamic_cast<CanvasState*>(state)){
//            QString output;
//            for (const auto& str : s->saved_state){
//                output += str;
//            }
//            qDebug() << output;
//        }
//    }
//    qDebug() << "Index: " << stack_index; 
//    qDebug() << "Size: " << state_stack.size();
//    qDebug() << "END";
//}



CanvasState::CanvasState(BrailleCanvas* current_canvas, QList<QList<QString>> saved_state)
    : canvas(current_canvas), 
    saved_state(saved_state){
}

void CanvasState::load(){
    canvas->setState(saved_state);
}
