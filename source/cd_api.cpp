#include "../headers/cd_api.h"

void AddGeom(CDDetector& detector, CDContur* c1)
{
    detector.AddGeom(c1);
}

void AddGeom(CDDetector& detector, std::vector<CDPoint> points)
{
    detector.AddGeom(points);
}

std::vector<CDIntersectingRelation> CheckIntersections(const CDDetector& detector)
{
    std::vector<std::tuple<CDIntersectionResult, CDContur*, CDContur*>> result;

    std::vector<CDContur*> geometry = detector.GetGeometry();

    for (size_t i = 0; i < geometry.size(); ++i)
    {
        for (size_t j = i + 1; j < geometry.size(); ++j)
        {

            //Информация после каждой проверки добавляется в список
            result.push_back(std::tuple<CDIntersectionResult, CDContur*, CDContur*>(detector.ConturCollision(geometry[i],geometry[j]),geometry[i],geometry[j]));
        }
    }

    std::sort(result.begin(), result.end());

    return result;
}

CDContur CreateContur(std::vector<CDPoint> points)
{
    return CDContur(points);
}
