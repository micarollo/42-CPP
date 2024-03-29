#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string.h>
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &cp);
        ~Cat();
        Cat &operator=(const Cat &cat);
        virtual void makeSound(void) const;
};

#endif