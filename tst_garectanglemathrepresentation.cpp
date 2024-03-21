#include <gtest/gtest.h>
#include "ga.h"
#include "cd_rectanglemathrepresentation.h"

using namespace testing;
using namespace GA;

TEST(GARectangleMathRepresentation, Center1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45.0f,23.0f,3.435253f), GA::Point(4.0f,5.0f,6.0f), GA::Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {4.0f,5.0f,6.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745f,34.0f,745.0f), GA::Point(-1.466346f, 0.0f, 6.774356f), GA::Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1.466346f, 0.0f, 6.774356f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.0f,34.0f,34.0f), GA::Point(432.0f, -64.5634f, 1.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001f, 0.0000001f, 456.0f), GA::Point(432.0f, -64.5634f, 0.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1.0f, -1.0f, -1.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Width1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45.0f,23.0f,3.435253f), GA::Point(4.0f,5.0f,6.0f), GA::Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = 45;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Width2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745f,34.0f,745.0f), GA::Point(-1.466346f, 0.0f, 6.774356f), GA::Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    //GA::Size является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 123.6456745;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Width3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.0f,34.0f,34.0f), GA::Point(432.0f, -64.5634f, 1.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Width4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001f, 0.0000001f, 456.0f), GA::Point(432.0f, -64.5634f, 0.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Height1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45.0f,23.0f,3.435253f), GA::Point(4.0f,5.0f,6.0f), GA::Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 23;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745f,34.0f,745.0f), GA::Point(-1.466346f, 0.0f, 6.774356f), GA::Rotation(442.0f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 34;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.0f,34.0f,34.0f), GA::Point(432.0f, -64.5634f, 1.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001f, 0.000000f, 456.0f), GA::Point(432.0f, -64.5634f, 0.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Rot1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45.0f,23.0f,3.435253f), GA::Point(4.0f,5.0f,6.0f), GA::Rotation(-456.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -456.0;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745f,34.0f,745.0f), GA::Point(-1.466346f, 0.0f, 6.774356f), GA::Rotation(442.54645f,50.0f,-70.0f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //GA::Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 442.54645f;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.0f,34.0f,34.0f), GA::Point(432.0f, -64.5634f, 1.0f), GA::Rotation(42.0f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001f, 0.0000001f, 456.0f), GA::Point(432.0f, -64.5634f, 0.0f), GA::Rotation(45.54645f,53.5664f,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot5)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45.0f,23.0f,3.435253f), GA::Point(4.0,5.0f,6.0f), GA::Rotation(-35667.0f,56.653464f,0.4352523564f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //GA::Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = -35667.0;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot6)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.0f,34.0f,34.0f), GA::Point(432.0f, -64.5634f, 1.0f), GA::Rotation(34.0f,53.5664f,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot7)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001f, 0.0000001f, 456.0f), GA::Point(432.0f, -64.5634f, 0.0f), GA::Rotation(42.0,53.5664,456.743f)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
