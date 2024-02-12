#include "parser.h"

std::vector<GA::GACubeMathRepresentation> GA::Parser::getInfo(const QString &path)
{
    std::vector<GA::GACubeMathRepresentation> vec;
    std::ifstream file(path.toStdString());
    std::string line;
    std::istringstream iss(line);
    while(std::getline(file, line))
    {
        GA::GACubeMathRepresentation math;
        parseObject(line, math);
        vec.push_back(math);
    }
    return vec;
}

void GA::Parser::parseObject(const std::string& line, GA::GACubeMathRepresentation& math)
{
    std::istringstream iss(line);
    float w,h,l,x,y,z, xr, yr,zr;
    iss >> w >> h >> l >> x >> y >> z >> xr >> yr >> zr;

    GA::Vector3D mathInfo[3];

    mathInfo[0] = GA::Size(w,h,l);
    mathInfo[1] = GA::Point(x,y,z);
    mathInfo[2] = GA::Rotation(xr,yr,zr);

    math = GACubeMathRepresentation(mathInfo);
}
