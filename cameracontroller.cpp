#include "cameracontroller.h"

CameraController::CameraController() {}

void CameraController::CreateCamera(Qt3DExtras::Qt3DWindow *view, Qt3DCore::QEntity* _rootEntity)
{
    Qt3DRender::QCamera *camera = view->camera();
    auto cameraEntity = view->camera();
    cameraEntity->setPosition(QVector3D(0, 0, 100.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QOrbitCameraController *cameraController = new Qt3DExtras::QOrbitCameraController(_rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(60.0f);
}

