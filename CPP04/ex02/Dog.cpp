#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}

Dog::Dog(Dog const &cp) : AAnimal(cp._type)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain();
    *this = cp;
    return ;
}

Dog &Dog::operator=(Dog const &dog)
{
    this->_type = dog._type;
    *this->_brain = *dog._brain;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sound" << std::endl;
}

Brain & Dog::getBrain(void) const
{
    return (*this->_brain);
}