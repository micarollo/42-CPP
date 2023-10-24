#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
    public:
        Form(std::string const name, const int gradeSig, const int gradeExec);
        Form(Form const &cp);
        ~Form(void);

        Form &operator=(Form const &form);

        std::string const & getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExect(void) const;
        bool getIsSigned(void) const;

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
        bool _isSigned;
        const int _gradeToExec;
        const int _gradeToSign;
        Form(void);
};

#endif