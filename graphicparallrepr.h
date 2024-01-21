#ifndef GRAPHICPARALLREPR_H
#define GRAPHICPARALLREPR_H

#include "graphicrepr.h"
#include "mathparallrepr.h"
#include <Qt3DExtras>

//Данный класс отвечает за графическое представление параллелепипеда
//Отвечает за меш, за положение в пространстве
class GraphicParallRepr : public GraphicRepr
{
public:
    GraphicParallRepr(MathParallRepr*, Qt3DCore::QEntity*);
};

#endif // GRAPHICPARALLREPR_H
