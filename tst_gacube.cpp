#include <gtest/gtest.h>
#include "ga.h"
#include "cd_cube.h"

using namespace testing;
using namespace GA;

TEST(GACube, ValidConstructor1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(1.0f,2.0f,3.0f), GA::Point(4.0f,5.0f,6.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    GA::Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    GA::Vector3D rightAnswer = {1.0f,2.0f,3.0f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, ValidConstructor2)
{
    //Создаю математическое описание параллелепипеда
    GA::Vector3D info[3] = {GA::Size(12.234235f, 0.24325345f, 345.534675458f),GA::Point(4.0f,5.0f,6.0f),GA::Rotation(123.0f,-324.0f,34.345f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    GA::Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    GA::Vector3D rightAnswer = {12.234235f, 0.24325345f, 345.534675458f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, ValidConstructor3)
{
    //Создаю математическое описание параллелепипеда
    GA::Vector3D info[3] = {GA::Size(0.0000234f,0.42434f,17.34634634f),GA::Point(4.0f,5.0f,6.0f),GA::Rotation(0.0f,0.0f,0.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube validCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    GA::Vector3D myAnswer(validCube.getMathRepresentation().Width(),
                      validCube.getMathRepresentation().Height(),
                      validCube.getMathRepresentation().Length());
    GA::Vector3D rightAnswer = {0.0000234f,0.42434f,17.34634634f};

    EXPECT_EQ(myAnswer, rightAnswer);
}

TEST(GACube, InvalidConstructor1)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(0.0f,2.0f,3.0f), GA::Point(-4.0f,5.0f,54.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    GA::Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    GA::Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    GA::Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    GA::Vector3D rightAnswer = {-1.0f,-1.0f,-1.0f};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor2)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(0.0f,2.0f,3.0f), GA::Point(-4.0f,5.0f,54.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    GA::Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                      invalidCube.getMathRepresentation().Height(),
                      invalidCube.getMathRepresentation().Length());
    GA::Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    GA::Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    GA::Vector3D rightAnswer = {-1.0f,-1.0f,-1.0f};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor3)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(1.0f,0.0f,3.0f), GA::Point(74.0f,16.0f,-6.0f), GA::Rotation(24.0f,346.0f,-678.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    GA::Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    GA::Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    GA::Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    GA::Vector3D rightAnswer = {-1.0f,-1.0f,-1.0f};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor4)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(0.000007f,-2.0f,432.0f), GA::Point(12.0f,5.0f,-6.0f), GA::Rotation(0.0f,0.0f,0.0f)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    GA::Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    GA::Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    GA::Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    GA::Vector3D rightAnswer = {-1.0f,-1.0f,-1.0f};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}

TEST(GACube, InvalidConstructor5)
{
    //Создаю информацию для описания параллелепипеда
    GA::Vector3D info[3] = {GA::Size(-1.534534f,234.0f,0.0f), GA::Point(353.0f,45.0f,1.0f), GA::Rotation(1230.0f,432.0f,765.56546)};
    GACubeMathRepresentation mathInfo(info);

    //Создаю параллелепипед
    GACube invalidCube(mathInfo);

    //При правильно введенных размерах параллелепипеда они сохраняются внутри его описания
    //При непраильно введенных все значения данных заменяются значениями -1, -1, -1
    GA::Vector3D myAnswerDimensions(invalidCube.getMathRepresentation().Width(),
                                invalidCube.getMathRepresentation().Height(),
                                invalidCube.getMathRepresentation().Length());
    GA::Point myAnswerPoint(invalidCube.getMathRepresentation().Center());
    GA::Rotation myAnswerRotation(invalidCube.getMathRepresentation().XRot(),
                              invalidCube.getMathRepresentation().YRot(),
                              invalidCube.getMathRepresentation().ZRot());

    GA::Vector3D rightAnswer = {-1.0f,-1.0f,-1.0f};

    EXPECT_EQ(myAnswerDimensions, rightAnswer);
    EXPECT_EQ(myAnswerPoint, rightAnswer);
    EXPECT_EQ(myAnswerRotation, rightAnswer);
}
