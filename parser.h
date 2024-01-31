#ifndef PARSER_H
#define PARSER_H

#include "mathrepresentation.h"

#include <QString>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QDebug>

//Класс используется для обработки файлов, хранящих информацию о сцене
class Parser
{
public:
    Parser();

    std::vector<MathRepresentation> getInfo(const QString& path);
private:
    void parseObject(const std::string& line, MathRepresentation& object);
};

#endif // PARSER_H
