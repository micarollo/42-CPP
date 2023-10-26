#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
    std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & cp) : AForm(cp), _target(cp._target)
{
    std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & shForm)
{
    (void)shForm;
    return (*this);
}

std::string const & ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeToExect())
        throw GradeTooLowException();
    std::ofstream file(_target + "_shrubbery");
    // if (!file.is_open())
	// 	throw FileException();
    file << "	                                               .    " << std::endl;
	file << "                                     .         ;       " << std::endl;
	file << "        .              .              ;%     ;;        " << std::endl;
	file << "          ,           ,                :;%  %;         " << std::endl;
	file << "           :         ;                   :;%;'     .,  " << std::endl;
	file << "  ,.        %;     %;            ;        %;'    ,;    " << std::endl;
	file << "    ;       ;%;  %%;        ,     %;    ;%;    ,%'     " << std::endl;
	file << "     %;       %;%;      ,  ;       %;  ;%;   ,%;'      " << std::endl;
	file << "      ;%;      %;        ;%;        % ;%;  ,%;'        " << std::endl;
	file << "       `%;.     ;%;     %;'         `;%%;.%;'          " << std::endl;
	file << "        `:;%.    ;%%. %@;        %; ;@%;%'             " << std::endl;
	file << "           `:%;.  :;bd%;          %;@%;'               " << std::endl;
	file << "             `@%:.  :;%.         ;@@%;'                " << std::endl;
	file << "               `@%.  `;@%.      ;@@%;                  " << std::endl;
	file << "                 `@%%. `@%%    ;@@%;                   " << std::endl;
	file << "                   ;@%. :@%%  %@@%;                    " << std::endl;
	file << "                     %@bd%%%bd%%:;                     " << std::endl;
	file << "                       #@%%%%%:;;                      " << std::endl;
	file << "                       %@@%%%::;                       " << std::endl;
	file << "                       %@@@%(o);  . '                  " << std::endl;
	file << "                       %@@@o%;:(.,'                    " << std::endl;
	file << "                   `.. %@@@o%::;                       " << std::endl;
	file << "                      `)@@@o%::;                       " << std::endl;
	file << "                       %@@(o)::;                       " << std::endl;
	file << "                      .%@@@@%::;                       " << std::endl;
	file << "                      ;%@@@@%::;.                      " << std::endl;
	file << "                     ;%@@@@%%:;;;.                     " << std::endl;
	file << "                 ...;%@@@@@%%:;;;;,..                  " << std::endl;
}