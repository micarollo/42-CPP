#include "ScalarConverter.hpp"

int ScalarConverter::_isInt;
char ScalarConverter::_isChar;
float ScalarConverter::_isFloat;
double ScalarConverter::_isDouble;
std::string ScalarConverter::_lit;
bool ScalarConverter::_flag;
bool ScalarConverter::_pseudo;

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter & cp)
{
    *this = cp;
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
    (void)src;
    _isChar = src._isChar;
    _isInt = src._isInt;
    _isDouble = src._isDouble;
    _isFloat = src._isFloat;
    _flag = src._flag;
    return (*this);
}

static bool isIntLiteral(const std::string input) 
{
    std::istringstream stream(input);
    int intValue;
    return (stream >> intValue) && stream.eof();
}

static bool isFloatLiteral(const std::string input) 
{
    std::istringstream stream(input);
    float floatValue;
    size_t fPos = input.find("f");
    size_t dotPos = input.find('.');
    if (fPos == (input.length() - 1) && dotPos)
    {
        stream >> floatValue && stream.eof();
        // std::cout << "Es un literal de float sin 'f': " << floatValue << std::endl;
        return true;
    }
    if (stream >> floatValue && stream.eof()) 
    {
        // std::cout << "Es un literal de float sin 'f': " << floatValue << std::endl;
        return true;
    }
    return false;
    // return (stream >> floatValue) && stream.eof();
}



static bool isDoubleLiteral(const std::string input) {
    std::istringstream stream(input);
    double doubleValue;
    return (stream >> doubleValue) && stream.eof();
}

static bool isCharLiteral(const std::string input) 
{
    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    else if (input.size() == 1 && std::isprint(input[0]))
        return true;
    return false;
}

static bool isPrintable(int i)
{
    if (i >= 32 && i <= 126)
        return true;
    return false;
}

void ScalarConverter::print(int i)
{
    size_t dotPos = _lit.find('.');
    if (_pseudo)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << _isFloat << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(_isFloat) << std::endl;
    }
    else if (i == CHAR)
    {
        std::cout << "char: " << _isChar << std::endl;
        std::cout << "int: " << static_cast<int>(_isChar) << std::endl;
        std::cout << "float: " << static_cast<float>(_isChar) << ".f" << std::endl;
        std::cout << "double: " << static_cast<double>(_isChar) << ".0" << std::endl;
    }
    else if (i == INT)
    {
        if (isPrintable(_isInt))
            std::cout << "char: '" << static_cast<char>(_isInt) << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << _isInt << std::endl;
        std::cout << "float: " << static_cast<float>(_isInt) << ".f" << std::endl;
        std::cout << "double: " << static_cast<double>(_isInt) << ".0" << std::endl;
    }
    else if (i == FLOAT) //42.02f 42.0f CAOSSSS
    {
        if (isPrintable(static_cast<int>(_isFloat)))
            std::cout << "char: '" << static_cast<char>(_isFloat) << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(_isFloat) << std::endl;
        if (_flag)
        {
            std::cout << "float: " << _isFloat << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(_isFloat) << ".0" << std::endl;
        }
        else if (dotPos)
        {
            std::cout << "float: " << _isFloat << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(_isFloat) << std::endl;
        }
        else
        {
            std::cout << "float: " << _isFloat << ".f" << std::endl;
            std::cout << "double: " << static_cast<double>(_isFloat) << ".0" << std::endl;
        }
    }
    else if (i == DOUBLE)
    {
        if (isPrintable(static_cast<int>(_isDouble)))
            std::cout << "char: '" << static_cast<char>(_isDouble) << "'" << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(_isDouble) << std::endl;
        if (_flag)
        {
            std::cout << "float: " << static_cast<double>(_isDouble) << ".0f" << std::endl;
            std::cout << "double: " << _isDouble << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(_isDouble) << "f" << std::endl;
            std::cout << "double: " << _isDouble << std::endl;
        }
    }
    // else if (i == 5)
    //     std::cout << "pseudo lit" << std::endl;
}

int ScalarConverter::findType(std::string s)
{
    if (s == "-inff" || s == "inff" || s == "nanf" || s == "+inff")
    {
        _pseudo = 1;
        s = s.substr(0, (s.length() - 1));
        // return (PSEUDO);
    }
    if (isCharLiteral(s))
    {
        _isChar = static_cast<char>(s[0]);
        return (CHAR);
    }
    else if (isIntLiteral(s))
    {
        _isInt = std::atoi(s.c_str());
        return (INT);
    }
    else if (isDoubleLiteral(s))
    {
        size_t dotPos = _lit.find('.');
        if ((_lit[dotPos + 1] == '0' && (dotPos + 1) == _lit.length() - 1))
            _flag = 1;
        _isDouble = std::atof(s.c_str());
        return (DOUBLE);
    }
    else if (isFloatLiteral(s))
    {
        if (s == "inf" || s == "-inf" || s == "nan" || s == "+inf")
            _pseudo = 1;
        size_t dotPos = _lit.find('.');
        if ((_lit[dotPos + 1] == '0' && _lit[dotPos + 2] == 'f' && (dotPos + 2) == _lit.length() - 1))
        {
            std::cout << "entro en la flag" << std::endl;
            _flag = 1;
        }
        _isFloat = std::atof(s.c_str());
        return (FLOAT);
    }
    else
        std::cout << "imposible" << std::endl;
    return (0);
}

void ScalarConverter::convert(std::string s)
{
    // if (ScalarConverter::isCharLiteral(s))
    //     std::cout << "char" << std::endl;
    // else if (ScalarConverter::isIntLiteral(s))
    //     std::cout << "int" << std::endl;
    // else if (ScalarConverter::isDoubleLiteral(s))
    //     std::cout << "double" << std::endl;
    // else if (ScalarConverter::isFloatLiteral(s))
    //     std::cout << "float" << std::endl;
    // else
    //     std::cout << "imposible" << std::endl;
    // findType(s);
    // ScalarConverter inst;
    // inst._lit = s;
    _lit = s;
    print(findType(s));
}