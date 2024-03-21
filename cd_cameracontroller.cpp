#include "cd_cameracontroller.h"

void GACameraController::CreateCamera(GA::Window3D *view)
{
    //Получаю указатель на камеру, находящуюся на сцене
    GA::Camera *camera = view->camera();
    //Выставляю необходимые настройки для камеры
    camera->setPosition(GA::Vector3D(0, 0, 100.0f));
    camera->setUpVector(GA::Vector3D(0, 1, 0));
    camera->setViewCenter(GA::Vector3D(0, 0, 0));

    //Создаю контроллер для камеры
    GA::OrbitCameraController *cameraController = new GA::OrbitCameraController(&GAScene::getRoot());
    //Добавляю камеру к контроллеру
    cameraController->setCamera(camera);
    //Выставляю необходимые настройки контроллеру
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(60.0f);
}

