#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter
{
public:
    static void convert(std::string s);

private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter & cp);
    ~ScalarConverter(void);
    ScalarConverter & operator=(ScalarConverter const & src);

    int _isInt;
    char _isChar;
    float _isFloat;
    double _isDouble;

    static bool isIntLiteral(const std::string input);

    static bool isFloatLiteral(const std::string input);

    static bool isDoubleLiteral(const std::string input);

    static bool isCharLiteral(const std::string input);
};

#endif