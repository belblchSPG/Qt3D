#include <gtest/gtest.h>
#include "../headers/cd_rectanglemathrepresentation.h"

using namespace testing;

//Группа тестов проверяет правильно ли функция возвращает координаты центра
TEST(RectangleCenterFunc, Center1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {4.0f,5.0f,6.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleCenterFunc, Center2)
{
    //Создаю информацию для описания параллелепипеда
     Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.466346f, 0.0f, 6.774356f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleCenterFunc, Center3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleCenterFunc, Center4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    Vector myAnswer = math.Center();

    Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает ширину объект
TEST(RectangleWidthFunc, Width1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = 45;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleWidthFunc, Width2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    //Size является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 123.6456745;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleWidthFunc, Width3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleWidthFunc, Width4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает высоту объект
TEST(RectangleHeightFunc, Height1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 23;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleHeightFunc, Height2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 34;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleHeightFunc, Height3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleHeightFunc, Height4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.000000f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

//Группа тестов проверяет правильно ли функция возвращает угол поворота объект
TEST(RectangleRotationFunc, Rot1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0f,5.0f,6.0f), Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -456.0;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(123.6456745f,34.0f,745.0f), Point(-1.466346f, 0.0f, 6.774356f), Rotation(442.54645f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 442.54645f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(45.54645f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot5)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(45.0f,23.0f,3.435253f), Point(4.0,5.0f,6.0f), Rotation(-35667.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = -35667.0;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot6)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.0f,34.0f,34.0f), Point(432.0f, -64.5634f, 1.0f), Rotation(34.0f,53.5664f,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(RectangleRotationFunc, Rot7)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-0.00000001f, 0.0000001f, 456.0f), Point(432.0f, -64.5634f, 0.0f), Rotation(42.0,53.5664,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
