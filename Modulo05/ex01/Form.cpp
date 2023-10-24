#include "Form.hpp"

Form::Form(std::string const name, const int gradeSig, const int gradeExec) : _name(name), _gradeToSign(gradeSig), _gradeToExec(gradeExec)
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