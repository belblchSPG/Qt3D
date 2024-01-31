#include "parser.h"

Parser::Parser() {}

std::vector<MathRepresentation> Parser::getInfo(const QString &path)
{
    std::vector<MathRepresentation> vec;
    std::ifstream file(path.toStdString());
    std::string line;
    std::istringstream iss(line);
    while(std::getline(file, line))
    {
        MathRepresentation math;
        parseObject(line, math);
        vec.push_back(math);
    }
    return vec;
}

void Parser::parseObject(const std::string& line, MathRepresentation& math)
{
    std::istringstream iss(line);
    float w,h,l,x,y,z, xr, yr,zr;
    iss >> w >> h >> l >> x >> y >> z >> xr >> yr >> zr;
    math = MathRepresentation(w,h,l,QVector3D(x,y,z),xr,yr,zr);
}
