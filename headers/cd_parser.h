#ifndef __GAPARSER_H__
#define __GAPARSER_H__

#include "../headers/cd_cubemathrepresentation.h"

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
    std::vector<GACubeMathRepresentation> GetInfo(const String& path);

private:

    //Метод необходимый для распарсивания отдельной строки в файле и создания математического представления на основе информации из строки
    GACubeMathRepresentation ParseObject(const std::string& line);
};
#endif // __GAPARSER_H__
