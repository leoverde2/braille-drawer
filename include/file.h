#ifndef SAVING_H
#define SAVING_H

#include <qgraphicsscene.h>
#include <qmainwindow.h>
#include <qwidget.h>
void exportSceneAsImage(QGraphicsScene* scene, QWidget* parent = nullptr);
void exportSceneAsTransparentImage(QGraphicsScene *scene, QWidget* parent);
void saveScene(QGraphicsScene* scene, QWidget *parent);
#endif
