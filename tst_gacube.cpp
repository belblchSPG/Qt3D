#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "GA.h"
#include "gacube.h"

using namespace testing;
using namespace GA;

TEST(GACube, ValidConstructor1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(1,2,3), Point(4,5,6), Rotation(0,0,0)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    Vector3D rightAnswer = {1.0,2.0,3.0};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, ValidConstructor2)
{
    //Создаю математическое описание параллелепипеда
    Vector3D info[3] = {Size(12.234235, 0.24325345, 345.534675458),Point(4,5,6),Rotation(123,-324,34.345)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    Vector3D rightAnswer = {12.234235, 0.24325345, 345.534675458};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, ValidConstructor3)
{
    //Создаю математическое описание параллелепипеда
    Vector3D info[3] = {Size(0.0000234,0.42434,17.34634634),Point(4,5,6),Rotation(0,0,0)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    Vector3D rightAnswer = {0.0000234,0.42434,17.34634634};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, InvalidConstructor1)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(0,2,3), Point(-4,5,54), Rotation(0,0,0)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    Vector3D rightAnswer = {-1.0,-1.0,-1.0};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor2)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(0,2,3), Point(-4,5,54), Rotation(0,0,0)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                      invalidCube.getMathRepresentation().Height(),
                      invalidCube.getMathRepresentation().Length());
    Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    Vector3D rightAnswer = {-1.0,-1.0,-1.0};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor3)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(1,0,3), Point(74,16,-6), Rotation(24,346,-678)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    Vector3D rightAnswer = {-1.0,-1.0,-1.0};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor4)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(0.000007,-2,432), Point(12,5,-6), Rotation(0,0,0)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    Vector3D rightAnswer = {-1.0,-1.0,-1.0};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor5)
{
    //Создаю информацию для описания параллелепипеда
    Vector3D info[3] = {Size(-1.534534,234,0), Point(353,45,1), Rotation(1230,432,765.56546)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    Vector3D rightAnswer = {-1.0,-1.0,-1.0};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}
