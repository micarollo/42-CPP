#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int range) : _name(name), _range(range)
{
    std::cout << "Constructor called" << std::endl;
    if (this->_range > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->_range < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Default destructor called" << std::endl;
}

//operador


//getters
std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_range);
}

void Bureaucrat::increaseGrade(void)
{
    if (this->_range - 1 > 1)
        this->_range--;
    else
        std::cout << "Error" << std::endl; //corregir
}

void Bureaucrat::decreaseGrade(void)
{
    if (this->_range + 1 < 150)
        this->_range++;
    else
        std::cout << "Error" << std::endl; //corregir
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat exception: Grade too high");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception: Grade too low");
}