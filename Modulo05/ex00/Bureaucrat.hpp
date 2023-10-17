#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

    private:
        std::string const _name;
        int _range;
        Bureaucrat(void);
};

#endif