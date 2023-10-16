#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string.h>
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const &cp);
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound(void) const;
};

#endif