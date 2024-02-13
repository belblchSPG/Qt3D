#ifndef __GACAMERACONTROLLER_H
#define __GACAMERACONTROLLER_H

#include "GA.h"

using namespace GA;

namespace GA{


//Класс, который отвечает за создание камеры, а также за ее контроль
//Все действия, связанные с управлением камерой будут находиться здесь
class GACameraController
{
public:
    GACameraController();

    void CreateCamera(GA::Window3D*, GA::Entity*);
};
}
#endif // GACAMERACONTROLLER_H
