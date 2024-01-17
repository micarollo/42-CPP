#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDO 5

class ScalarConverter
{
public:
    static void convert(std::string s);
    class NotValid : public std::exception
    {
    public:
        const char *	what() const throw();
    };

private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter & cp);
    ~ScalarConverter(void);
    ScalarConverter & operator=(ScalarConverter const & src);

    static std::string _lit;
    static int _int;
    static char _char;
    static float _float;
    static double _double;
    static bool _pseudo;

    static bool isChar(std::string lit);
    static bool isInt(std::string lit);
    static bool isDouble(std::string lit);
    static bool isFloat(std::string lit);
    static bool isPseudo(std::string lit);
    static void convertAndPrint(std::string lit, int type);
    static void printChar(double n);
};

#endif