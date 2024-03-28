#include <gtest/gtest.h>
#include "../headers/cd_cubemathrepresentation.h"

using namespace testing;

//calculateRotationMatrixX
//calculateRotationMatrixX
//calculateRotationMatrixX
//calculateRotationMatrix
//multiplyMatrices
//calculateRotationVectors

//Группа тестов проверяет правильно ли функция возвращает координаты центра
TEST(GACubeCenterFunc, Center1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {4.0f,5.0f,6.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeCenterFunc, Center2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.466346f, 0.0f, 6.774356f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeCenterFunc, Center3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeCenterFunc, Center4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает ширину объект
TEST(GACubeWidthFunc, Width1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);


    double myAnswer = math.Width();

    double rightAnswer = 45.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeWidthFunc, Width2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Width();

    //Size является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 123.6456745f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeWidthFunc, Width3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeWidthFunc, Width4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает высоту объект
TEST(GACubeHeightFunc, Height1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 23.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeHeightFunc, Height2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 34.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeHeightFunc, Height3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeHeightFunc, Height4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает длину объект
TEST(GACubeLengthFunc, Length1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Length();

    //Size является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 3.435253f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeLengthFunc, Length2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Length();

    double rightAnswer = 745.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeLengthFunc, Length3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Length();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GACubeLengthFunc, Length4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.Length();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает поворот объект по оси X
TEST(MathZRotXunc, XRot1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.XRot();

    double rightAnswer = -456.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotXunc, XRot2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.XRot();
    //Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 442.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotXunc, XRot3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.XRot();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotXunc, XRot4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.XRot();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает поворот объект по оси Y
TEST(MathYRotFunc, YRot1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.YRot();
    //Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 56.653464f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathYRotFunc, YRot2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.YRot();

    double rightAnswer = 50.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathYRotFunc, YRot3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.YRot();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathYRotFunc, YRot4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.YRot();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает поворот объект по оси Z
TEST(MathZRotFunc, ZRot1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.ZRot();

    //Rotationявляется QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 0.4352523564f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotFunc, ZRot2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.ZRot();

    double rightAnswer = -70.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotFunc, ZRot3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.ZRot();

    double rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(MathZRotFunc, ZRot4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GACubeMathRepresentation math(info);

    double myAnswer = math.ZRot();

    float rightAnswer = -1.0f;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция конвертирует угол в радианы
TEST(MathConvertToRadFunc, convertToRad1)
{
    double angleInDegrees = 0;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = 0;

    EXPECT_EQ(angleInRad, rightAnswer);
}
TEST(MathConvertToRadFunc, convertToRad2)
{
    double angleInDegrees = -56;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = -0.97738438111682457;

    EXPECT_EQ(angleInRad, rightAnswer);
}
TEST(MathConvertToRadFunc, convertToRad3)
{
    double angleInDegrees = 764.5457;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = 13.343839746964811;

    EXPECT_EQ(angleInRad, rightAnswer);
}
TEST(MathConvertToRadFunc, convertToRad4)
{
    double angleInDegrees = 0.5464;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = 0.0095364790328970172;

    EXPECT_EQ(angleInRad, rightAnswer);
}
TEST(MathConvertToRadFunc, convertToRad5)
{
    double angleInDegrees = 124534262;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = 2173532.9034412587;

    EXPECT_EQ(angleInRad, rightAnswer);
}
TEST(MathConvertToRadFunc, convertToRad6)
{
    double angleInDegrees = -85684733;

    double angleInRad = GACubeMathRepresentation::ConvertToRad(angleInDegrees);

    double rightAnswer = -1495480.7095422384;

    EXPECT_EQ(angleInRad, rightAnswer);
}

//Группа тестов проверяет правильно ли функция расчитывает векторное произведение двух векторов
TEST(MathCrossProductFunc, TwoVectors1)
{
    std::vector<double> vec1 = {23.563, 25.78679, 645.567000867};
    std::vector<double> vec2 = {0,0,0};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0, 0, 0};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors2)
{
    std::vector<double> vec1 = {0,0,0};
    std::vector<double> vec2 = {12423423,-24.4646,1763364};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0,0,0};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors3)
{
    std::vector<double> vec1 = {1,2,3};
    std::vector<double> vec2 = {10,20,30};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0, 0, 0};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors4)
{
    std::vector<double> vec1 = {-3,-8,-0.2};
    std::vector<double> vec2 = {-15,-40, -1};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0, 0, 0};

    EXPECT_EQ(Cross, rightAnswer);
};
TEST(MathCrossProductFunc, TwoVectors5)
{
    std::vector<double> vec1 = {1,0,0};
    std::vector<double> vec2 = {0,1,0};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0,0,1};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors6)
{
    std::vector<double> vec1 = {0,12.25,0};
    std::vector<double> vec2 = {0,0,12.7456};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {156.1336, 0, 0};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors7)
{
    std::vector<double> vec1 = {12,28,-6};
    std::vector<double> vec2 = {11,65,0};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {390, -66, 472};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors8)
{
    std::vector<double> vec1 = {11,65,0};
    std::vector<double> vec2 = {12,28,-6};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {-390, 66, -472};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors9)
{
    std::vector<double> vec1 = {324.56456,455.3241,0.542353};
    std::vector<double> vec2 = {-1.546456,53464,-57.564};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {-55206.6372844, 18682.395606789029, 17353223.774526387};

    EXPECT_EQ(Cross, rightAnswer);
}
TEST(MathCrossProductFunc, TwoVectors10)
{
    std::vector<double> vec1 = {0.677658458,-0.5324523632,-0.00063456};
    std::vector<double> vec2 = {-2.45645745,1.45754685,-0.65865};

    std::vector<double> Cross = GACubeMathRepresentation::CrossProduct(vec1,vec2);

    std::vector<double> rightAnswer = {0.35162464995081599,  0.44789851300117195, -0.32022762351898837};

    EXPECT_EQ(Cross, rightAnswer);
}

//Группа тестов проверяет правильно ли функция просчитывает скалярное произведение двух векторов
TEST(MathDotProductFunc, DotProduct1)
{
    std::vector<double> vec1 = {23.563, 25.78679, 645.567000867};
    std::vector<double> vec2 = {0,0,0};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 0;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct2)
{
    std::vector<double> vec1 = {0,0,0};
    std::vector<double> vec2 = {12423423,-24.4646,1763364};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 0;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct3)
{
    std::vector<double> vec1 = {1,2,3};
    std::vector<double> vec2 = {10,20,30};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 140;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct4)
{
    std::vector<double> vec1 = {-3,-8,-0.2};
    std::vector<double> vec2 = {-15,-40, -1};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 365.2;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct5)
{
    std::vector<double> vec1 = {1,0,0};
    std::vector<double> vec2 = {0,1,0};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 0;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct6)
{
    std::vector<double> vec1 = {0,12.25,0};
    std::vector<double> vec2 = {0,12.7456,0};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 156.1336;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct7)
{
    std::vector<double> vec1 = {12,28,-6};
    std::vector<double> vec2 = {11,65,0};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 1952;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct8)
{
    std::vector<double> vec1 = {11,65,0};
    std::vector<double> vec2 = {12,28,-6};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 1952;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct9)
{
    std::vector<double> vec1 = {324.56456,455.3241,0.542353};
    std::vector<double> vec2 = {-1.546456,53464,-57.564};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = 24342914.537580710;

    EXPECT_EQ(Dot, rightAnswer);
}
TEST(MathDotProductFunc, DotProduct10)
{
    std::vector<double> vec1 = {0.677658458,-0.5324523632,-0.00063456};
    std::vector<double> vec2 = {-2.45645745,1.45754685,-0.65865};

    double Dot = GACubeMathRepresentation::DotProduct(vec1,vec2);

    double rightAnswer = -2.440295479522828;

    EXPECT_EQ(Dot, rightAnswer);
}
