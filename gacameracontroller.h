#ifndef __GACAMERACONTROLLER_H
#define __GACAMERACONTROLLER_H

#include "GA.h"
#include "gascene.h"

using namespace GA;

namespace GA{

//Класс, который отвечает за создание камеры, а также за ее контроль
//Все действия, связанные с управлением камерой будут находиться здесь
class GACameraController
{

public:

    GACameraController() = default;

    ~GACameraController() = default;

    //Конструктор копирования
    GACameraController(const GACameraController& camera) = delete;

    //Оператор присваивания с копированием
    GACameraController& operator=(const GACameraController& copy) = delete;

    //Оператор присваивания с премещением
    GACameraController& operator=(GACameraController&& moved) = delete;

    //Метод добавляет кастомный контроллер для камеры и задаетт ей необходимые настройки
    void CreateCamera(GA::Window3D*);
};
}
#endif // __GACAMERACONTROLLER_H
