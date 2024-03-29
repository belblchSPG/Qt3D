#include "../headers/cd_collisiondetector.h"

std::vector<std::tuple<GACube*,GACube*,CDIntersectionResult>> GACollisionDetector::CollisionDetection3D(const std::vector<GACube*>& objects)
{
   //Создаю список, который будет хранить информацию о коллизях
   std::vector<std::tuple<GACube*,GACube*,CDIntersectionResult>> collisions;

   //Если на сцене один объект, то проверки не происходят
   if(objects.size() == 1)
   {
       collisions.push_back(std::tuple<GACube*,GACube*,CDIntersectionResult>(objects[0],nullptr,NoIntersection));
   }

   else
   {    //Каждый между объект проверяется на коллизии с другим единожды
       for (size_t i = 0; i < objects.size(); ++i)
       {
           for (size_t j = i + 1; j < objects.size(); ++j)
           {
               GACube* c1 = objects[i];
               GACube* c2 = objects[j];

               //Информация после каждой проверки добавляется в список
               collisions.push_back(std::tuple<GACube*,GACube*,CDIntersectionResult>(c1,c2,CalculateCollision3D(*c1,*c2)));
           }
       }
   }

   return collisions;
}

CDIntersectionResult GACollisionDetector::CalculateCollision3D(const GACube& cube1, const GACube& cube2)
{
    GACubeMathRepresentation Cube1MathRepresentation = cube1.GetMathRepresentation();
    GACubeMathRepresentation Cube2MathRepresentation = cube2.GetMathRepresentation();

    //Получаю координаты центра у параллелепипедов
    Point Pa = Cube1MathRepresentation.Center();
    Point Pb = Cube2MathRepresentation.Center();

    //Получаю половины ширины, высоты и длины
    double Ha = Cube1MathRepresentation.Height() / 2;
    double Wa = Cube1MathRepresentation.Width() / 2;
    double Da = Cube1MathRepresentation.Length() / 2;
    double Hb = Cube2MathRepresentation.Height() / 2;
    double Wb = Cube2MathRepresentation.Width() / 2;
    double Db = Cube2MathRepresentation.Length() / 2;

    //Получаю матрицы поворота параллелепипедов
    std::vector<std::vector<double>> rotationVectorsA = Cube1MathRepresentation.CalculateRotationVectors();
    std::vector<std::vector<double>> rotationVectorsB = Cube2MathRepresentation.CalculateRotationVectors();

    //Получаю единичные векторы осей
    std::vector<double> Ax = { rotationVectorsA[0][0], rotationVectorsA[0][1], rotationVectorsA[0][2] };
    std::vector<double> Ay = { rotationVectorsA[1][0], rotationVectorsA[1][1], rotationVectorsA[1][2] };
    std::vector<double> Az = { rotationVectorsA[2][0], rotationVectorsA[2][1], rotationVectorsA[2][2] };

    std::vector<double> Bx = { rotationVectorsB[0][0], rotationVectorsB[0][1], rotationVectorsB[0][2] };
    std::vector<double> By = { rotationVectorsB[1][0], rotationVectorsB[1][1], rotationVectorsB[1][2] };
    std::vector<double> Bz = { rotationVectorsB[2][0], rotationVectorsB[2][1], rotationVectorsB[2][2] };

    //Вычисляю вектор разности центров
    std::vector<double> T = {abs(Pb[0] - Pa[0]), abs(Pb[1] - Pa[1]), abs(Pb[2] - Pa[2])};

    //Переменные необходимые для расчетов и удобной отладки
    double length;
    double length1;
    double length2;
    double length3;
    double length4;
    double sum;
    double Rxx = GACubeMathRepresentation::DotProduct(Ax, Bx);
    double Rxy = GACubeMathRepresentation::DotProduct(Ax, By);
    double Rxz = GACubeMathRepresentation::DotProduct(Ax, Bz);
    double Ryx = GACubeMathRepresentation::DotProduct(Ay, Bx);
    double Ryy = GACubeMathRepresentation::DotProduct(Ay, By);
    double Ryz = GACubeMathRepresentation::DotProduct(Ay, Bz);
    double Rzx = GACubeMathRepresentation::DotProduct(Az, Bx);
    double Rzy = GACubeMathRepresentation::DotProduct(Az, By);
    double Rzz = GACubeMathRepresentation::DotProduct(Az, Bz);

    // case 1
    // L = Ax
    //  |T * Ax | > Wa + |WbRxx| + |HbRxy| + |DbRxz|
    //  length > Wa + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, Ax));

    length1 = std::abs(Wb * Rxx);
    length2 = std::abs(Hb * Rxy);
    length3 = std::abs(Db * Rxz);

    sum = (Wa + length1 + length2 + length3);

    bool case1 = length > sum;

    if (case1) return NoIntersection;

    // case 2 done
    // L = Ay
    //  |T * Ay | > Ha + |WbRyx| + |HbRyy| + |DbRyz|
    //  length > Ha + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, Ay));

    length1 = std::abs(Wb * Ryx);
    length2 = std::abs(Hb * Ryy);
    length3 = std::abs(Db * Ryz);

    sum = Ha + length1 + length2 + length3;

    bool case2 = length > sum;

    if (case2) return NoIntersection;

    // case 3 done
    // L = Az
    //  |T * Az | > Da + |WbRzx| + |HbRzy| + |DbRzz|
    //  length > Da + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, Az));

    length1 = std::abs(Wb * Rzx);
    length2 = std::abs(Hb * Rzy);
    length3 = std::abs(Db * Rzz);

    sum = (Da + length1 + length2 + length3);

    bool case3 = length > sum;

    if (case3) return NoIntersection;

    // case 4 done
    // L = Bx
    //  |T * Bx | > Wb + |WaRxx| + |HaRyx| + |DaRzx|
    //  length > Wb + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, Bx));

    length1 = std::abs(Wa * Rxx);
    length2 = std::abs(Ha * Ryx);
    length3 = std::abs(Da * Rzx);

    sum = (Wb + length1 + length2 + length3);

    bool case4 = length > sum;

    if (case4) return NoIntersection;

    // case 5 done
    // L = By
    //  |T * By | > Hb + |WaRxy| + |HaRyy| + |DaRzy|
    //  length > Hb + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, By));

    length1 = std::abs(Wa * Rxy);
    length2 = std::abs(Ha * Ryy);
    length3 = std::abs(Da * Rzy);

    sum = (Hb + length1 + length2 + length3);

    bool case5 = length > sum;

    if (case5) return NoIntersection;

    // case 6 done
    // L = Bz
    //  |T * Bz | > Db + |WaRxz| + |HaRyz| + |DaRzz|
    //  length > Db + length1 + length2 + length3

    length = abs(GACubeMathRepresentation::DotProduct(T, Bz));

    length1 = std::abs(Wa * Rxz);
    length2 = std::abs(Ha * Ryz);
    length3 = std::abs(Da * Rzz);

    sum = (Db + length1 + length2 + length3);

    bool case6 = length > sum;

    if (case6) return NoIntersection;

    // case 7 done
    //  |T * (Ax x Bx) | > |HaRzx| + |DaRyx| + |HbRxz| + |DbRxy|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ax, Bx)));

    length1 = std::abs(Ha * Rzx);
    length2 = std::abs(Da * Ryx);
    length3 = std::abs(Hb * Rxz);
    length4 = std::abs(Db * Rxy);

    sum = length1 + length2 + length3 + length4;

    bool case7 = length > sum;

    if (case7) return NoIntersection;

    // case 8 done
    //  |T * (Ax x By) | > |HaRzy| + |DaRyy| + |WbRxz| + |DbRxx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ax, By)));

    length1 = std::abs(Ha * Rzy);
    length2 = std::abs(Da * Ryy);
    length3 = std::abs(Wb * Rxz);
    length4 = std::abs(Db * Rxx);

    sum = (length1 + length2 + length3 + length4);

    bool case8 = length > sum;

    if (case8) return NoIntersection;

    // case 9 done
    //  |T * (Ax x Bz) | > |HaRzz| + |DaRyz| + |WbRxy| + |HbRxx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ax, Bz)));

    length1 = std::abs(Ha * Rzz);
    length2 = std::abs(Da * Ryz);
    length3 = std::abs(Wb * Rxy);
    length4 = std::abs(Hb * Rxx);

    sum = (length1 + length2 + length3 + length4);

    bool case9 = length > sum;

    if (case9) return NoIntersection;

    // case 10 done
    //  |T * (Ay x Bx) | > |WaRzx| + |DaRxx| + |HbRyz| + |DbRyy|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ay, Bx)));

    length1 = std::abs(Wa * Rzx);
    length2 = std::abs(Da * Rxx);
    length3 = std::abs(Hb * Ryz);
    length4 = std::abs(Db * Ryy);

    sum = (length1 + length2 + length3 + length4);

    bool case10 = length > sum;

    if (case10) return NoIntersection;

    // case 11 done
    //  |T * (Ay x By) | > |WaRzy| + |DaRxy| + |WbRyz| + |DbRyx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ay, By)));

    length1 = std::abs(Wa * Rzy);
    length2 = std::abs(Da * Rxy);
    length3 = std::abs(Wb * Ryz);
    length4 = std::abs(Db * Ryx);

    sum = (length1 + length2 + length3 + length4);

    bool case11 = length > sum;

    if (case11) return NoIntersection;

    // case 12 done
    //  |T * (Ay x Bz) | > |WaRzz| + |DaRxz| + |WbRyy| + |HbRyx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Ay, Bz)));

    length1 = std::abs(Wa * Rzz);
    length2 = std::abs(Da * Rxz);
    length3 = std::abs(Wb * Ryy);
    length4 = std::abs(Hb * Ryx);

    sum = (length1 + length2 + length3 + length4);

    bool case12 = length > sum;

    if (case12) return NoIntersection;

    // case 13 done
    //  |T * (Az x Bx) | > |WaRyx| + |HaRxx| + |HbRzz| + |DbRzy|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Az, Bx)));

    length1 = std::abs(Wa * Ryx);
    length2 = std::abs(Ha * Rxx);
    length3 = std::abs(Hb * Rzz);
    length4 = std::abs(Db * Rzy);

    sum = (length1 + length2 + length3 + length4);

    bool case13 = length > sum;

    if (case13) return NoIntersection;

    // case 14 done
    //  |T * (Az x By) | > |WaRyy| + |HaRxy| + |WbRzz| + |DbRzx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Az, By)));

    length1 = std::abs(Wa * Ryy);
    length2 = std::abs(Ha * Rxy);
    length3 = std::abs(Wb * Rzz);
    length4 = std::abs(Db * Rzx);

    sum = (length1 + length2 + length3 + length4);

    bool case14 = length > sum;

    if (case14) return NoIntersection;

    // case 15
    //  |T * (Az x Bz) | > |WaRyz| + |HaRxz| + |WbRzy| + |HbRzx|
    //  length > Wa + length1 + length2 + length3 + length4

    length = abs(GACubeMathRepresentation::DotProduct(T, GACubeMathRepresentation::CrossProduct(Az, Bz)));

    length1 = std::abs(Wa * Ryz);
    length2 = std::abs(Ha * Rxz);
    length3 = std::abs(Wb * Rzy);
    length4 = std::abs(Hb * Rzx);

    sum = (length1 + length2 + length3 + length4);

    bool case15 = length > sum;

    if(case15) return NoIntersection;

    return Intersection;
}

std::vector<std::tuple<GARectangle *, GARectangle *, CDIntersectionResult> > GACollisionDetector::CollisionDetection2D(const std::vector<GARectangle *> &objects)
{
    //Создаю список, который будет хранить информацию о коллизях
    std::vector<std::tuple<GARectangle*,GARectangle*,CDIntersectionResult>> collisions;

    //Если на сцене один объект, то проверки не происходят
    if(objects.size() == 1)
    {
        collisions.push_back(std::tuple<GARectangle*,GARectangle*,CDIntersectionResult>(objects[0],nullptr,NoIntersection));
    }

    else
    {    //Каждый между объект проверяется на коллизии с другим единожды
        for (size_t i = 0; i < objects.size(); ++i)
        {
            for (size_t j = i + 1; j < objects.size(); ++j)
            {
                GARectangle* c1 = objects[i];
                GARectangle* c2 = objects[j];

                //Информация после каждой проверки добавляется в список
                collisions.push_back(std::tuple<GARectangle*,GARectangle*,CDIntersectionResult>(c1,c2,CalculateCollision2D(*c1,*c2)));
            }
        }
    }

    return collisions;
}

CDIntersectionResult GACollisionDetector::CalculateCollision2D(const GARectangle &rectangle1, const GARectangle &rectangle2)
{
    GARectangleMathRepresentation Rec1MathRepresentation = rectangle1.GetMathRepresentation();
    GARectangleMathRepresentation Rec2MathRepresentation = rectangle2.GetMathRepresentation();

    //Получаю координаты центра у параллелепипедов
    Point Pa = Rec1MathRepresentation.Center();
    Point Pb = Rec2MathRepresentation.Center();

    //Получаю половины ширины, высоты и длины
    double Ha = Rec1MathRepresentation.Height() / 2;
    double Wa = Rec1MathRepresentation.Width() / 2;
    double Hb = Rec2MathRepresentation.Height() / 2;
    double Wb = Rec2MathRepresentation.Width() / 2;

    qDebug() << Ha << Wa << Hb << Wb;

    //Получаю матрицы поворота параллелепипедов
    std::vector<std::vector<double>> rotationVectorsA = Rec1MathRepresentation.CalculateRotationVectors();
    std::vector<std::vector<double>> rotationVectorsB = Rec2MathRepresentation.CalculateRotationVectors();

    //Получаю единичные векторы осей
    std::vector<double> Ax = { rotationVectorsA[0][0], rotationVectorsA[0][1] };
    std::vector<double> Ay = { rotationVectorsA[1][0], rotationVectorsA[1][1] };

    std::vector<double> Bx = { rotationVectorsB[0][0], rotationVectorsB[0][1] };
    std::vector<double> By = { rotationVectorsB[1][0], rotationVectorsB[1][1] };

    //Вычисляю вектор разности центров
    std::vector<double> T = {abs(Pb[0] - Pa[0]), abs(Pb[1] - Pa[1])};

    double length;
    double length1;
    double length2;
    double sum;
    double Rxx = GARectangleMathRepresentation::DotProduct(Ax, Bx);
    double Rxy = GARectangleMathRepresentation::DotProduct(Ax, By);
    double Ryx = GARectangleMathRepresentation::DotProduct(Ay, Bx);
    double Ryy = GARectangleMathRepresentation::DotProduct(Ay, By);

    // case 1
    //  L = Ax
    //  | T • Ax | > Wa + | Wb * Rxx | + |Hb * Ryx|
    // length > Wa + length1 + length 2

    length = std::abs(GARectangleMathRepresentation::DotProduct(T, Ax));

    length1 = std::abs(Wb * Rxx);

    length2 = std::abs(Hb * Ryx);

    sum = Wa + length1 + length2;

    bool case1 = length > sum;

    if (case1) return NoIntersection;

    qDebug() << "Кейс 1";

    // case 2 done
    //  L = Ay
    //  | T • Ay | > Ha + | Wb * Rxy | + |Hb * Ryy|
    // length > Ha + length1 + length2

    length = std::abs(GARectangleMathRepresentation::DotProduct(T, Ay));

    length1 = std::abs(Wb * Rxy);

    length2 = std::abs(Hb * Ryy);

    sum = Ha + length1 + length2;

    bool case2 = length > sum;

    if (case2) return NoIntersection;

    qDebug() << "Кейс 1";

    // case 3 done
    // L = Bx
    // |T • Bx| > Wb + |Wa*Rxx| + |Ha*Ryx|
    // length > Wb + length1 + length2

    length = std::abs(GARectangleMathRepresentation::DotProduct(T, Bx));

    length1 = std::abs(Wa * Rxx);

    length2 = std::abs(Ha * Ryx);

    sum = Wb + length1 + length2;

    bool case3 = length > sum;

    if (case3) return NoIntersection;

    qDebug() << "Кейс 3";

    // case 4 done
    // L = By
    //  |T • By| > Hb + |Wa*Rxy| + |Ha*Ryy|
    // length > Wb + length1 + length2

    length = std::abs(GARectangleMathRepresentation::DotProduct(T, By));

    length1 = std::abs(Wa * Rxy);

    length2 = std::abs(Ha * Ryy);

    sum = Wb + length1 + length2;

    bool case4 = length > sum;

    if (case4) return NoIntersection;

    qDebug() << "Кейс 1";

    return Intersection;
}
