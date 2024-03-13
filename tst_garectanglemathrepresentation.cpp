#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "GA.h"
#include "garectanglemathrepresentation.h"

using namespace testing;
using namespace GA;

TEST(GARectangleMathRepresentation, Center1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45,23,3.435253), GA::Point(4,5,6), GA::Rotation(-456,56.653464,0.4352523564)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {4.0,5.0,6.0};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745,34,745), GA::Point(-1.466346, 0, 6.774356), GA::Rotation(442,50,-70)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1.466346, 0, 6.774356};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1,34,34), GA::Point(432, -64.5634, 1), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1, -1, -1};

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Center4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001, 0.0000001, 456), GA::Point(432, -64.5634, 0), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    GA::Vector myAnswer = math.Center();

    GA::Vector3D rightAnswer = {-1, -1, -1};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Width1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45,23,3.435253), GA::Point(4,5,6), GA::Rotation(-456,56.653464,0.4352523564)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = 45;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Width2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745,34,745), GA::Point(-1.466346, 0, 6.774356), GA::Rotation(442,50,-70)};
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
    GA::Vector3D info[3] = {GA::Size(-1,34,34), GA::Point(432, -64.5634, 1), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Width4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001, 0.0000001, 456), GA::Point(432, -64.5634, 0), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Width();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Height1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45,23,3.435253), GA::Point(4,5,6), GA::Rotation(-456,56.653464,0.4352523564)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 23;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745,34,745), GA::Point(-1.466346, 0, 6.774356), GA::Rotation(442,50,-70)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = 34;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1,34,34), GA::Point(432, -64.5634, 1), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Height4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001, 0.0000001, 456), GA::Point(432, -64.5634, 0), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Height();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GARectangleMathRepresentation, Rot1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45,23,3.435253), GA::Point(4,5,6), GA::Rotation(-456,56.653464,0.4352523564)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -456.0;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(123.6456745,34,745), GA::Point(-1.466346, 0, 6.774356), GA::Rotation(442.54645,50,-70)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //GA::Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = 442.54645;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1,34,34), GA::Point(432, -64.5634, 1), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001, 0.0000001, 456), GA::Point(432, -64.5634, 0), GA::Rotation(45.54645,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot5)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(45,23,3.435253), GA::Point(4,5,6), GA::Rotation(-35667,56.653464,0.4352523564)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();
    //GA::Rotation является QVector3D, который хранит в себе float.
    //При изменении типа rightAnswer на double тест не проходит
    float rightAnswer = -35667;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot6)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1,34,34), GA::Point(432, -64.5634, 1), GA::Rotation(34,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangleMathRepresentation, Rot7)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-0.00000001, 0.0000001, 456), GA::Point(432, -64.5634, 0), GA::Rotation(42,53.5664,456.743)};
    GARectangleMathRepresentation math(info);

    double myAnswer = math.Rot();

    double rightAnswer = -1;

    EXPECT_EQ(myAnswer, rightAnswer);
}
