#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cp)
{
    this->type = cp.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cat)
{
    this->type = cat.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sound" << std::endl;
}