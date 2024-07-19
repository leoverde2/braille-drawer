#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "braille_canvas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    BrailleCanvas* canvas = ui->graphicsView;
}

MainWindow::~MainWindow()
{
    delete ui;
}
