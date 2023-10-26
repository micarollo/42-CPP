#include "AForm.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeToExec(0), _gradeToSign(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string const name, const int gradeSig, const int gradeExec) : _name(name), _isSigned(false), _gradeToExec(gradeExec), _gradeToSign(gradeSig)
{
    std::cout << "AForm Constructor called" << std::endl;
    if (gradeSig < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSig > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::~AForm(void)
{
    std::cout << "Destructor called" << std::endl;
}

AForm::AForm(AForm const &cp) : _name(cp._name), _gradeToExec(cp._gradeToExec), _gradeToSign(cp._gradeToSign)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm & AForm::operator=(AForm const &form)
{
    (void)form;
    return (*this);
}

std::string const & AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);    
}

int AForm::getGradeToExect(void) const
{
    return (this->_gradeToExec);
}

bool AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

void AForm::beSigned(Bureaucrat &bure)
{
    if (bure.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    else
        this->_isSigned = true;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char * AForm::NotSignedException::what() const throw()
{
    return ("Form not signed");
}

const char * AForm::FileException::what() const throw()
{
    return ("Cant open file");
}

std::ostream &operator<<(std::ostream &o, AForm const &form)
{
    o << "Name: " << form.getName() << std::endl;
    o << "Its signed: " << form.getIsSigned() << std::endl;
    o << "Grade require to sign: " << form.getGradeToSign() << std::endl;
    o << "Grade require to execute: " << form.getGradeToExect() << std::endl;
    return (o);
}