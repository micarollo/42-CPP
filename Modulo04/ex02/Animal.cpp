#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = cp;
}

Animal &Animal::operator=(Animal const &animal)
{
    this->_type = animal.getType();
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->_type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}