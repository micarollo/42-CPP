#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    this->_range = bureaucrat._range;
    return (*this);
}

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
        throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
    if (this->_range + 1 < 150)
        this->_range++;
    else
        throw GradeTooLowException();
}

const char *	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat exception: Grade too high");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat exception: Grade too low");
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << "name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
	return (o);
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldnt sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.execute(*this);
		std::cout << _name << " has executed form '"
			<< form.getName() << "'." << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << _name << " can't execute " << form.getName()
			<< " because: '" << e.what() << "'." << std::endl;
	}
}