#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm (ShrubberyCreationForm const &cp);

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const & shForm);

        std::string const & getTarget(void) const;

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
        ShrubberyCreationForm(void);
};

#endif