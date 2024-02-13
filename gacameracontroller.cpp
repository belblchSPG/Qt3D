#include "gacameracontroller.h"

GACameraController::GACameraController() {}

void GACameraController::CreateCamera(GA::Window3D *view, GA::Entity* _rootEntity)
{
    GA::Camera *camera = view->camera();
    auto cameraEntity = view->camera();
    cameraEntity->setPosition(GA::Vector3D(0, 0, 100.0f));
    cameraEntity->setUpVector(GA::Vector3D(0, 1, 0));
    cameraEntity->setViewCenter(GA::Vector3D(0, 0, 0));

    GA::OrbitCameraController *cameraController = new GA::OrbitCameraController(_rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(60.0f);
}

