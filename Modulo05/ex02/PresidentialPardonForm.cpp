#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cp) : AForm(cp), _target(cp._target)
{
    std::cout << "Copy constructor called" << std::endl;
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