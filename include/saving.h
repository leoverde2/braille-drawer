#ifndef SAVING_H
#define SAVING_H

#include <qgraphicsscene.h>
#include <qmainwindow.h>
#include <qwidget.h>
void saveSceneAsImage(QGraphicsScene* scene, QWidget* parent = nullptr);
void saveSceneAsTransparentImage(QGraphicsScene *scene, QWidget* parent);
#endif
