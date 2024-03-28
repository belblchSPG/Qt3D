#ifndef __CD_COLLISION_MANAGER_API_H__
#define __CD_COLLISION_MANAGER_API_H__

#include "cd.h"
#include "cd_detector.h"
#include "cd_contur.h"

//Тип, описывающий отношение между двумя контурами
using CDIntersectingRelation = std::tuple<CDIntersectionResult, CDContur*,  CDContur*>;

//Добвляю готовый контур в детектор
void AddGeom(CDDetector& detector, CDContur* c1);

//Добвляю контур в детектор в виде точек
void AddGeom(CDDetector& detector, std::vector<CDPoint> points);

//Прохожу все контуры в детекторе и возвращаю информацию об отношениях между контурами
std::vector<CDIntersectingRelation> CheckIntersections(const CDDetector& detector);

#endif // __CD_COLLISION_MANAGER_API_H__
