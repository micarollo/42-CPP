#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _isInt(0), _isChar(0), _isFloat(0.0f), _isDouble(0.0)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter & cp) : _isInt(cp._isInt), _isChar(cp._isChar), _isFloat(cp._isFloat), _isDouble(cp._isDouble)
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
    return (*this);
}

bool ScalarConverter::isIntLiteral(const std::string input) 
{
    std::istringstream stream(input);
    int intValue;
    return (stream >> intValue) && stream.eof();
}

bool ScalarConverter::isFloatLiteral(const std::string input) {
    std::istringstream stream(input);
    float floatValue;
    return (stream >> floatValue) && stream.eof();
}

bool ScalarConverter::isDoubleLiteral(const std::string input) {
    std::istringstream stream(input);
    double doubleValue;
    return (stream >> doubleValue) && stream.eof();
}

bool ScalarConverter::isCharLiteral(const std::string input) 
{
    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;  // A char literal with single character between single quotes.
    else if (input.size() == 1 && std::isprint(input[0]))
        return true;
    return false;
}

void ScalarConverter::convert(std::string s)
{
    if (ScalarConverter::isCharLiteral(s))
        std::cout << "char" << std::endl;
    if (ScalarConverter::isDoubleLiteral(s))
        std::cout << "double" << std::endl;
    if (ScalarConverter::isFloatLiteral(s))
        std::cout << "float" << std::endl;
    if (ScalarConverter::isIntLiteral(s))
        std::cout << "int" << std::endl;
}
