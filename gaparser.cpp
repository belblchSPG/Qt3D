#include "gaparser.h"

std::vector<GACubeMathRepresentation> GAParser::getInfo(const GA::String &path)
{
    std::vector<GACubeMathRepresentation> vec;
    std::ifstream file(path.toStdString());
    std::string line;
    std::istringstream iss(line);
    while(std::getline(file, line))
    {
        GACubeMathRepresentation math;
        parseObject(line, math);
        vec.push_back(math);
    }
    return vec;
}

void GAParser::parseObject(const std::string& line, GACubeMathRepresentation& math)
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
