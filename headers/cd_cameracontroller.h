#ifndef __GACAMERACONTROLLER_H__
#define __GACAMERACONTROLLER_H__

#include "cd.h"
#include "../headers/cd_scene.h"

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
    void CreateCamera(Window3D*);
};
#endif // __GACAMERACONTROLLER_H__
