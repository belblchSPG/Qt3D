#ifndef __GA_H
#define __GA_H

#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

#include <Qt3DCore>
#include <Qt3DExtras>
#include <QVector3D>
#include <QQuaternion>
#include <Qt3DRender>
#include <QBuffer>
#include <QGraphicsOpacityEffect>
#include <QLineEdit>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QToolBar>


namespace GA
{

using Point = QVector3D;
using Vector = QVector3D;
using Vector3D = QVector3D;
using Size = QVector3D;
using Rotation = QVector3D;
using Quaternion = QQuaternion;
using Color = QColor;
using Entity = Qt3DCore::QEntity;
using DiffuseMaterial = Qt3DExtras::QDiffuseSpecularMaterial;
using Transform = Qt3DCore::QTransform;
using CuboidMesh = Qt3DExtras::QCuboidMesh;
using Window3D = Qt3DExtras::Qt3DWindow;
using String = QString;
using Camera = Qt3DRender::QCamera;
using OrbitCameraController = Qt3DExtras::QOrbitCameraController;

enum IntersectionType : int{
    NoIntersection = 0,
    SharedVertex = 1, // rgb(170, 130, 140)
    PartialIntersection = 2, //cyan
    FullIntersection = 3 //blue
};

class GACube;
class GACubeMathRepresentation;
class GACubeGraphicRepresentation;
class GAScene;
class GAObjectManager;
class GAParser;
class GACameraController;
class GAAppWindow;
}


#endif // __GA_H
