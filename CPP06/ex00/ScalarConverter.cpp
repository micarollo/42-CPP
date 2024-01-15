#include "ScalarConverter.hpp"
#include <iomanip>

std::string ScalarConverter::_lit;
int ScalarConverter::_int;
char ScalarConverter::_char;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_needF;
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
    _needF = src._needF;
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
    if (dot + 2 == lit.length() && (lit[lit.length() - 1] == '0'))
        _needF = true;
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
    if ((charF + 1 == lit.length()) && (lit[lit.length() - 2] == '0') && (lit[lit.length() - 3] == '.'))
        _needF = true;
    if ((charF + 1 == lit.length()) && (dot + 1 != charF))
        return true;
    return false;
}

void ScalarConverter::printChar(int n)
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

    // nuevo
    if (type == CHAR || type == INT || type == FLOAT || type == DOUBLE)
    {
        if (test > 31 && test < 127)
        {
            _char = test;
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else if (test > 127 || test < -128)
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (test > 2147483647 || test < -2147483648)
        {
            std::cout << "int: impossible" << std::endl;
            // std::cout << "float: " << res << ".0f" << std::endl;
            if (test > std::numeric_limits<float>::max())
                std::cout << "float: impossible" << std::endl;
            else
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
            if (test > std::numeric_limits<double>::max())
                std::cout << "double: impossible" << std::endl;
            else
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
            // std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
        }
        else
        {
            std::cout << "int: " << static_cast<int>(test) << std::endl;
            // std::cout << "float: " << _int << ".0f" << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
            // std::cout << "double: " << _int << ".0" << std::endl;
        }
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
    // nuevo

    //     switch (type)
    //     {
    //     case CHAR:
    //     {
    //         _int = static_cast<int>(lit[0]);
    //         std::cout << "char: '" << lit << "'" << std::endl;
    //         std::cout << "int: " << _int << std::endl;
    //         std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //         std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //         // std::cout << "float: " << _int << ".0f" << std::endl;
    //         // std::cout << "double: " << _int << ".0" << std::endl;
    //     }
    //     break;

    //     case INT:
    //     {
    //         // long double test = std::stold(lit);
    //         long int res = 0;
    //         bool neg = false;
    //         if (lit[0] == '-')
    //             neg = true;
    //         for (std::size_t i = 0; i < lit.length(); ++i)
    //         {
    //             if (lit[i] >= '0' && lit[i] <= '9')
    //             {
    //                 res = res * 10 + (lit[i] - '0');
    //             }
    //         }
    //         res = neg ? -res : res;
    //         _int = res;
    //         printChar(_int);
    //         if (res > 2147483647 || res < -2147483648)
    //         {
    //             std::cout << "int: impossible" << std::endl;
    //             // std::cout << "float: " << res << ".0f" << std::endl;
    //             if (test > std::numeric_limits<float>::max())
    //                 std::cout << "float: impossible" << std::endl;
    //             else
    //                 std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //             if (test > std::numeric_limits<double>::max())
    //                 std::cout << "double: impossible" << std::endl;
    //             else
    //                 std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //             // std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //         }
    //         else
    //         {
    //             std::cout << "int: " << _int << std::endl;
    //             // std::cout << "float: " << _int << ".0f" << std::endl;
    //             std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //             std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //             // std::cout << "double: " << _int << ".0" << std::endl;
    //         }
    //     }
    //     break;

    //     case FLOAT:
    //     {
    //         // long double test = std::stold(lit);
    //         _float = static_cast<float>(std::atof(lit.c_str()));
    //         // _int = static_cast<int>(_float);
    //         if (test > 2147483647 || test < -2147483648)
    //         {
    //             std::cout << "char: impossible" << std::endl;
    //             std::cout << "int: impossible" << std::endl;
    //             if (test > std::numeric_limits<float>::max())
    //                 std::cout << "float: impossible" << std::endl;
    //             else
    //                 std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //             if (test > std::numeric_limits<double>::max())
    //                 std::cout << "double: impossible" << std::endl;
    //             else
    //                 std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //         }
    //         else
    //         {
    //             _int = std::stoi(lit);
    //             printChar(_int);
    //             if (_needF == true)
    //             {
    //                 std::cout << "int: " << _int << std::endl;
    //                 std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //                 // std::cout << "float: " << _float << ".0f" << std::endl;
    //                 std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //                 // std::cout << "double: " << _float << ".0" << std::endl;
    //             }
    //             else
    //             {
    //                 std::cout << "int: " << _int << std::endl;
    //                 std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //                 // std::cout << "float: " << _float << "f" << std::endl;
    //                 std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //                 // std::cout << "double: " << _float << std::endl;
    //             }
    //         }
    //     }
    //     break;

    //     case DOUBLE:
    //     {
    //         // long double test = std::stold(lit);
    //         // _double = std::strtod(lit.c_str(), nullptr);
    //         // _int = static_cast<int>(_double);
    //         if (test > 2147483647 || test < -2147483648)
    //         {
    //             std::cout << "char: impossible" << std::endl;
    //             std::cout << "int: impossible" << std::endl;
    //             if (test > std::numeric_limits<float>::max())
    //                 std::cout << "float: impossible" << std::endl;
    //             else
    //                 std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //             if (test > std::numeric_limits<double>::max())
    //                 std::cout << "double: impossible" << std::endl;
    //             else
    //                 std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //         }
    //         else
    //         {
    //             _int = std::stoi(lit);
    //             printChar(_int);
    //             std::cout << "int: " << _int << std::endl;
    //             std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(test) << "f" << std::endl;
    //             std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(test) << std::endl;
    //             // if (_needF == true)
    //             // {
    //             //     std::cout << "int: " << _int << std::endl;
    //             //     std::cout << "float: " << _double << ".0f" << std::endl;
    //             //     std::cout << "double: " << _double << ".0" << std::endl;
    //             // }
    //             // else
    //             // {
    //             //     std::cout << "int: " << _int << std::endl;
    //             //     std::cout << "float: " << _double << "f" << std::endl;
    //             //     std::cout << "double: " << _double << std::endl;
    //             // }
    //         }
    //     }
    //     break;

    //     case PSEUDO:
    //     {
    //         _double = std::strtod(lit.c_str(), nullptr);
    //         _float = static_cast<float>(std::atof(lit.c_str()));
    //         std::cout << "char: impossible" << std::endl;
    //         std::cout << "int: impossible" << std::endl;
    //         std::cout << "float: " << _float << "f" << std::endl;
    //         std::cout << "double: " << _double << std::endl;
    //     }
    //     break;

    //     default:
    //         break;
    //     }
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