#ifndef PARSER_H
#define PARSER_H

#include "gacubemathrepresentation.h"


namespace GA
{

//Класс используется для обработки файлов, хранящих информацию о сцене
class Parser
{
public:
    Parser() = default;

    std::vector<GACubeMathRepresentation> getInfo(const QString& path);
private:
    void parseObject(const std::string& line, GACubeMathRepresentation& object);
};
}
#endif // PARSER_H
