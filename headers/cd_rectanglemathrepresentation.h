#ifndef __GA_GARECTANGLEMATHREPRESENATION_H__
#define __GA_GARECTANGLEMATHREPRESENATION_H__

#include "cd.h"

class GARectangleMathRepresentation
{

public:

    GARectangleMathRepresentation() = delete;

    GARectangleMathRepresentation(Vector mathInfo[3]);

    ~GARectangleMathRepresentation() = default;

    GARectangleMathRepresentation(const GARectangleMathRepresentation& math) = default;

    //Конструктор перемещения
    GARectangleMathRepresentation(GARectangleMathRepresentation&& math) = delete;

    //Оператор присваивания с копированием
    GARectangleMathRepresentation &operator=(const GARectangleMathRepresentation& copy) = default;

    Point Center() const;

    double Width() const;

    double Height() const;

    double Rot() const;

    //Метод рассчитывает матрицу поворота параллелепипеда относительно оси X
    std::vector<std::vector<double>> CalculateRotationMatrixX();

    //Метод рассчитывает матрицу поворота параллелепипеда относительно оси Y
    std::vector<std::vector<double>> CalculateRotationMatrixY();

    //Метод объединяет матрицы поворота относительно осей X,Y,Z и возвращает полную матрицу поворота для параллелепипеда
    std::vector<std::vector<double>> CalculateRotationMatrix();

    //Метод принимает две матрицы, перемножает их и возвращает получивщуюся матрицу
    std::vector<std::vector<double>> MultiplyMatrices(const std::vector<std::vector<double>>& matrix1,
                                                      const std::vector<std::vector<double>>& matrix2);

    //Метод возвращает вектор, содержащий единичные векторы, представляющие направление осей у параллелепипеда
    std::vector<std::vector<double>> CalculateRotationVectors();

    static double ConvertToRad(double degree);

    static double DotProduct(const std::vector<double>& a, const std::vector<double>& b);

private:

    //Поле хранит в себе координаты центра параллелелограммма
    Point m_center = { 0, 0, 0};

    //Поле хранит в себе размеры параллелелограммма
    Size m_dimensions = { 0, 0, 0};

    //Поле хранит углы поворота параллелелограммма относительно каждой оси
    Rotation m_rotation = {0,0,0};
};

#endif // __GA_GARECTANGLEMATHREPRESENATION_H__
