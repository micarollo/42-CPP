#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
public:
    static void convert(std::string s);

private:
    ScalarConverter(void);
    ScalarConverter(ScalarConverter & const cp);
    ~ScalarConverter(void);
    ScalarConverter & operator=(ScalarConverter const & src);
};

#endif