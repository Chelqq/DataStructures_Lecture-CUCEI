#include "date.h"

bool Date::validationYear(const std::string &y)
{
    return (stoi(y)>=2010 && stoi(y)<=2021);
}

bool Date::validationMonth(const std::string &m)
{
    return (stoi(m)>=1 && stoi(m)<=12);
}

bool Date::validationDay(const std::string &d)
{
    return (stoi(d)>=1 && stoi(d)<=30);
}


Date::Date(const std::string &y , const std::string &m , const std::string &d)
{
    year = validationYear(y) ? y : "2020";
    month = validationMonth(m) ? m : "02";
    day = validationDay(d) ? d : "07";
}

void Date::setYear(const std::string &y)
{
    if (validationYear(y))
        year = y;
}

void Date::setMonth(const std::string &m)
{
    if (validationMonth(m))
        month = m;

}

void Date::setDay(const std::string &d)
{
    if(validationDay(d))
        day = d;

}

std::string Date::getYear()
{
    return year;
}

std::string Date::getMonth()
{
    return month;
}

std::string Date::getDay()
{
    return day;
}

