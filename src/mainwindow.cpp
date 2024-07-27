#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "braille_canvas.h"
#include "state.h"
#include <QAction>
#include "saving.h"

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
    QObject::connect(ui->actionSave, &QAction::triggered, this, [this](){
        QGraphicsScene *scene = ui->centralwidget->getScene();
        saveSceneAsTransparentImage(scene, this);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
