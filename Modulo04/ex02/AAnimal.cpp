#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cp)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = cp;
}

AAnimal &AAnimal::operator=(AAnimal const &animal)
{
    this->_type = animal.getType();
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal sound" << std::endl;
}