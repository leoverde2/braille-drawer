#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "braille_canvas.h"
#include "state.h"
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    StateTracker* stateTracker = new StateTracker();
    BrailleCanvas* canvas = ui->centralwidget;
    toolFactory = new ToolFactory(canvas, this);
    toolFactory->connectToolboxActions(ui->toolBar);

    canvas->stateTrackerSetter(stateTracker);
    canvas->createGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}
