#include "state.h"
#include "braille_text_box.h"
#include <qlist.h>


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
    state_stack[stack_index] = state;
    stack_index ++;
}

CanvasState::CanvasState(BrailleCanvas* current_canvas, QList<QGraphicsItem*> saved_state)
    : canvas(current_canvas), 
    saved_state(saved_state){
}

void CanvasState::load(){
    QList<BrailleTextProxy*> proxies;
    for (auto item : saved_state){
        BrailleTextProxy* proxy = dynamic_cast<BrailleTextProxy*>(item);
        proxies.append(proxy);
    }
    canvas->setState(proxies);
}
