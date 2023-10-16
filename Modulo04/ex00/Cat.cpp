#include "Cat.hpp"

Cat::Cat(void)
{
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cp)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cp;
}

Cat &Cat::operator=(Cat const &cat)
{
    this->_type = cat._type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound" << std::endl;
}