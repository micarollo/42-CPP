#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("")
{
    // std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    // std::cout << "Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    // std::cout << "Default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cp) : AForm(cp), _target(cp._target)
{
    // std::cout << "Copy constructor called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & presForm)
{
    (void)presForm;
    return (*this);
}

std::string const & PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeToExect())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm *		PresidentialPardonForm::getCopy( void )const
{
	AForm* copy = new PresidentialPardonForm(*this);
	return (copy);
}

std::ostream & operator<<(std::ostream &o, PresidentialPardonForm const &pf)
{
	o << "Name: " << pf.getName() << std::endl;
    o << "Its signed: " << pf.getIsSigned() << std::endl;
    o << "Grade require to sign: " << pf.getGradeToSign() << std::endl;
    o << "Grade require to execute: " << pf.getGradeToExect() << std::endl;
	return (o);
}