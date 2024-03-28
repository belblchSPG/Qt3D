#include "../headers/cd_cameracontroller.h"

void GACameraController::CreateCamera(Window3D *view)
{
    //Получаю указатель на камеру, находящуюся на сцене
    Camera *camera = view->camera();
    //Выставляю необходимые настройки для камеры
    camera->setPosition(Vector3D(0, 0, 100.0f));
    camera->setUpVector(Vector3D(0, 1, 0));
    camera->setViewCenter(Vector3D(0, 0, 0));

    //Создаю контроллер для камеры
    OrbitCameraController *cameraController = new OrbitCameraController(&GAScene::GetRoot());
    //Добавляю камеру к контроллеру
    cameraController->setCamera(camera);
    //Выставляю необходимые настройки контроллеру
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(60.0f);
}

