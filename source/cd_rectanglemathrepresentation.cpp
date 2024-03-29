#include "../headers/cd_rectanglemathrepresentation.h"

using std::cos;
using std::sin;

GARectangleMathRepresentation::GARectangleMathRepresentation(Vector mathInfo[3])
{
    //Если один из принимаемых размеров параллелепипеда меньше или равен нулю, то все данные параллелепипеда равны -1
    if (mathInfo[0][0] <= 0 || mathInfo[0][1] <= 0)
    {
        m_dimensions = { -1, -1, -1 };
        m_center = { -1, -1, -1 };
        m_rotation = {-1,-1,-1};
        return;
    }
    m_dimensions = mathInfo[0];
    m_center = mathInfo[1];
    m_rotation = mathInfo[2];
}

Point GARectangleMathRepresentation::Center() const
{
    return m_center;
}

double GARectangleMathRepresentation::Width() const
{
    return m_dimensions[0];
}

double GARectangleMathRepresentation::Height() const
{
    return m_dimensions[1];
}

double GARectangleMathRepresentation::Rot() const
{
    return m_rotation[0];
}

std::vector<std::vector<double> > GARectangleMathRepresentation::CalculateRotationMatrix()
{
    //Создаю матрицу, которая будет хранить матрицу поворота
    std::vector<std::vector<double>> result(2, std::vector<double>(2,0.0));

    double angle = this->ConvertToRad(this->Rot());

    //Расситываю матрицу поворота как матрицу поворота XY

    result[0][0] = cos(angle);
    result[0][1] = -sin(angle);
    result[1][0] = sin(angle);
    result[1][1] = cos(angle);

    return result;
}

std::vector<std::vector<double> > GARectangleMathRepresentation::CalculateRotationVectors()
{
    //Рассчитываю матрицу поворота
    std::vector<std::vector<double>> rotationMatrix = this->CalculateRotationMatrix();

    //Создаю массив, хранящий единичные вектора
    std::vector<std::vector<double>> vectors(2, std::vector<double>(2, 0.0));

    //Единичный вектор для оси X
    vectors[0] =
        {
            rotationMatrix[0][0],
            rotationMatrix[0][1]
        };
    //Единичный вектор ддля оси Y
    vectors[1] =
        {
            rotationMatrix[1][0],
            rotationMatrix[1][1]
        };


    return vectors;
}

double GARectangleMathRepresentation::ConvertToRad(double degree)
{
    return (degree * (M_PI / 180));
}

double GARectangleMathRepresentation::DotProduct(const std::vector<double> &a, const std::vector<double> &b)
{
    if (a.size() != 2 || b.size() != 2)
    {
        return 0.0;
    }

    return a[0] * b[0] + a[1] * b[1];
}
