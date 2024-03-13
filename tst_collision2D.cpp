#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "GA.h"
#include "gacube.h"
#include "garectangle.h"
#include "gacollisiondetector.h"

using namespace testing;
using namespace GA;

TEST(GARectangle, Collision1)
{
    GACollisionDetector detector;

   ///Создаю информацию для описания параллелепипеда
    GA::Vector3D info1[3] = {GA::Size(1,1,1), GA::Point(0,0,0), GA::Rotation(0,0,0)};
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info2[3] = {GA::Size(1,1,1), GA::Point(3,3,3), GA::Rotation(0,0,0)};

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
