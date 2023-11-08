#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
    this->_type = cp._type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &wronganimal)
{
    this->_type = wronganimal._type;
    return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound" << std::endl;
}