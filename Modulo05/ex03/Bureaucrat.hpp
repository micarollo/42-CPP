#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int range);
        Bureaucrat(Bureaucrat const &cp);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &b);

        std::string getName(void) const;
        int getGrade(void) const;

        void increaseGrade(void);
        void decreaseGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const & form);

        class	GradeTooHighException : public std::exception
	    {
	        public:
		        virtual const char *	what() const throw();
	    };

	    class	GradeTooLowException : public std::exception
	    {
	        public:
		        virtual const char *	what() const throw();
	    };

    private:
        std::string const _name;
        int _range;
        Bureaucrat(void);
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif