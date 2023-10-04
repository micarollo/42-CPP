#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
    this->type = cp.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &animal)
{
    this->type = animal.type;
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}