#include "../headers/cd_cubemathrepresentation.h"

using std::cos;
using std::sin;

GACubeMathRepresentation::GACubeMathRepresentation(Vector3D mathInfo[3])
{
    //Если один из принимаемых размеров параллелепипеда меньше или равен нулю, то все данные параллелепипеда равны -1
    if(mathInfo[0].x() <= 0 || mathInfo[0].y() <= 0 || mathInfo[0].z() <= 0)
    {
        m_dimensions = {-1,-1,-1};
        m_center = {-1,-1,-1};
        m_rotation = {-1,-1,-1};
        return;
    }
    m_dimensions = mathInfo[0];
    m_center = mathInfo[1];
    m_rotation = mathInfo[2];
}

Point GACubeMathRepresentation::Center() const
{
    return m_center;
}

double GACubeMathRepresentation::Width() const
{
    return m_dimensions.x();
}

double GACubeMathRepresentation::Height() const
{
    return m_dimensions.y();
}

double GACubeMathRepresentation::Length() const
{
    return m_dimensions.z();
}

double GACubeMathRepresentation::XRot() const
{
    return m_rotation.x();
}

double GACubeMathRepresentation::YRot() const
{
    return m_rotation.y();
}

double GACubeMathRepresentation::ZRot() const
{
    return m_rotation.z();
}

double GACubeMathRepresentation::ConvertToRad(double degree)
{
    return (degree * (M_PI / 180));
}

std::vector<std::vector<double> > GACubeMathRepresentation::CalculateRotationMatrixX()
{
    //Создаю матрицу, в которой буду хранить результат
    std::vector<std::vector<double>> matrix(3, std::vector<double>(3, 0.0));

    //Перевожу угол поворота по оси X в радианы
    double angle = this->ConvertToRad(this->XRot());

    //Заполню матрицу поворота по оси X
    matrix[0][0] = 1.0;
    matrix[1][1] = cos(angle);
    matrix[1][2] = -(sin(angle));
    matrix[2][1] = sin(angle);
    matrix[2][2] = cos(angle);

    return matrix;
}

std::vector<std::vector<double> > GACubeMathRepresentation::CalculateRotationMatrixY()
{
    //Создаю матрицу, в которой буду хранить результат
    std::vector<std::vector<double>> matrix(3, std::vector<double>(3, 0.0));

    //Перевожу угол поворота по оси Y в радианы
    double angle = this->ConvertToRad(this->YRot());

    //Заполню матрицу поворота по оси Y
    matrix[0][0] = std::cos(angle);
    matrix[0][2] = std::sin(angle);
    matrix[1][1] = 1.0;
    matrix[2][0] = -(std::sin(angle));
    matrix[2][2] = std::cos(angle);

    return matrix;
}

std::vector<std::vector<double> > GACubeMathRepresentation::CalculateRotationMatrixZ()
{
    //Создаю матрицу, в которой буду хранить результат
    std::vector<std::vector<double>> matrix(3, std::vector<double>(3, 0.0));

    //Перевожу угол поворота по оси Z в радианы
    double angle = this->ConvertToRad(this->ZRot());

    //Заполню матрицу поворота по оси Z
    matrix[0][0] = std::cos(angle);
    matrix[0][1] = -(std::sin(angle));
    matrix[1][0] = std::sin(angle);
    matrix[1][1] = std::cos(angle);
    matrix[2][2] = 1.0;

    return matrix;
}

std::vector<std::vector<double> > GACubeMathRepresentation::CalculateRotationMatrix()
{
    //Рассчитываю матрицы поврота для каждой оси
    std::vector<std::vector<double>> matrixX = this->CalculateRotationMatrixX();
    std::vector<std::vector<double>> matrixY = this->CalculateRotationMatrixY();
    std::vector<std::vector<double>> matrixZ = this->CalculateRotationMatrixZ();

    //Создаю матрицу, которая будет хранить матрицу поворота
    std::vector<std::vector<double>> result(3, std::vector<double>(3,0.0));

    //Расситываю матрицу поворота как матрицу поворота XYZ
    result = MultiplyMatrices(MultiplyMatrices(matrixX, matrixY),matrixZ);

    return result;
}

std::vector<std::vector<double> > GACubeMathRepresentation::CalculateRotationVectors()
{
    //Рассчитываю матрицу поворота
    std::vector<std::vector<double>> rotationMatrix = this->CalculateRotationMatrix();

    //Создаю массив, хранящий единичные вектора
    std::vector<std::vector<double>> vectors(3, std::vector<double>(3, 0.0));

    //Единичный вектор для оси X
    vectors[0] =
        {
            rotationMatrix[0][0],
            rotationMatrix[1][0],
            rotationMatrix[2][0]
        };
    //Единичный вектор ддля оси Y
    vectors[1] =
        {
            rotationMatrix[0][1],
            rotationMatrix[1][1],
            rotationMatrix[2][1]
        };
    //Единичный вектор для оси Z
    vectors[2] =
        {
            rotationMatrix[0][2],
            rotationMatrix[1][2],
            rotationMatrix[2][2]
        };

    return vectors;
}

std::vector<std::vector<double> > GACubeMathRepresentation::MultiplyMatrices(const std::vector<std::vector<double> > &matrix1, const std::vector<std::vector<double> > &matrix2)
{
    //Рассчитываю размеры матрицы
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t cols2 = matrix2[0].size();

    //Создаю матрицу хранящую результат перемножения
    std::vector<std::vector<double>> result(rows1, std::vector<double>(cols2, 0.0));

    //Заполняю матрицу
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

double GACubeMathRepresentation::DotProduct(const std::vector<double>& a, const std::vector<double>& b)
{
    if (a.size() != 3 || b.size() != 3)
    {
        return 0.0;
    }

    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

std::vector<double> GACubeMathRepresentation::CrossProduct(const std::vector<double>& a, const std::vector<double>& b)
{
    if (a.size() != 3 || b.size() != 3)
    {
        return std::vector<double>(3, 0.0);
    }

    std::vector<double> result(3);
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];

    return result;
}
