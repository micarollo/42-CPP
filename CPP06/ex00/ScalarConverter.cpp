#include "ScalarConverter.hpp"

// int ScalarConverter::_isInt;
// char ScalarConverter::_isChar;
// float ScalarConverter::_isFloat;
// double ScalarConverter::_isDouble;
// std::string ScalarConverter::_lit;
// bool ScalarConverter::_flag;
// bool ScalarConverter::_pseudo;

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

// ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
// {
//     (void)src;
//     _isChar = src._isChar;
//     _isInt = src._isInt;
//     _isDouble = src._isDouble;
//     _isFloat = src._isFloat;
//     _flag = src._flag;
//     return (*this);
// }

// static bool isIntLiteral(const std::string lit)
// {
//     std::istringstream stream(lit);
//     int intValue;
//     return (stream >> intValue) && stream.eof();
// }

// static bool isFloatLiteral(const std::string lit)
// {
//     std::istringstream stream(lit);
//     float floatValue;
//     size_t fPos = lit.find("f");
//     size_t dotPos = lit.find('.');
//     if (fPos == (lit.length() - 1) && dotPos)
//         return true;
//     return (stream >> floatValue) && stream.eof();
// }

// static bool isDoubleLiteral(const std::string lit)
// {
//     std::istringstream stream(lit);
//     double doubleValue;
//     return (stream >> doubleValue) && stream.eof();
// }

// static bool isCharLiteral(const std::string lit)
// {
//     if (lit.size() == 3 && lit[0] == '\'' && lit[2] == '\'')
//         return true;
//     else if (lit.size() == 1 && std::isprint(lit[0]))
//         return true;
//     return false;
// }

// static bool isPrintable(int i)
// {
//     if (i >= 32 && i <= 126)
//         return true;
//     return false;
// }

// void ScalarConverter::print(int i)
// {
//     size_t dotPos = _lit.find('.');
//     if (_pseudo)
//     {
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: " << _isFloat << "f" << std::endl;
//         std::cout << "double: " << static_cast<double>(_isFloat) << std::endl;
//     }
//     else if (i == CHAR)
//     {
//         std::cout << "char: " << _isChar << std::endl;
//         std::cout << "int: " << static_cast<int>(_isChar) << std::endl;
//         std::cout << "float: " << static_cast<float>(_isChar) << ".f" << std::endl;
//         std::cout << "double: " << static_cast<double>(_isChar) << ".0" << std::endl;
//     }
//     else if (i == INT)
//     {
//         if (isPrintable(_isInt))
//             std::cout << "char: '" << static_cast<char>(_isInt) << "'" << std::endl;
//         else
//             std::cout << "char: "
//                       << "Non displayable" << std::endl;
//         std::cout << "int: " << _isInt << std::endl;
//         std::cout << "float: " << static_cast<float>(_isInt) << ".f" << std::endl;
//         std::cout << "double: " << static_cast<double>(_isInt) << ".0" << std::endl;
//     }
//     else if (i == FLOAT)
//     {
//         if (isPrintable(static_cast<int>(_isFloat)))
//             std::cout << "char: '" << static_cast<char>(_isFloat) << "'" << std::endl;
//         else
//             std::cout << "char: "
//                       << "Non displayable" << std::endl;
//         std::cout << "int: " << static_cast<int>(_isFloat) << std::endl;
//         if (_flag)
//         {
//             std::cout << "float: " << _isFloat << ".0f" << std::endl;
//             std::cout << "double: " << static_cast<double>(_isFloat) << ".0" << std::endl;
//         }
//         else if (dotPos)
//         {
//             std::cout << "float: " << _isFloat << "f" << std::endl;
//             std::cout << "double: " << static_cast<double>(_isFloat) << std::endl;
//         }
//         else
//         {
//             std::cout << "float: " << _isFloat << ".f" << std::endl;
//             std::cout << "double: " << static_cast<double>(_isFloat) << ".0" << std::endl;
//         }
//     }
//     else if (i == DOUBLE)
//     {
//         if (isPrintable(static_cast<int>(_isDouble)))
//             std::cout << "char: '" << static_cast<char>(_isDouble) << "'" << std::endl;
//         else
//             std::cout << "char: "
//                       << "Non displayable" << std::endl;
//         std::cout << "int: " << static_cast<int>(_isDouble) << std::endl;
//         if (_flag)
//         {
//             std::cout << "float: " << static_cast<double>(_isDouble) << ".0f" << std::endl;
//             std::cout << "double: " << _isDouble << ".0" << std::endl;
//         }
//         else
//         {
//             std::cout << "float: " << static_cast<float>(_isDouble) << "f" << std::endl;
//             std::cout << "double: " << _isDouble << std::endl;
//         }
//     }
// }

// int ScalarConverter::findType(std::string s)
// {
//     if (s == "-inff" || s == "inff" || s == "nanf" || s == "+inff")
//     {
//         _pseudo = 1;
//         s = s.substr(0, (s.length() - 1));
//     }
//     if (isCharLiteral(s))
//     {
//         _isChar = static_cast<char>(s[0]);
//         return (CHAR);
//     }
//     else if (isIntLiteral(s))
//     {
//         _isInt = std::atoi(s.c_str());
//         return (INT);
//     }
//     else if (isDoubleLiteral(s))
//     {
//         size_t dotPos = _lit.find('.');
//         if ((_lit[dotPos + 1] == '0' && (dotPos + 1) == _lit.length() - 1))
//             _flag = 1;
//         _isDouble = std::atof(s.c_str());
//         return (DOUBLE);
//     }
//     else if (isFloatLiteral(s))
//     {
//         if (s == "inf" || s == "-inf" || s == "nan" || s == "+inf")
//             _pseudo = 1;
//         size_t dotPos = _lit.find('.');
//         if ((_lit[dotPos + 1] == '0' && _lit[dotPos + 2] == 'f' && (dotPos + 2) == _lit.length() - 1))
//             _flag = 1;
//         _isFloat = std::atof(s.c_str());
//         return (FLOAT);
//     }
//     else
//         throw NotValid();
//     return (0);
// }

// void ScalarConverter::convert(std::string s)
// {
//     _lit = s;
//     print(findType(s));
// }

const char *ScalarConverter::NotValid::what() const throw()
{
    return ("Not valid lit");
}

// 1.
// 2f
// -2f
// num cn un digito
// MAX MIN
// inf y demas
// char mas grande, cuando no cabe debe imp imposible, y en int tamb

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

void ScalarConverter::convertAndPrint(std::string lit, int type)
{
    switch (type)
    {
    case CHAR:
    {
        _int = static_cast<int>(lit[0]);
        std::cout << "char: '" << lit << "'" << std::endl;
        std::cout << "int: " << _int << std::endl;
        std::cout << "float: " << _int << ".0f" << std::endl;
        std::cout << "double: " << _int << ".0" << std::endl;
    }
    break;

    case INT:
    {
        int res = 0;
        for (std::size_t i = 0; i < lit.length(); ++i)
        {
            if (lit[i] >= '0' && lit[i] <= '9')
            {
                res = res * 10 + (lit[i] - '0');
            }
        }
        _int = res;
        if (res > 31 && res < 127)
        {
            _char = res;
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << _int << std::endl;
        std::cout << "float: " << _int << ".0f" << std::endl;
        std::cout << "double: " << _int << ".0" << std::endl;
    }
    break;

    case FLOAT:
    {
        _float = static_cast<float>(std::atof(lit.c_str()));
        _int = static_cast<int>(_float);
        if (_needF == true)
        {
            if (_int > 31 && _int < 127)
            {
                _char = _int;
                std::cout << "char: '" << _char << "'" << std::endl;
            }
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << _int << std::endl;
            std::cout << "float: " << _float << ".0f" << std::endl;
            std::cout << "double: " << _float << ".0" << std::endl;
        }
        else
        {
            if (_int > 31 && _int < 127)
            {
                _char = _int;
                std::cout << "char: '" << _char << "'" << std::endl;
            }
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << _int << std::endl;
            std::cout << "float: " << _float << "f" << std::endl;
            std::cout << "double: " << _float << std::endl;
        }
    }
    break;

    case DOUBLE:
    {
        _double = std::strtod(lit.c_str(), nullptr);
        _int = static_cast<int>(_double);
        if (_needF == true)
        {
            if (_int > 31 && _int < 127)
            {
                _char = _int;
                std::cout << "char: '" << _char << "'" << std::endl;
            }
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << _int << std::endl;
            std::cout << "float: " << _double << ".0f" << std::endl;
            std::cout << "double: " << _double << ".0" << std::endl;
        }
        else
        {
            if (_int > 31 && _int < 127)
            {
                _char = _int;
                std::cout << "char: '" << _char << "'" << std::endl;
            }
            else
                std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << _int << std::endl;
            std::cout << "float: " << _double << "f" << std::endl;
            std::cout << "double: " << _double << std::endl;
        }
    }
    break;

    case PSEUDO:
    {
        _double = std::strtod(lit.c_str(), nullptr);
        _float = static_cast<float>(std::atof(lit.c_str()));
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << _float << "f" << std::endl;
        std::cout << "double: " << _double << std::endl;
    }
    break;

    default:
        break;
    }
}

void ScalarConverter::convert(std::string s)
{
    _lit = s;
    int type = 0;

    if (isPseudo(_lit) == true)
    {
        type = PSEUDO;
        std::cout << "type pseudo" << std::endl;
    }
    else if (isChar(_lit) == true)
    {
        type = CHAR;
        std::cout << "type char" << std::endl;
    }
    else if (isInt(_lit) == true)
    {
        type = INT;
        std::cout << "type int" << std::endl;
    }
    else if (isDouble(_lit) == true)
    {
        type = DOUBLE;
        std::cout << "type double" << std::endl;
    }
    else if (isFloat(_lit) == true)
    {
        type = FLOAT;
        std::cout << "type float" << std::endl;
    }
    convertAndPrint(_lit, type);
}