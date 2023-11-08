#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm (PresidentialPardonForm const &cp);

        PresidentialPardonForm &operator=(PresidentialPardonForm const & presForm);

        std::string const & getTarget(void) const;

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
        PresidentialPardonForm(void);
};

#endif