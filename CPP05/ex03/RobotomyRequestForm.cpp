#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("")
{
    // std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    // std::cout << "Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    // std::cout << "Default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cp) : AForm(cp), _target(cp._target)
{
    // std::cout << "Copy constructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & robForm)
{
    (void)robForm;
    return (*this);
}

std::string const & RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int i;

    if (this->getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeToExect())
        throw GradeTooLowException();
    std::cout << "Some drilling noises";
	i = rand() % 2;
	if (i)
		std::cout << _target << " was robotomized" << std::endl;
	else
		std::cout << _target << " was not robotomized" << std::endl;
}

AForm *		RobotomyRequestForm::getCopy( void )const
{
	AForm* copy = new RobotomyRequestForm(*this);
	return (copy);
}

std::ostream & operator<<(std::ostream &o, RobotomyRequestForm const &rb)
{
	o << "Name: " << rb.getName() << std::endl;
    o << "Its signed: " << rb.getIsSigned() << std::endl;
    o << "Grade require to sign: " << rb.getGradeToSign() << std::endl;
    o << "Grade require to execute: " << rb.getGradeToExect() << std::endl;
	return (o);
}