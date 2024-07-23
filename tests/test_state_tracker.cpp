#define TESTING
#include <QtTest/QtTest>
#include "state.h"
#include "braille_canvas.h" // Assuming this is where BrailleCanvas is defined
#include <QDebug>
#include <QApplication>
#include <qtestcase.h>

#define MYCOMPARE(actual, expected) \
do {\
    if (!QTest::qCompare(actual, expected, #actual, #expected, __FILE__, __LINE__)){\
        qDebug() << "Expected: " << expected;\
        qDebug() << "Actual: " << actual;\
        return;\
    }\
    qDebug() << "Expected: " << expected;\
    qDebug() << "Expected name: " << #expected; \
    qDebug() << "Actual: " << actual;\
    qDebug() << "Actual name: " << #actual;\
} while (false)


class TestStateTracker : public QObject
{
    Q_OBJECT

private:
    StateTracker* stateTracker;
    BrailleCanvas* canvas;

private Q_SLOTS:
    void initTestCase();
    void init();
    void cleanup();
    void testUndo();
    void testUndoRedo();
    void testEdge();
    void cleanupTestCase();
};

void TestStateTracker::init(){
    stateTracker = new StateTracker();
    canvas = new BrailleCanvas();
    canvas->stateTrackerSetter(stateTracker);
    canvas->createGrid();
}

void TestStateTracker::cleanup(){
    delete stateTracker;
    delete canvas;
}

void TestStateTracker::initTestCase()
{
}

void TestStateTracker::cleanupTestCase()
{
}

void TestStateTracker::testUndoRedo()
{
    // Initialize states
    QList<QString> initialState = {"A", "B"};
    QList<QString> state1 = {"A", "B", "C"};
    QList<QString> state2 = {"A", "B", "D"};
    QList<QString> state3 = {"A", "B", "E"};

    // Push initial state
    stateTracker->push(new CanvasState(canvas, initialState));

    // Push a series of new states
    stateTracker->push(new CanvasState(canvas, state1));
    stateTracker->push(new CanvasState(canvas, state2));
    stateTracker->push(new CanvasState(canvas, state3));

    // Perform undo operations
    stateTracker->undo();  // Undo to state2
    auto stateAfterUndo1 = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterUndo1->saved_state, state2);

    stateTracker->undo();  // Undo to state1
    auto stateAfterUndo2 = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterUndo2->saved_state, state1);

    stateTracker->undo();  // Undo to initialState
    auto stateAfterUndo3 = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterUndo3->saved_state, initialState);

    // Push a new state after undo operations
    QList<QString> newState = {"A", "B", "F"};
    stateTracker->push(new CanvasState(canvas, newState));

    // Verify the new state
    auto stateAfterPush = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterPush->saved_state, newState);

    // Perform redo operations
    stateTracker->undo();  // Undo to initialState
    stateTracker->redo();  // Redo to newState
    auto stateAfterRedo = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterRedo->saved_state, newState);

    // Optionally, perform additional undo and redo to test edge cases
    stateTracker->undo();  // Undo to initialState
    stateTracker->redo();  // Redo to newState
    auto stateAfterRedoAgain = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(stateAfterRedoAgain->saved_state, newState);

    // Ensure that redo is correctly handled and no extra states are present
    QCOMPARE(stateTracker->state_stack.size(), 2);
}

void TestStateTracker::testEdge(){
    QList<QString> first = {"A", "B", "C", "D"};
    stateTracker->push(new CanvasState(canvas, first));

    QList<QString> second = {"A", "B", "F"};
    stateTracker->push(new CanvasState(canvas, second));

    stateTracker->undo();

    QList<QString> third = {"A", "B", "F", "d"};
    stateTracker->push(new CanvasState(canvas, third));

    stateTracker->undo();

    auto state = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(state->saved_state, first);
}

void TestStateTracker::testUndo()
{
    
    // Push a new state
    QList<QString> first = {"A", "B", "C", "D"};
    stateTracker->push(new CanvasState(canvas, first));

    QList<QString> second = {"A", "B", "F"};
    stateTracker->push(new CanvasState(canvas, second));
    auto state = dynamic_cast<CanvasState*>(stateTracker->state_stack.last());
    MYCOMPARE(state->saved_state, second);

    stateTracker->undo();
    auto state2 = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(state2->saved_state, first);

    QList<QString> third = {"A", "B", "F", "d"};
    stateTracker->push(new CanvasState(canvas, third));

    QList<QString> fourth = {"A", "B", "s"};
    stateTracker->push(new CanvasState(canvas, fourth));

    QList<QString> fifth = {"A", "B", "1"};
    stateTracker->push(new CanvasState(canvas, fifth));

    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();
    stateTracker->undo();


    QList<QString> sixth = {"A", "B", "1", "2"};
    stateTracker->push(new CanvasState(canvas, sixth));
    auto state3 = dynamic_cast<CanvasState*>(stateTracker->state_stack[stateTracker->stack_index]);
    MYCOMPARE(state3->saved_state, sixth);
}



QTEST_MAIN(TestStateTracker)


#include "test_state_tracker.moc"
