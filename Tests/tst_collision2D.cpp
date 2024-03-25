#include <gtest/gtest.h>
#include "ga.h"
#include "cd_cube.h"
#include "cd_rectangle.h"
#include "cd_collisiondetector.h"

#include "cd.h"
#include "cd_contur.h"
#include "cd_detector.h"


using namespace testing;
using namespace GA;

TEST(GARectangle, Collision1)
{
    GACollisionDetector detector;

   ///Создаю информацию для описания параллелепипеда
    GA::Vector3D info1[3] = {GA::Size(1.0f,1.0f,1.0f), GA::Point(0.0f,0.0f,0.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info2[3] = {GA::Size(1.0f,1.0f,1.0f), GA::Point(3.0f,3.0f,3.0f), GA::Rotation(0.0f,0.0f,0.0f)};

    GARectangleMathRepresentation mathInfo1(info1);
    GARectangleMathRepresentation mathInfo2(info2);

    //Создаю параллелепипед
    GARectangle Rectangle1(mathInfo1);

    //Создаю параллелепипед
    GARectangle Rectangle2(mathInfo2);

    GA::IntersectionType rightAnswer = GA::NoIntersection;

    GA::IntersectionType myAnswer = detector.CalculateCollision2D(Rectangle1, Rectangle2);

    EXPECT_EQ(myAnswer, rightAnswer);
}
TEST(GARectangle, Collision2)
{
    GACollisionDetector detector;

    ///Создаю информацию для описания параллелепипеда
    GA::Vector3D info1[3] = {GA::Size(4.0f,5.0f,1.0f), GA::Point(1.0f,-5.0f,0.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info2[3] = {GA::Size(1.0f,1.0f,1.0f), GA::Point(3.0f,3.0f,3.0f), GA::Rotation(0.0f,0.0f,0.0f)};

    GARectangleMathRepresentation mathInfo1(info1);
    GARectangleMathRepresentation mathInfo2(info2);

    //Создаю параллелепипед
    GARectangle Rectangle1(mathInfo1);

    //Создаю параллелепипед
    GARectangle Rectangle2(mathInfo2);

    GA::IntersectionType rightAnswer = GA::NoIntersection;

    GA::IntersectionType myAnswer = detector.CalculateCollision2D(Rectangle1, Rectangle2);

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(CD, Collision3)
{
    CDDetector detector;

    CDContur c1{ {0,1},{1,0},{1,1}};
    CDContur c2{ {0,1},{1,1},{0,0}};

    CD::IntersectionType Answer = detector.ConturCollision2D(c1,c2);
    CD::IntersectionType rightAnswer = CD::Intersection;

    EXPECT_EQ(Answer, rightAnswer);
}

TEST(CD, Collision4)
{
    CDDetector detector;

    CDContur c1{ {1.0,1.5},{1.5,3.0},{2.5,2.0}};
    CDContur c2{ {0,1},{0.5,0.5},{0,0}};

    CD::IntersectionType Answer = detector.ConturCollision2D(c1,c2);
    CD::IntersectionType rightAnswer = CD::NoIntersection;

    EXPECT_EQ(Answer, rightAnswer);
}
