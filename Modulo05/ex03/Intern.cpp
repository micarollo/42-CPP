#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Default destructor called" << std::endl;
}

Intern::Intern(Intern const &cp)
{
    std::cout << "Constructor called" << std::endl;
    *this = cp;
}

Intern & Intern::operator=(Intern const & intern)
{
    (void)intern;
    return (*this); 
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    ShrubberyCreationForm	sh		= ShrubberyCreationForm(target);
	RobotomyRequestForm		rb		= RobotomyRequestForm(target);
	PresidentialPardonForm	pr	= PresidentialPardonForm(target);
    AForm*	forms[] = {&sh, &rb, &pr};

    for (int i = 0; i < 3; i++)
    {
        if (forms[i]->getName() == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return(forms[i]);
        }
    }
    return (NULL);
}