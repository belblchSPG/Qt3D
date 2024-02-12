#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "GA.h"


//Класс, который отвечает за создание камеры, а также за ее контроль
//Все действия, связанные с управлением камерой будут находиться здесь
class CameraController
{
public:
    CameraController();

    void CreateCamera(Qt3DExtras::Qt3DWindow*, Qt3DCore::QEntity*);
};

#endif // CAMERACONTROLLER_H
