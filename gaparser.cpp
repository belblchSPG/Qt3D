#include "gaparser.h"

std::vector<GACubeMathRepresentation> GAParser::getInfo(const GA::String &path)
{
    //Создаю список математических представлений
    std::vector<GACubeMathRepresentation> vec;

    //Получаю информацию из файла
    std::ifstream file(path.toStdString());
    std::string line;

    //Начинаю парсить каждую строку из файла и заполняю список математических представлений
    //Одна строка описывает один объект
    while(std::getline(file, line))
    {
        GACubeMathRepresentation math = parseObject(line);

        vec.push_back(math);
    }

    return vec;
}

GACubeMathRepresentation GAParser::parseObject(const std::string& line)
{
    //Получаю информацию из строки и ставлю ее на необходимые места
    std::istringstream iss(line);
    double w,h,l,x,y,z, xr, yr,zr;
    iss >> w >> h >> l >> x >> y >> z >> xr >> yr >> zr;

    GA::Vector3D mathInfo[3] =
    {
        GA::Size(w,h,l),
        GA::Point(x,y,z),
        GA::Rotation(xr,yr,zr)
    };

    return GACubeMathRepresentation(mathInfo);
}
