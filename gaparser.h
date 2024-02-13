#ifndef __GAPARSER_H
#define __GAPARSER_H

#include "gacubemathrepresentation.h"

using namespace GA;

namespace GA
{

//Класс используется для обработки файлов, хранящих информацию о сцене
class GAParser
{
public:
    GAParser() = default;

    std::vector<GACubeMathRepresentation> getInfo(const GA::String& path);
private:
    void parseObject(const std::string& line, GACubeMathRepresentation& object);
};
}
#endif // __GAPARSER_H
