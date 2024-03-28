#ifndef __GACUBEMATHREORESENTATION_H__
#define __GACUBEMATHREORESENTATION_H__
#define _USE_MATH_DEFINES

#include "cd.h"

//Класс хранит параметры параллелепипеда, которое необходимо для его математического представления
class GACubeMathRepresentation
{
public:

    GACubeMathRepresentation() = default;

    //Конструктор принимает в себя координаты центра, размеры и углы поворота относительно каждый из осей параллелепипеда
    GACubeMathRepresentation(Vector3D mathInfo[3]);

    ~GACubeMathRepresentation() = default;

    //Конструктор копирования
    GACubeMathRepresentation(const GACubeMathRepresentation& math) = default;

    //Конструктор перемещения
    GACubeMathRepresentation(GACubeMathRepresentation&& math) = default;

    //Оператор присваивания с копированием
    GACubeMathRepresentation &operator=(const GACubeMathRepresentation& copy) = default;

    //Метод возвращает координаты центра параллелепипеда
    Point Center() const;

    //Метод возвращает ширину параллелепипеда
    double Width() const;

    //Метод возвращает высоту параллелепипеда
    double Height() const;

    //Метод возвращает длину параллелепипеда
    double Length() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси X
    double XRot() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси Y
    double YRot() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси Z
    double ZRot() const;

    //Метод возвращает вектор, содержащий единичные векторы, представляющие направление осей у параллелепипеда
    std::vector<std::vector<double>> CalculateRotationVectors();

    //Метод конвертирует градусы в радианы
    static double ConvertToRad(double degree);

    //Метод рассчитывает склярное произведение двух векторов
    static double DotProduct(const std::vector<double>& a, const std::vector<double>& b);

    //Метод рассчитывает векторное произведение двух векторов
    static std::vector<double> CrossProduct(const std::vector<double>& a, const std::vector<double>& b);

    //Метод рассчитывает матрицу поворота параллелепипеда относительно оси X
    std::vector<std::vector<double>> CalculateRotationMatrixX();

    //Метод рассчитывает матрицу поворота параллелепипеда относительно оси Y
    std::vector<std::vector<double>> CalculateRotationMatrixY();

    //Метод рассчитывает матрицу поворота параллелепипеда относительно оси Z
    std::vector<std::vector<double>> CalculateRotationMatrixZ();

    //Метод объединяет матрицы поворота относительно осей X,Y,Z и возвращает полную матрицу поворота для параллелепипеда
    std::vector<std::vector<double>> CalculateRotationMatrix();

    //Метод принимает две матрицы, перемножает их и возвращает получивщуюся матрицу
    std::vector<std::vector<double>> MultiplyMatrices(const std::vector<std::vector<double>>& matrix1,
                                                      const std::vector<std::vector<double>>& matrix2);

private:

    //Поле хранит в себе координаты центра параллелепипеда
    Point m_center = {0,0,0};

    //Поле хранит в себе размеры параллелепипеда
    Size m_dimensions = {1,1,1};

    //Поле хранит углы поворота параллелепипеда относительно каждый оси
    Rotation m_rotation = {0,0,0};
};
#endif // __MATHREPRESENTATION_H__
