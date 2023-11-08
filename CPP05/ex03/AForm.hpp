#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const name, const int gradeSig, const int gradeExec);
        AForm(AForm const &cp);
        ~AForm(void);

        AForm &operator=(AForm const &form);

        std::string const & getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExect(void) const;
        bool getIsSigned(void) const;

        void beSigned(Bureaucrat &bure);
        virtual void execute( Bureaucrat const & executor ) const = 0;

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

        class	NotSignedException : public std::exception
        {
        public:
            virtual const char *	what() const throw();
        };

        class	FileException : public std::exception
        {
        public:
            virtual const char *	what() const throw();
        };

    private:
        std::string const _name;
        bool _isSigned;
        const int _gradeToExec;
        const int _gradeToSign;
        AForm(void);
};

std::ostream &	operator<<( std::ostream & o, AForm const & form );

#endif