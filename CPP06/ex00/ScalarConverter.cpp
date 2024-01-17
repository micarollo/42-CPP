#include "ScalarConverter.hpp"
#include <iomanip>

std::string ScalarConverter::_lit;
int ScalarConverter::_int;
char ScalarConverter::_char;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_pseudo;

ScalarConverter::ScalarConverter(void)
{
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cp)
{
    *this = cp;
    return;
}

ScalarConverter::~ScalarConverter(void)
{
    return;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    _char = src._char;
    _int = src._int;
    _double = src._double;
    _float = src._float;
    _pseudo = src._pseudo;
    return (*this);
}

const char *ScalarConverter::NotValid::what() const throw()
{
    return ("Not valid input");
}

bool ScalarConverter::isPseudo(std::string lit)
{
    if (lit == "-inf" || lit == "nan" || lit == "+inf")
        return true;
    if (lit == "-inff" || lit == "nanf" || lit == "+inff")
        return true;
    return false;
}

bool ScalarConverter::isChar(std::string lit)
{
    if (lit.length() == 1 && ((lit[0] > 31 && lit[0] < 48) || (lit[0] > 57 && lit[0] < 127)))
        return true;
    return false;
}

bool ScalarConverter::isInt(std::string lit)
{
    for (size_t i = 0; i < lit.length(); i++)
    {
        if (!isdigit(lit[i]) && lit[i] != '-')
        {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isDouble(std::string lit)
{
    size_t dot_count = 0;

    if (lit == "-inf" || lit == "nan" || lit == "+inf")
    {
        _pseudo = true;
        return true;
    }
    size_t dot = lit.find(".");
    if (dot == std::string::npos)
        return false;
    for (size_t i = 0; i < lit.length(); i++)
    {
        if (!isdigit(lit[i]) && lit[i] != '-' && lit[i] != '.')
        {
            return false;
        }
        if (lit[i] == '.')
        {
            if (lit[i + 1] == '\0')
                return false;
            dot_count++;
            if (dot_count > 1)
                return false;
        }
    }
    return true;
}

bool ScalarConverter::isFloat(std::string lit)
{
    if (lit == "-inff" || lit == "nanf" || lit == "+inff")
    {
        _pseudo = true;
        return true;
    }
    size_t dot_count = 0;
    size_t dot = lit.find(".");
    size_t charF = lit.find("f");
    if (dot == std::string::npos)
        return false;
    if (charF == std::string::npos)
        return false;
    for (size_t i = 0; i < lit.length(); i++)
    {
        if (!isdigit(lit[i]) && lit[i] != '-' && lit[i] != '.' && lit[i] != 'f')
        {
            return false;
        }
        if (lit[i] == '.')
        {
            if (lit[i + 1] == '\0')
                return false;
            dot_count++;
            if (dot_count > 1)
                return false;
        }
    }
    if ((charF + 1 == lit.length()) && (dot + 1 != charF))
        return true;
    return false;
}

void ScalarConverter::printChar(double n)
{
    if (n > 31 && n < 127)
    {
        _char = n;
        std::cout << "char: '" << _char << "'" << std::endl;
    }
    else if (n > 127 || n < -128)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convertAndPrint(std::string lit, int type)
{
    long double test = 0;
    if (lit.length() == 1 && !std::isdigit(lit[0]))
        test = static_cast<double>(lit[0]);
    else
        test = std::stold(lit);
    if (type == CHAR || type == INT || type == FLOAT || type == DOUBLE)
    {
        printChar(test);
        if (test > std::numeric_limits<int>::max() || test < std::numeric_limits<int>::lowest())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(test) << std::endl;
        if (test > std::numeric_limits<float>::max() || test < std::numeric_limits<float>::lowest())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
        if (test > std::numeric_limits<double>::max() || test < std::numeric_limits<double>::lowest())
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    }
    if (type == PSEUDO)
    {
        _double = std::strtod(lit.c_str(), nullptr);
        _float = static_cast<float>(std::atof(lit.c_str()));
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << _float << "f" << std::endl;
        std::cout << "double: " << _double << std::endl;
    }
}

void ScalarConverter::convert(std::string s)
{
    _lit = s;
    int type = 0;

    if (isPseudo(_lit) == true)
        type = PSEUDO;
    else if (isChar(_lit) == true)
        type = CHAR;
    else if (isInt(_lit) == true)
        type = INT;
    else if (isDouble(_lit) == true)
        type = DOUBLE;
    else if (isFloat(_lit) == true)
        type = FLOAT;
    else
    {
        throw NotValid();
        return;
    }
    convertAndPrint(_lit, type);
}