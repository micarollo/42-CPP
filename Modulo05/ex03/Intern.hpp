#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern(void);
    ~Intern(void);
    Intern(Intern const &cp);

    Intern &operator=(Intern const & intern);

    AForm* makeForm(std::string name, std::string target);
};

#endif