#ifndef __GAPARSER_H
#define __GAPARSER_H

#include "gacubemathrepresentation.h"

using namespace GA;

namespace GA
{

//Класс используется для обработки файлов, хранящих информацию об объектах
class GAParser
{
public:

    GAParser() = default;

    ~GAParser() = default;

    //Конструктор копирования
    GAParser(const GAParser& parser) = delete;

    //Оператор присваивания с копированием
    GAParser& operator=(const GAParser& copy) = delete;

    //Оператор присваивания с премещением
    GAParser& operator=(GAParser&& moved) = delete;

    //Метод парсит файл, находящийся по принимаемому пути и возвращает список математических представлений, описанных в файле
    std::vector<GACubeMathRepresentation> getInfo(const GA::String& path);

private:

    //Метод необходимый для распарсивания отдельной строки в файле и создания математического представления на основе информации из строки
    GACubeMathRepresentation parseObject(const std::string& line);
};
}
#endif // __GAPARSER_H
