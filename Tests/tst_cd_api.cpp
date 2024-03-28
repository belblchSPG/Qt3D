#include "../headers/cd_api.h"

#include <gtest/gtest.h>

using namespace testing;

//Тест проверяет коллизию между двумя контурами
TEST(CDLibraryCheckIntersections, TwoConturs)
{
    CDDetector detector;

    CDContur* c1 = new CDContur({1.0,1.5},{1.5,3.0},{2.5,2.0});
    CDContur* c2 = new CDContur({0,1},{0.5,0.5},{0,0});

    AddGeom(detector, c1);
    AddGeom(detector, c2);

    std::vector<CDIntersectingRelation> result = {{NoIntersection, c1, c2}};


    EXPECT_EQ(CheckIntersections(detector) , result );
}

//Тест проверяет коллизию между тремя контурами
TEST(CDLibraryCheckIntersections, ThreeConturs)
{
    CDDetector detector;

    CDContur* c1 = new CDContur({1.0,1.5},{1.5,3.0},{2.5,2.0});
    CDContur* c2 = new CDContur({0,1},{0.5,0.5},{0,0});
    CDContur* c3 = new CDContur({5,5},{7,7},{4,12});

    AddGeom(detector, c1);
    AddGeom(detector, c2);
    AddGeom(detector, c3);

    std::vector<CDIntersectingRelation> result = {{NoIntersection, c1, c2}, {NoIntersection,c1,c3},{NoIntersection,c2,c3}};
    std::sort(result.begin(), result.end());

    EXPECT_EQ(CheckIntersections(detector) , result);
}

