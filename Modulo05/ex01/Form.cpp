#include "Form.hpp"

Form::Form() : _name(""), _isSigned(0), _gradeToExec(0), _gradeToSign(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string const name, const int gradeSig, const int gradeExec) : _name(name), _gradeToSign(gradeSig), _gradeToExec(gradeExec), _isSigned(0)
{
    std::cout << "Form Constructor called" << std::endl;
    if (gradeSig < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSig > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
	return ;
}

Form::~Form(void)
{
    std::cout << "Destructor called" << std::endl;
}

Form::Form(Form const &cp) : _name(cp._name), _gradeToExec(cp._gradeToExec), _gradeToSign(cp._gradeToSign)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form & Form::operator=(Form const &form)
{
    return (*this);
}

std::string const & Form::getName(void) const
{
    return (this->_name);
}

int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);    
}

int Form::getGradeToExect(void) const
{
    return (this->_gradeToExec);
}

bool Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

void Form::beSigned(Bureaucrat &bure)
{
    if (bure.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    else
        this->_isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Form const &form)
{
    o << "Name: " << form.getName() << std::endl;
    o << "Its signed: " << form.getIsSigned() << std::endl;
    o << "Grade require to sign: " << form.getGradeToSign() << std::endl;
    o << "Grade require to execute: " << form.getGradeToExect() << std::endl;
}