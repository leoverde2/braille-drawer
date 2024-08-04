#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "braille_canvas.h"
#include "state.h"
#include <QAction>
#include "file.h"
#include "image_menu.h"
#include "ui_resize.h"

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
        exportSceneAsTransparentImage(scene, this);
    });

    QObject::connect(ui->actionResize, &QAction::triggered, this, [this](){ 
        auto dialog = std::make_unique<QDialog>();
        auto resize_ui = std::make_unique<Ui_Resize>();
        resize_ui->setupUi(dialog.get());

        ImageMenu::resize(ui->centralwidget, std::move(dialog), std::move(resize_ui));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
