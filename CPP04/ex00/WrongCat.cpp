#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cp) : WrongAnimal(cp._type)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = cp;
}

WrongCat &WrongCat::operator=(WrongCat const &wrongcat)
{
    this->_type = wrongcat._type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sound" << std::endl;
}