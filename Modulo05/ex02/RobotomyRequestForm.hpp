#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm (RobotomyRequestForm const &cp);

        RobotomyRequestForm &operator=(RobotomyRequestForm const & robForm);

        std::string const & getTarget(void) const;

    private:
        const std::string _target;
        RobotomyRequestForm(void);
};

#endif