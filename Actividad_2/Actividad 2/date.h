#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <string.h>

class Date
{
private:
    std::string year;
    std::string month;
    std::string day;

    bool validationYear(const std::string &);
    bool validationMonth(const std::string &);
    bool validationDay(const std::string &);

public:

    Date(const std::string & = "0", const std::string & = "0" ,const std::string & = "0");

    void setYear(const std::string &);
    void setMonth(const std::string &);
    void setDay(const std::string &);

    std::string getYear();
    std::string getMonth();
    std::string getDay();

};

#endif // DATE_H_INCLUDED
